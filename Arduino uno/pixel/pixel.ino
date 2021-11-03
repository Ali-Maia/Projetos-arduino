const int ledr=11;
const int ledg=10;
const int ledb=9;
const int botaor=7;
const int botaog=6;
const int botaob=5;
const int botaoa=4;
const int potenciometro=A0;

int leiturabr;
int leiturabg;
int leiturabb;
int leituraba;
int leiturapotenc;
int pwmr=255;
int pwmg=255;
int pwmb=255;

void setup() {
  pinMode (ledr,OUTPUT);
  pinMode (ledg,OUTPUT);
  pinMode (ledb,OUTPUT);
  pinMode (botaor,INPUT_PULLUP);
  pinMode(botaog,INPUT_PULLUP);
  pinMode(botaob,INPUT_PULLUP);
  pinMode(botaoa,INPUT_PULLUP);
  pinMode(potenciometro,INPUT);

}

void loop() {
  leiturapotenc=analogRead(potenciometro);
  leiturabr=digitalRead(botaor);
  leiturabg=digitalRead(botaog);
  leiturabb=digitalRead(botaob);
  leituraba=digitalRead(botaoa);

  if(leiturabr==LOW){
    if(leituraba==LOW){
      pwmr=map(leiturapotenc,0,1023,0,255);
    }
    analogWrite(ledr,pwmr);
  }
  else{
    analogWrite(ledr,0);
  }
  
  if(leiturabg==LOW){
    if(leituraba==LOW){
      pwmg=map(leiturapotenc,0,1023,0,255);
    }
    analogWrite(ledg,pwmg);
  }
  else{
    analogWrite(ledg,0);
  }

  if(leiturabb==LOW){
    if(leituraba==LOW){
      pwmb=map(leiturapotenc,0,1023,0,255);
    }
    analogWrite(ledb,pwmb);
  }
  else{
    analogWrite(ledb,0);
  }

  delay(100);
}
