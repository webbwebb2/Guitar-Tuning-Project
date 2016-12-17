#include <LiquidCrystal.h>

#define L_BTN 0
#define R_BTN 1
#define C_BTN 2
#define L_BTN_PIN A5
#define R_BTN_PIN A4
#define C_BTN_PIN A3

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = A5;
int switchState = 0;
int ctrl_state = 0;
int btn_state[3] = {0, 0, 0};
int btn_now[3] = {0, 0, 0};
int btn_pre[3] = {0, 0, 0};

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
}

void loop() {
  // read button input
  btn_now[L_BTN] = analogRead(L_BTN_PIN);
  btn_now[R_BTN] = analogRead(R_BTN_PIN);
  btn_now[C_BTN] = analogRead(C_BTN_PIN);
  
  for (int i = 0; i < 3; i++) {
    if (btn_now[L_BTN] < 10)
      btn_now[L_BTN] = 0;
    else if (btn_now[L_BTN] > 1000)
      btn_now[L_BTN] = 1;
  }
  
  switch (ctrl_state) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Man");
      lcd.setCursor(12, 0);
      lcd.print("Auto");
      
    default:
      break;
  }
}
