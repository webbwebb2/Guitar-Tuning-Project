#include <LiquidCrystal.h>
#include <_28BYJ48.h>
#include <util.h>
#include <type.h>
#include <_math.h>
#include <dstruct.h>

#define PIN_BTN_0 A1
#define PIN_BTN_1 A2
#define PIN_BTN_2 A3
#define PIN_BTN_3 A4
#define PIN_AUDIO A5
#define PIN_MUX_0 9
#define PIN_MUX_1 8
#define PIN_MUX_2 A0
#define PIN_MTR_1 10
#define PIN_MTR_2 11
#define PIN_MTR_3 12
#define PIN_MTR_4 13

#define MASK_0_DN B10000000
#define MASK_1_DN B01000000
#define MASK_2_DN B00100000
#define MASK_3_DN B00010000
#define MASK_0_UP B00001000
#define MASK_1_UP B00000100
#define MASK_2_UP B00000010
#define MASK_3_UP B00000001

#define STATE_NULL  0
#define STATE_INI   1  // ini
#define STATE_M_CC  2  // 'M'anual mode - 'C'hoose 'C'urrent string
#define STATE_M_CP  3  // 'M'anual mode - 'C'hosse 'P'revious string
#define STATE_M_CN  4  // 'M'anual mode - 'C'hosse 'N'ext string
#define STATE_M_TS  5  // 'M'anual mode - 'T'une 'S'top
#define STATE_M_TLB 6  // 'M'anual mode - 'T'une 'T'ightening 'B'egin
#define STATE_M_TTB 7  // 'M'anual mode - 'T'une 'L'oosening 'B'egin
#define STATE_M_TL  9  // 'M'anual mode - 'T'une 'L'oosening
#define STATE_M_TT  10  // 'M'anual mode - 'T'une 'T'ightening
#define STATE_FD_S  11  // 'Frq'uency 'D'etection mode - 'S'ampling
#define STATE_FD_C  12  // 'Frq'uency 'D'etection mode - 'C'alculation
#define STATE_A_CC  13 // 'A'uto mode - 'C'hoose 'C'urrent string
#define STATE_A_CP  14 // 'A'uto mode - 'C'hosse 'P'revious string
#define STATE_A_CN  15 // 'A'uto mode - 'C'hosse 'N'ext string

#define REFRESH_NA  0
#define REFRESH_L0  1
#define REFRESH_L1  2
#define REFRESH_LA  3

#define SAMPLE_LEN  1024
#define STEP_PER_R  2048
#define MT_STEPS    128
#define THRESHOLD   125
#define NOISE       5
#define AVG_RADIUS  10

_28BYJ48 motor(10, 11, 12, 13);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
byte pre_state = STATE_NULL;
byte state     = STATE_INI;
byte event_btn = 0x00;  // DnL DnR DnC x UpL UpR UpC x 
byte val_btn   = 0x00;  // PrL PrR PrC x CuL CuR CuC x

// musical
byte string   = 1;
char pitch[3] = "NA";
float s_frq   = 0.0;
float avg_frq = 0.0;
float frq     = 0.0;
byte data[SAMPLE_LEN];
TrotArray avg_buff(20);

// temp
int  i_temp  = 0;
byte b_temp  = 0;

long timer;
long elapsed;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  motor.setRPM(12);
  //ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
  //ADCSRA |=  (1 << ADPS2) | (1 << ADPS1);
  Serial.println("Ready to go...");
}

void loop() {
  // timer = millis();
//  if (!blocked) {
  // read button analog input
  i_temp = analogRead(PIN_BTN_0);
  i_temp < 10   ? val_btn &= B11110111 : 0x00;
  i_temp > 512 ? val_btn |= B00001000 : 0x00;
  i_temp = analogRead(PIN_BTN_1);
  i_temp < 10   ? val_btn &= B11111011 : 0x00;
  i_temp > 512 ? val_btn |= B00000100 : 0x00;
  i_temp = analogRead(PIN_BTN_2);
  i_temp < 10   ? val_btn &= B11111101 : 0x00;
  i_temp > 512 ? val_btn |= B00000010 : 0x00;
  i_temp = analogRead(PIN_BTN_3);
  i_temp < 10   ? val_btn &= B11111110 : 0x00;
  i_temp > 512 ? val_btn |= B00000001 : 0x00;
  
  // detect keyup, keydown event
  b_temp  = (val_btn << 4) ^ (val_btn & 0xF0);
  event_btn = b_temp ? b_temp - (val_btn & 0xF0) | (b_temp >> 4) - (val_btn & 0x0F) : 0x00;

  // update val_btn
  val_btn <<= 4;

  // control state machine
  switch (state) {
    case STATE_INI:
      if (event_btn & MASK_0_DN)         // MT mode
        state = STATE_M_CC;
      else if (event_btn & MASK_1_DN)    // FrqD mode
        state = STATE_FD_S;
      else if (event_btn & MASK_2_DN)    // AT mode
        state = STATE_A_CC;
      break;
      
    case STATE_M_CC:
    case STATE_M_CP:
    case STATE_M_CN:
      if (event_btn & MASK_3_DN)         // Reset
        state = STATE_INI;
      else if (event_btn & MASK_0_DN)    // Pre string
        state = STATE_M_CP;
      else if (event_btn & MASK_2_DN)    // Nxt string
        state = STATE_M_CN;
      else if (event_btn & MASK_1_DN)    // Ok
        state = STATE_M_TS;
      else                               // no user input or undefined input
        state = STATE_M_CC;    
      break;
      
    case STATE_M_TS:
      if (event_btn & MASK_3_DN)         // Reset
        state = STATE_INI;
      else if (event_btn & MASK_0_DN)    // Lo string
        state = STATE_M_TLB;
      else if (event_btn & MASK_2_DN)    // Ti string
        state = STATE_M_TTB;
      break;
      
    case STATE_M_TLB:
      state = STATE_M_TL;
      break;
    
    case STATE_M_TTB:
      state = STATE_M_TT;
      break;
      
    case STATE_M_TL:
      if (event_btn & MASK_3_DN)         // Reset
        state = STATE_INI;
      else if (event_btn & MASK_0_UP)    // stop Lo string
        state = STATE_M_TS;
      else
        state = STATE_M_TS;
      break;
    
    case STATE_M_TT:
      if (event_btn & MASK_3_DN)         // Reset
        state = STATE_INI;
      else if (event_btn & MASK_2_UP)    // stop Ti string
        state = STATE_M_TS;
      else
        state = STATE_M_TS;
      break;
      
    case STATE_FD_S:
      if (event_btn & MASK_3_DN)         // Reset
        state = STATE_INI;
      else
        state = STATE_FD_C;
      break;
      
    case STATE_FD_C:
      if (event_btn & MASK_3_DN)         // Reset
        state = STATE_INI;
      else
        state = STATE_FD_S;
      break;
      
    case STATE_A_CC:
    case STATE_A_CP:
    case STATE_A_CN:
      if (event_btn & MASK_3_DN)         // Reset
        state = STATE_INI;
      else if (event_btn & MASK_0_DN)    // Pre string
        state = STATE_A_CP;
      else if (event_btn & MASK_2_DN)    // Nxt string
        state = STATE_A_CN;
      else if (event_btn & MASK_1_DN)    // Ok
        state = STATE_A_CC;
      else                               // no user input or undefined input
        state = STATE_A_CC;
      break;
    
    default:
      break;
  }
  
  // tasks
  switch (state) {
    case STATE_M_CP:
    case STATE_A_CP:
      string = string == 1 ? 6 : string - 1;
      break;
    
    case STATE_A_CN:  
    case STATE_M_CN:
      string = string == 6 ? 1 : string + 1;
      break;
    
    case STATE_M_TS:
      motor.off();
      
      break;
      
    case STATE_M_TLB:
    case STATE_M_TTB:
      pinMode(PIN_MUX_2, OUTPUT);
      for (int i = 0; i < 10000; i++)
        select_motor();
      break;
    
    case STATE_M_TL:
      pinMode(PIN_MUX_2, OUTPUT);
      motor.rotate(MT_STEPS);
      break;
    
    case STATE_M_TT:
      pinMode(PIN_MUX_2, OUTPUT);
      motor.rotate(-MT_STEPS);
      break;
      
    case STATE_FD_S:
      timer = micros();
      for (int i = 0; i < SAMPLE_LEN; i++) {
        data[i] = analogRead(PIN_AUDIO) / 2;
      }
      s_frq = 1000000 / (float)(micros() - timer) * SAMPLE_LEN;
      break;
    
    case STATE_FD_C:
      byte peak_val = 0;
      byte val = 0;
      int pre_i = 0;
      int count = 0;
      float sum = 0;
      for (int i = 0; i < SAMPLE_LEN; i++) {
        val = data[i];
        peak_val = val > peak_val ? val : peak_val;
        if (val <= THRESHOLD - NOISE && peak_val > THRESHOLD + NOISE) {
          if (pre_i == 0) {
            pre_i = i;
            peak_val = 0;
            continue;
          }
          sum += s_frq / (i - pre_i);
          peak_val = 0;
          pre_i = i;
          count++;
        }
        frq = sum / count;
      }
      avg_buff.push_back(frq);
      avg_frq = get_avg();
      break;
  }

  // screen state and control
  if (pre_state != state)
    lcd.clear();
  pre_state = state;
    
  switch (state) {
    case STATE_INI:
      lcd.setCursor(2, 0);  lcd.print("EC601 TUNER!");
      lcd.setCursor(0, 1);  lcd.print("MT");
      lcd.setCursor(14, 1); lcd.print("AT");
      lcd.setCursor(6, 1);  lcd.print("FrqD");
      break;
      
    case STATE_M_CC:
    case STATE_M_CP:
    case STATE_M_CN:
    case STATE_A_CC:
    case STATE_A_CP:
    case STATE_A_CN:
      lcd.setCursor(5, 0);
      switch (string) {
        case 1:  lcd.print("1st E4"); break;
        case 2:  lcd.print("2nd B3"); break;
        case 3:  lcd.print("3rd G3"); break;
        case 4:  lcd.print("4th D3"); break;
        case 5:  lcd.print("5th A2"); break;
        case 6:  lcd.print("6th E2"); break;
        default: lcd.print("Error!"); break;
      }
      lcd.setCursor(0, 1);  lcd.print("Pre");
      lcd.setCursor(13, 1); lcd.print("Nxt");
      lcd.setCursor(7, 1);  lcd.print("Ok");
      break;
     
    case STATE_M_TS:
    case STATE_M_TL:
    case STATE_M_TT:
      lcd.setCursor(0, 0);
      switch (string) {
        case 1:  lcd.print("1st"); break;
        case 2:  lcd.print("2nd"); break;
        case 3:  lcd.print("3rd"); break;
        case 4:  lcd.print("4th"); break;
        case 5:  lcd.print("5th"); break;
        case 6:  lcd.print("6th"); break;
        default: lcd.print("Err"); break;
      }
      lcd.setCursor(4, 0);
      switch (state) {
        case STATE_M_TLB:
        case STATE_M_TL: lcd.print("Loosening..."); break;
        case STATE_M_TTB:
        case STATE_M_TT: lcd.print("Tightening.."); break;
      }
      lcd.setCursor(0, 1);  lcd.print("Lo");
      lcd.setCursor(14, 1); lcd.print("Ti");
      break;
      
    case STATE_FD_C:
    case STATE_FD_S:
      lcd.setCursor(0, 0);  lcd.print("Cur:");
      lcd.setCursor(5, 0);  lcd.print(frq);
      lcd.setCursor(11, 0); lcd.print("Hz");
      lcd.setCursor(0, 1);  lcd.print("Avg:");
      lcd.setCursor(5, 1);  lcd.print(avg_frq);
      lcd.setCursor(11, 1); lcd.print("Hz");
      break;
    
    case 100:  // frequency detection mode
      lcd.setCursor(0, 0);
      break;
    
    case 101:  // auto tuning mode
      lcd.setCursor(0, 0);
      break;
  }
  
    
  Serial.print(event_btn, BIN);
  Serial.print(" ");
  Serial.println(val_btn, BIN);
  delay(500);
}

float get_avg(void) {
  byte count = 0;
  byte max_count_in_radius = 0;
  byte max_idx = 0;
  float sum = 0;
  for (int i = 0; i < avg_buff.get_len(); i++) {
    for (int j = 0; j < avg_buff.get_len(); j++) {
      if (avg_buff[j] < avg_buff[i] + AVG_RADIUS && avg_buff[j] > avg_buff[i] - AVG_RADIUS) {
        count ++;
      }
    }
    if (max_count_in_radius < count) {
      max_idx = i;
      max_count_in_radius = count;
    }
    count = 0;
  }
  for (int i = 0; i < avg_buff.get_len(); i++)
    if (avg_buff[i] < avg_buff[max_idx] + AVG_RADIUS && avg_buff[i] > avg_buff[max_idx] - AVG_RADIUS)
      sum += avg_buff[i];
  return sum / max_count_in_radius;
}

void select_motor(void) {
  switch (string) {
    case 1:
      digitalWrite(PIN_MUX_0, HIGH);
      digitalWrite(PIN_MUX_1, LOW);
      digitalWrite(PIN_MUX_2, LOW);
      break;
      
    case 2:
      digitalWrite(PIN_MUX_0, LOW);
      digitalWrite(PIN_MUX_1, HIGH);
      digitalWrite(PIN_MUX_2, LOW);
      break;
      
    case 3:
      digitalWrite(PIN_MUX_0, HIGH);
      digitalWrite(PIN_MUX_1, HIGH);
      digitalWrite(PIN_MUX_2, LOW);
      break;
      
    case 4:
      digitalWrite(PIN_MUX_0, LOW);
      digitalWrite(PIN_MUX_1, LOW);
      digitalWrite(PIN_MUX_2, HIGH);
      break;
      
    case 5:
      digitalWrite(PIN_MUX_0, HIGH);
      digitalWrite(PIN_MUX_1, LOW);
      digitalWrite(PIN_MUX_2, HIGH);
      break;
      
    case 6:
      digitalWrite(PIN_MUX_0, LOW);
      digitalWrite(PIN_MUX_1, HIGH);
      digitalWrite(PIN_MUX_2, HIGH);
      break;
  }
}

