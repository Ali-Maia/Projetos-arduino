const int pino_buzzer=6;
const int led_r=2;
const int led_y=3;
const int led_g=4;
const int b_1=9;
const int b_2=10;
const int b_3=11;

const int c = 261; // Dó
const int d = 293; // Ré
const int e = 329; // Mi
const int f = 349; // Fá
const int g = 391; // Sol
const int a = 440; // Lá
const int b = 493; // Si

void setup() {
  pinMode(pino_buzzer,OUTPUT);
  pinMode(led_r,OUTPUT);
  pinMode(led_y,OUTPUT);
  pinMode(led_g,OUTPUT);
  pinMode(b_1,INPUT_PULLUP);
  pinMode(b_2,INPUT_PULLUP);
  pinMode(b_3,INPUT_PULLUP);
  
}

void loop() {
  bool estado_b1=digitalRead(b_1);
  bool estado_b2=digitalRead(b_2);
  bool estado_b3=digitalRead(b_3);

  if(estado_b1==LOW){
    tone(pino_buzzer,c);
    digitalWrite(led_r,HIGH);
    digitalWrite(led_y,LOW);
    digitalWrite(led_g,LOW);
  }

  else if(estado_b2==LOW){
    tone(pino_buzzer,d);
    digitalWrite(led_r,LOW);
    digitalWrite(led_y,HIGH);
    digitalWrite(led_g,LOW);
  }
  else if(estado_b3==LOW){
    tone(pino_buzzer,e);
    digitalWrite(led_r,LOW);
    digitalWrite(led_y,LOW);
    digitalWrite(led_g,HIGH);
  }
  
  else{
    noTone(pino_buzzer);
    digitalWrite(led_r,LOW);
    digitalWrite(led_y,LOW);
    digitalWrite(led_g,LOW);
  }
}
