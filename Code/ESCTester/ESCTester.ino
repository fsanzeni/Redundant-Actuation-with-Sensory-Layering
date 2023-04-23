#include <Servo.h>
#include <Wire.h>

Servo ESC;     // create servo object to control the ESC
int potValue;  // value from the analog pin
const int escPin = 11;
const int relay1 = 2;
const int relay2 = 3;
const int relay3 = 4;
const int relay4 = 5;
const int relay5 = 6;
const int relay6 = 7;

void setup() {
  ESC.attach(escPin, 1000, 2000); // (pin, min pulse width, max pulse width in microseconds)
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  ESC.write(0);
  delay(7000);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay1, HIGH);
}
void loop() {
  delay(100);
}

void receiveEvent(int howMany)
{
  int s = Wire.read();    // receive byte as an integer
  ESC.write(s);
}
