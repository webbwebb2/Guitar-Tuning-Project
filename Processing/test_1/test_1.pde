
import processing.serial.*;

Serial port;
long i = 0;
long sum = 0;
int data[] = new int[128];
boolean data_ready = false;
int count = 0;

void setup() {
  port = new Serial(this, Serial.list()[1], 9600);
  size(800, 600);
  background(255);
}

void draw() {
  stroke(0);
  if (data_ready) {
    background(255);
    int scaler = max(data) / 500;
    int x = 0;
    int y = 0;
    int px = 0;
    int py = 0;
    for (int i = 1; i < 128; i++) {
      x = 144 + i * 4;
      px = x - 4;
      y = 550 - int(data[i]) / scaler;
      py = 550 - int(data[i - 1]) / scaler;
      line(x, y, px, py);
    }
  }
}

void serialEvent(Serial p) {
  String val = p.readStringUntil('\n');
  if (val != null) {
    if (val.trim().equals("start")) {
      print("start");
      data_ready = false;
      count = 0;
    } else if (count < 127) {
      data[count] = int(val.trim());
      println(data[count]);
    } else {
      data_ready = true;
    }
    count++;
  }
}