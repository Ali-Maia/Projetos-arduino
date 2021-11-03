const int ledr=11;
const int ledg=10;
const int ledb=9;
const int botaor=7;
const int botaog=6;
const int botaob=5;

int leiturabotaor;
int leiturabotaog;
int leiturabotaob;

void setup() {
  pinMode(ledr,OUTPUT);
  pinMode(ledg,OUTPUT);
  pinMode(ledb,OUTPUT);
  pinMode(botaor,INPUT_PULLUP);
  pinMode(botaog,INPUT_PULLUP);
  pinMode(botaob,INPUT_PULLUP);

}

void loop() {
  leiturabotaor=digitalRead(botaor);
  leiturabotaog=digitalRead(botaog);
  leiturabotaob=digitalRead(botaob);

  if(leiturabotaor==LOW){
    analogWrite(ledr,255);
  }
  else{
    analogWrite(ledr,0);
  }

  if(leiturabotaog==LOW){
    analogWrite(ledg,255);
  }
  else{
    analogWrite(ledg,0);
  }
  if(leiturabotaob==LOW){
    analogWrite(ledb,255);
  }
  else{
    analogWrite(ledb,0);
  }
  delay(100);

}
