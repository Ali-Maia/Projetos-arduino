const int pino_a=12;
const int pino_b=9;
const int pino_c=10;
const int pino_d=11;
const int botao=2;

int estado_botao, resultado;

void setup() {
  Serial.begin(9600);
  pinMode(pino_a,OUTPUT);
  pinMode(pino_b,OUTPUT);
  pinMode(pino_c,OUTPUT);
  pinMode(pino_d,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
}

void loop() {
  estado_botao=digitalRead(botao);
  if(estado_botao==LOW){
    delay(150);
    resultado=random(1,9);
    Serial.println(resultado);
    switch(resultado){
      case 1:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,LOW);
      digitalWrite(pino_c,LOW);
      digitalWrite(pino_d,LOW);
     break;

      case 2:
      digitalWrite(pino_a,LOW);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,LOW);
      digitalWrite(pino_d,LOW);
     break;

     case 3:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,LOW);
      digitalWrite(pino_d,LOW);
     break;
    
      case 4:
      digitalWrite(pino_a,LOW);
      digitalWrite(pino_b,LOW);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,LOW);
     break;

      case 5:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,LOW);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,LOW);
     break;
    
      case 6:
      digitalWrite(pino_a,LOW);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,LOW);
     break;

      case 7:
      digitalWrite(pino_a,HIGH);
      digitalWrite(pino_b,HIGH);
      digitalWrite(pino_c,HIGH);
      digitalWrite(pino_d,LOW);
     break;
    
      case 8:
      digitalWrite(pino_a,LOW);
      digitalWrite(pino_b,LOW);
      digitalWrite(pino_c,LOW);
      digitalWrite(pino_d,HIGH);
     break;
    
    }
  }
  
}
