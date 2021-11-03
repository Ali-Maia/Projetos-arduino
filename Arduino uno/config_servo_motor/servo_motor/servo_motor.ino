#include<Servo.h>
Servo servo_motor;
void setup() {
  servo_motor.attach(9);
  servo_motor.write(170);

}

void loop() {
  // put your main code here, to run repeatedly:

}
