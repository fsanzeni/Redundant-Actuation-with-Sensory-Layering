bool idle_check(int trigPin) {
  bool val = digitalRead(trigPin);
  if (val == LOW) {
    return false;
  } if (val == HIGH) {
    return true;
  }
}

bool motorSelectCheck(int sel) {
  bool val = digitalRead(sel);
    if (val == LOW) {
    return false;
  } if (val == HIGH) {
    return true;
  }
}

bool select_rampUP_BMotor(int p1, int p2, int p3, int rampTo, int rampTime) {
  //Select appropriate side of the relay - BM is on the NC contact
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);

  //ramp up motor to specified amount
  bool f = false;
  if (f == true) {
    return true;
  } else {
    bool i = false;
    if (i == false) {
      //setup ramping to user specified parameters
      rampESC.go(rampTo, rampTime);
      i = true;

      while (i == true) {
        //write ramp values to motor
        ESC.write(rampESC.update());

        //check if ramping is finished
        if (rampESC.isFinished()) {
          Serial.print("finished ramping up at: ");
          Serial.println(rampESC.update());

          break;
        }
      }
      return true;
    }
  }
}

bool SpeedCTRL(int analogPin, int triggerPin) {
  // monitor the actuator for error messages
  // SYNTAX: 0 = no error, 1 = error
  byte isTriggered = Wire.read();

  int MotorSpeed = analogRead(analogPin);

  if (isTriggered == 0) {
    ESC.write(MotorSpeed);

    Serial.print("Current speed is: ");
    Serial.println(MotorSpeed);
    return false;
  }

  if (isTriggered == 1) {
    Serial.println("SWITCHING TO BACKUP MOTOR");
    return true;
  }
}

bool rampDown_BMotor(int p1, int p2, int p3, int rampTime) {
  //Select appropriate side of the relay - BM is on the NC contact
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);

  //ramp up motor to specified amount
  bool f = false;
  if (f == true) {
    return true;
  } else {
    bool i = false;
    if (i == false) {

      //setup ramping to user specified parameters
      rampESC.go(0, rampTime);
      i = true;

      while (i == true) {
        //write ramp values to motor
        ESC.write(rampESC.update());

        //check if ramping is finished
        if (rampESC.isFinished()) {
          Serial.print("finished ramping down at: ");
          Serial.println(rampESC.update());

          break;
        }
      }
      return true;
    }
  }
}

bool select_rampUP_FMotor(int p1, int p2, int p3, int rampTo, int rampTime) {
  //Select appropriate side of the relay - FM is on the NO contact
  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, HIGH);

  //ramp up motor to specified amount
  bool f = false;
  if (f == true) {
    return true;
  } else {
    bool i = false;
    if (i == false) {

      //setup ramping to user specified parameters
      rampESC.go(rampTo, rampTime);
      i = true;

      while (i == true) {
        //write ramp values to motor
        ESC.write(rampESC.update());

        //check if ramping is finished
        if (rampESC.isFinished()) {
          Serial.print("finished ramping up at: ");
          Serial.println(rampESC.update());

          break;
        }
      }
      return true;
    }
  }
}

bool rampDown_FMotor(int p1, int p2, int p3, int rampTime) {
  //Select appropriate side of the relay - FM is on the NO contact
  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, HIGH);

  //ramp up motor to specified amount
  bool f = false;
  if (f == true) {
    return true;
  } else {
    bool i = false;
    if (i == false) {

      //setup ramping to user specified parameters
      rampESC.go(0, rampTime);
      i = true;

      while (i == true) {
        //write ramp values to motor
        ESC.write(rampESC.update());

        //check if ramping is finished
        if (rampESC.isFinished()) {
          Serial.print("finished ramping down at: ");
          Serial.println(rampESC.update());

          break;
        }
      }
      return true;
    }
  }
}
