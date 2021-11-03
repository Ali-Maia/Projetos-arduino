const int led=11;
const int botao=9;

int estado_bot=0;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

 if((digitalRead(botao)==LOW)&&(estado_bot==0)){
  estado_bot=1;
  while(digitalRead(botao)==LOW){
    delay(100);
  }
 }
 if((digitalRead(botao)==LOW) && (estado_bot==1)){
  estado_bot=0;
  while(digitalRead(botao)==LOW){
    delay(100);
  }
 }
  switch(estado_bot){
    case 1:
    digitalWrite(led,HIGH);
    break;
    default:
    digitalWrite(led,LOW);
    break;
  }
}
