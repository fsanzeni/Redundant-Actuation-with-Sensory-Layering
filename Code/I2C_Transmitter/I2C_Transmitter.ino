#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int bt1 = 6;
const int bt2 = 5;
const int bt3 = 3;
const int bt4 = 4;

byte bt1_state = HIGH;
byte bt1_reading;
byte bt1_prev = LOW;
byte bt2_state = HIGH;
byte bt2_reading;
byte bt2_prev = LOW;
byte bt3_state = HIGH;
byte bt3_reading;
byte bt3_prev = LOW;
byte bt4_state = HIGH;
byte bt4_reading;
byte bt4_prev = LOW;

long time = 0;
long debounce = 200;

const int pot = A0;

LiquidCrystal_I2C lcd(0x27,20,4);  

void setup() {
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);
  pinMode(bt4, INPUT_PULLUP);
  pinMode(pot, INPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  Wire.begin();                 //join i2c bus (address optional for master)
}

void loop() {
  bt1_reading = digitalRead(bt1);
  bt2_reading = digitalRead(bt2);
  bt3_reading = digitalRead(bt3);
  bt4_reading = digitalRead(bt4);

  if (bt1_reading == HIGH && bt1_prev == LOW && millis() - time > debounce) {
    if (bt1_state == HIGH)
      bt1_state = LOW;
    else
      bt1_state = HIGH;
    time = millis();
  }
  if (bt2_reading == HIGH && bt2_prev == LOW && millis() - time > debounce) {
    if (bt2_state == HIGH)
      bt2_state = LOW;
    else
      bt2_state = HIGH;
    time = millis();
  }
  if (bt3_reading == HIGH && bt3_prev == LOW && millis() - time > debounce) {
    if (bt3_state == HIGH)
      bt3_state = LOW;
    else
      bt3_state = HIGH;
    time = millis();
  }
  if (bt4_reading == HIGH && bt4_prev == LOW && millis() - time > debounce) {
    if (bt4_state == HIGH)
      bt4_state = LOW;
    else
      bt4_state = HIGH;
    time = millis();
  }

  bt1_prev = bt1_reading;
  bt2_prev = bt2_reading;
  bt3_prev = bt3_reading;
  bt4_prev = bt4_reading;

  int potValue = analogRead(pot);
  potValue = map(potValue, 0, 1023, 0, 180);
  int perc = map(potValue, 0, 180, 0, 100);
  lcd.setCursor(0,0);
  lcd.print("Speed Value: ");
  lcd.setCursor(0,1);
  lcd.print(perc);
  
  delay(100);
  lcd.clear();

  printToSerial(bt1_state, bt2_state, bt3_state, bt4_state, potValue);

  writeToDevice(4, potValue);
}
