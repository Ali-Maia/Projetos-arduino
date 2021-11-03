const int potenciometro=A0;
const int led=11;
int leitura=0;
int pwm=0;

void setup() {
  pinMode(potenciometro,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
 leitura=analogRead(potenciometro);
 pwm=map(leitura,0,1023,0,255);
 analogWrite(led,pwm);
}
