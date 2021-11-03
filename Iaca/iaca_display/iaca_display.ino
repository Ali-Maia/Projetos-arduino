const int pin_a=12;
const int pin_b=11;
const int pin_c=7;
const int pin_d=6;
const int pin_e=5;
const int pin_f=10;
const int pin_g=9;

const int botao=2;

int contagem=0;

void setup() {
  pinMode(pin_a,OUTPUT);
  pinMode(pin_b,OUTPUT);
  pinMode(pin_c,OUTPUT);
  pinMode(pin_d,OUTPUT);
  pinMode(pin_e,OUTPUT);
  pinMode(pin_f,OUTPUT);
  pinMode(pin_g,OUTPUT);
  
  pinMode(botao,INPUT_PULLUP);

}

void loop() {
  
  if(digitalRead(botao)==LOW){
    contagem =contagem + 1;
    while(digitalRead(botao)==LOW){
      delay(100); 
    }
  }

  if(contagem==10){
    contagem=0;
  }
  
  switch(contagem){
    case 1:
    digitalWrite(pin_a,LOW);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,LOW);
    digitalWrite(pin_e,LOW);
    digitalWrite(pin_f,LOW);
    digitalWrite(pin_g,LOW);
    break;

    case 2:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,LOW);
    digitalWrite(pin_d,HIGH);
    digitalWrite(pin_e,HIGH);
    digitalWrite(pin_f,LOW);
    digitalWrite(pin_g,HIGH);
    break;

    case 3:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,HIGH);
    digitalWrite(pin_e,LOW);
    digitalWrite(pin_f,LOW);
    digitalWrite(pin_g,HIGH);
    break;

    case 4:
    digitalWrite(pin_a,LOW);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,LOW);
    digitalWrite(pin_e,LOW);
    digitalWrite(pin_f,HIGH);
    digitalWrite(pin_g,HIGH);
    break;

    case 5:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,LOW);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,HIGH);
    digitalWrite(pin_e,LOW);
    digitalWrite(pin_f,HIGH);
    digitalWrite(pin_g,HIGH);
    break;

    case 6:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,LOW);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,HIGH);
    digitalWrite(pin_e,HIGH);
    digitalWrite(pin_f,HIGH);
    digitalWrite(pin_g,HIGH);
    break;

    case 7:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,LOW);
    digitalWrite(pin_e,LOW);
    digitalWrite(pin_f,LOW);
    digitalWrite(pin_g,LOW);
    break;

    case 8:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,HIGH);
    digitalWrite(pin_e,HIGH);
    digitalWrite(pin_f,HIGH);
    digitalWrite(pin_g,HIGH);
    break;

    case 9:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,LOW);
    digitalWrite(pin_e,LOW);
    digitalWrite(pin_f,HIGH);
    digitalWrite(pin_g,HIGH);
    break;
    
    default:
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_c,HIGH);
    digitalWrite(pin_d,HIGH);
    digitalWrite(pin_e,HIGH);
    digitalWrite(pin_f,HIGH);
    digitalWrite(pin_g,LOW);
    break;
  }

}
