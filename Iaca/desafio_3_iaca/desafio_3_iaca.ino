const int pin_pot=A0;

const int pin_red=11;
const int pin_green=10;
const int pin_blue=9;

int leitura_pot=0;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(pin_pot,INPUT);
  
  pinMode(pin_red,OUTPUT);
  pinMode(pin_green,OUTPUT);
  pinMode(pin_blue,OUTPUT);
  
}

void loop() {
leitura_pot=(analogRead(pin_pot));
Serial.println(leitura_pot);
delay(100);

if((leitura_pot >= 0)and(leitura_pot <340) ){
  digitalWrite(pin_red,LOW);
  digitalWrite(pin_green,HIGH);
  digitalWrite(pin_blue,HIGH);
}
else if((leitura_pot>=340) and (leitura_pot<680)){
  digitalWrite(pin_red,HIGH);
  digitalWrite(pin_green,LOW);
  digitalWrite(pin_blue,HIGH);
}
if(leitura_pot>=680){
  digitalWrite(pin_red,HIGH);
  digitalWrite(pin_green,HIGH);
  digitalWrite(pin_blue,LOW);
}


}
