#include <Servo.h>

const int ECHO = 6;
const int TRIG = 7;

Servo servo_motor;

const int botao=12;
int leitura;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  servo_motor.attach(13);
  servo_motor.write(90);

  pinMode(botao,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  leitura=digitalRead(botao);
  //leitura=map(leitura,0,1023,90,140);
  //servo_motor.write();
  //Serial.println(leitura);
  //delay(100);
  
  int distancia=sensor_distancia(TRIG,ECHO);//leitura do sensor
  Serial.println(distancia);
  delay(100);

  if(leitura==LOW){ //Fazer a garra abrir com botão
    servo_motor.write(90);
  }
  else{
    if(distancia<=10){
      servo_motor.write(140);
    }
    
  }


}

int sensor_distancia(int pino_trig,int pino_echo){ //Configuração do sensor ultrassom.
    digitalWrite(pino_trig,LOW);
    delayMicroseconds(2);
    digitalWrite(pino_trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_trig,LOW);
    delayMicroseconds(2);

    return pulseIn(pino_echo,HIGH)/58;
    }
