void printToSerial(int a, int b, int c, int d, int e) {
  Serial.print(a);
  Serial.print("\t");
  Serial.print(b);
  Serial.print("\t");
  Serial.print(c);
  Serial.print("\t");
  Serial.print(d);
  Serial.print("\t");
  Serial.println(e);
}

void printFlagToSerial (bool a, bool b, bool c, bool d) {
  Serial.print(a);
  Serial.print("\t");
  Serial.print(b);
  Serial.print("\t");
  Serial.print(c);
  Serial.print("\t");
  Serial.println(d);
}
