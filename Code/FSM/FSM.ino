#include <Servo.h>
#include <Ramp.h>
#include <Wire.h>

Servo ESC;                              //ESC object
ramp rampESC;                           //ramp object

const int pinESC = 10;                  //must be a PWM pin
const int enablePin = 12;               //HIGH = enable motors, LOW = idle
const int motorSelect = 13;             //HIGH = front motor, LOW = back motor
const int speedPinBM = A0;              //get analog value to determine back motor speed, should be a value between 0 and 180
byte triggerBM;                         //back motor: 1 = problem detected, 0 = no problem detected
byte triggerFM;                         //front motor: 1 = problem detected, 0 = no problem detected

const int relay1 = 2;
const int relay2 = 3;
const int relay3 = 4;
const int relay4 = 5;
const int relay5 = 6;
const int relay6 = 7;


int machineState = 0;                    //to keep track of the FSM

void setup() {
  pinMode(enablePin, INPUT);
  pinMode(motorSelect, INPUT);
  pinMode(speedPinBM, INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);  

  ESC.attach(pinESC, 1000, 2000);        // (pin, min pulse width, max pulse width in microseconds)

  Serial.begin(9600);

  Wire.begin(1);                         // Join I2C Bus as device #1
}

void loop() {
  // FSM logic
  switch (machineState) {
    //IDLE
    case 0:
      Serial.println("IDLE");

      //Select Back Motor
      if (idle_check(enablePin) == true && motorSelectCheck(motorSelect) == false) {
        machineState = 1;

        Serial.println("Activating Back Motor");
        delay(3000);
      }

      //Select Front Motor
      if (idle_check(enablePin) == true && motorSelectCheck(motorSelect) == true) {
        machineState = 4;

        Serial.println("Activating Front Motor");
        delay(3000);
      }
      break;

    //BMOTOR select and ramp up
    case 1:
      //SYNTAX: pinRelay1, pinRelay2, pinRelay3, rampTo, rampTime (in microseconds)
      //rampTo should be between 0 and 180
      if (select_rampUP_BMotor(relay1, relay2, relay3, 100, 2000) == true) {
        machineState = 2;

        Serial.println("transition to state 2");
        delay(3000);
      }
      break;

    //BMOTOR speed control
    case 2:
      if (SpeedCTRL(speedPinBM, triggerBM) == true) {
        machineState = 3;

        Serial.println("transition to state 3");
        delay(3000);
      }
      break;

    //BMOTOR HALT
    case 3:
      //SYNTAX: pinRelay1, pinRelay2, pinRelay3, rampTime (in microseconds)
      if (rampDown_BMotor(relay1, relay2, relay3, 100) == true) {
        machineState = 0;

        Serial.println("transition to IDLE");
        delay(3000);
      }
      break;

    //FMOTOR select and ramp up
    case 4:
      //SYNTAX: pinRelay1, pinRelay2, pinRelay3, rampTo, rampTime (in microseconds)
      //rampTo should be between 0 and 180
      if (select_rampUP_FMotor(relay4, relay5, relay6, 100, 2000) == true) {
        machineState = 5;

        Serial.println("transition to state 5");
        delay(3000);
      }
      break;

    //FMOTOR speed control
    case 5:
      if (SpeedCTRL(speedPinBM, triggerFM) == true) {
        machineState = 6;

        Serial.println("transition to state 3");
        delay(3000);
      }
      break;

    //FMOTOR HALT
    case 6:
      //SYNTAX: pinRelay1, pinRelay2, pinRelay3, rampTime (in microseconds)
      if (rampDown_FMotor(relay4, relay5, relay6, 100) == true) {
        machineState = 0;

        Serial.println("transition to IDLE");
        delay(3000);
      }
      break;
  }
}
