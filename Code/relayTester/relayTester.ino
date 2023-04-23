const int relay1 = 2;
const int relay2 = 3;
const int relay3 = 4;
const int relay4 = 5;
const int relay5 = 6;
const int relay6 = 7;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
}

void loop() {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
    digitalWrite(relay6, LOW);
  
    delay(4000);
  
    digitalWrite(relay6, HIGH);
    digitalWrite(relay5, HIGH);
    digitalWrite(relay4, HIGH);
    digitalWrite(relay3, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay1, LOW);
  
    delay(4000);
}
