void writeToDevice (byte deviceAddress, int motorSpeed) {
  Wire.beginTransmission(deviceAddress);  // transmit to device #9
  Wire.write(motorSpeed);                 // sends speed
  Wire.endTransmission();                 // stop transmitting
}

void updateScreen() {
  
}
