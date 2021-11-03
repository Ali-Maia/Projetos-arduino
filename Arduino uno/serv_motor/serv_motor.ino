#include<Servo.h>
const int pot=A5;
int leitura;
Servo servo_motor;
Servo servo_m2;
void setup() {
  pinMode(pot,INPUT);
  servo_motor.attach(9);
  servo_m2.attach(10);
  Serial.begin(9600);
}

void loop() {
  leitura=analogRead(pot);
  Serial.println(leitura);
  leitura=map(leitura,0,1023,10,170);
  servo_motor.write(leitura);
  servo_m2.write(leitura);
  delay(100);

}
