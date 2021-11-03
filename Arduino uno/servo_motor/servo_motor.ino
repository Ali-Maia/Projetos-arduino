#include<Servo.h>
Servo servo_motor;
void setup() {
  servo_motor.attach(13);
  servo_motor.write(10);

}

void loop() {
  // put your main code here, to run repeatedly:

}
