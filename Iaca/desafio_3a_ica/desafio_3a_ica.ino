const int pin_red=11;
const int pin_green=10;
const int pin_blue=9;

void setup() {
  pinMode(pin_red,OUTPUT);
  pinMode(pin_green,OUTPUT);
  pinMode(pin_blue,OUTPUT);

}

void loop() {
  digitalWrite(pin_red,LOW);
  digitalWrite(pin_green,HIGH);
  digitalWrite(pin_blue,HIGH);

  delay(1000);

  digitalWrite(pin_red,HIGH);
  digitalWrite(pin_green,LOW);
  digitalWrite(pin_blue,HIGH);

  delay(1000);

  digitalWrite(pin_red,HIGH);
  digitalWrite(pin_green,HIGH);
  digitalWrite(pin_blue,LOW);
  delay(1000);

}
