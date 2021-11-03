#include<Servo.h>
Servo serv_base;
Servo serv_eixo1;
Servo serv_eixo2;
Servo serv_garra;

int const Vrx_a=A5;
int const Vry_a=A4;
int const Vrx_b=A3;
int const Vry_b=A2;

int mov_sb;
int mov_se1;
int mov_se2;
int mov_sg;

int leit_xa;
int leit_ya;
int leit_xb;
int leit_yb;

void setup() {
  Serial.begin(9600);
  
  serv_base.attach(10);
  serv_eixo1.attach(11);
  serv_eixo2.attach(6);
  serv_garra.attach(9);

  pinMode(Vrx_a,INPUT);
  pinMode(Vry_a,INPUT);
  pinMode(Vrx_b,INPUT);
  pinMode(Vry_b,INPUT);
  

}

void loop() {
  
  leit_xa=map(analogRead(Vrx_a),0,1023,10,170);//base
  leit_ya=map(analogRead(Vry_a),0,1023,125,175 );//eixo1
  leit_xb=map(analogRead(Vrx_b),0,1023,130 ,10);//garra
  leit_yb=map(analogRead(Vry_b),0,1023,114,160);//eixo2

  mov_sb=leit_xa;
  mov_sg=leit_xb;
  mov_se1=leit_ya;
  mov_se2=leit_yb;
  
 serv_base.write(leit_xa);
  serv_garra.write(leit_xb);
  serv_eixo1.write(leit_ya);
  serv_eixo2.write(leit_yb);

 /* if(leit_xa >=530){
    serv_base.write(mov_sb + 5);
  }
  else if(leit_xa<=495){
    serv_base.write(mov_sb - 5);
  }

   if(leit_xb >=530){
    serv_base.write(mov_sg + 5);
  }
  else if(leit_xb<=495){
    serv_base.write(mov_sg - 5);
  }
   if(leit_ya >=530){
    serv_base.write(mov_se1 + 5);
  }
  else if(leit_ya<=495){
    serv_base.write(mov_se1 - 5);
  }
   if(leit_yb >=530){
    serv_base.write(mov_se2 + 5);
  }
  else if(leit_yb<=495){
    serv_base.write(mov_se2 - 5);
  }
  */
  
  
  Serial.println("**********************************************");
  Serial.print("rxa:");
  Serial.print(analogRead(Vrx_a));
  Serial.print(" Angulo base:");
  Serial.println(leit_xa);

  Serial.print("rxb:");
  Serial.print(analogRead(Vrx_b));
  Serial.print(" Angulo garra:");
  Serial.println(leit_xb);

  Serial.print("rya:");
  Serial.print(analogRead(Vry_a));
  Serial.print(" Angulo eixo1:");
  Serial.println(leit_ya);

  Serial.print("ryb:");
  Serial.print(analogRead(Vry_b));
  Serial.print(" Angulo eixo2:");
  Serial.println(leit_yb);

  delay(1000);

  

}
