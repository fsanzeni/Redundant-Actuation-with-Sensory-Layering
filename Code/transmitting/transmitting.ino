//#include <LiquidCrystal_I2C.h>
//
////Transmitting Arduino
////Potentiometer connected to A0, +5V, GND- provides one test value
////Pin 12 Arduino One Connected to  Pin 13 Arduino Two
////Pin 13 Arduino One Connected to Pin 12 Arduino Two
////Arduino Grounds connected together
//
//#include <SoftwareSerial.h>   //We are using software serial so as not to conflict with serial download and monitor
//#include "Wire.h" // For I2C
//
//SoftwareSerial mySerial(12, 13); // RX, TX
//
//LiquidCrystal_I2C lcd(0x27,20,4);
//
//int testvalue = 200;
//
//void setup() {
//  // Set off LCD module
//  lcd.init();
//  lcd.backlight();
//
//  mySerial.begin(9600);
//}
//
//void loop()  {
//  int valueRead = analogRead(A0);
//  mySerial.print(valueRead);
//  mySerial.print( "  ");
//  mySerial.println(testvalue);
//
//  lcd.print(valueRead);
//  delay(200);
//  lcd.clear();
//}

#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop()
{
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
}
