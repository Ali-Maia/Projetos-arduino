const int ldr=A0;
const int buzzer=6;
const int botao=8;

int leitura=0;
int estadob=0;
int valor=0;
void setup() {
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
}

void loop() {
  leitura=analogRead(ldr);
  estadob=digitalRead(botao);
  
  Serial.print("Leitura:");
  Serial.print(leitura);
  Serial.print("\t");
  Serial.print("quantidade:");
  Serial.print(valor);
  Serial.print("\t");
  
   Serial.print("Obstaculo:");
   if(leitura<=670){
    Serial.print("Sim");
    tone(buzzer,200);
    valor=valor+1;
   }
  else if(estadob==LOW){
    valor=0;
  }
  else{
    Serial.print("Não");
    noTone(buzzer);
  }
  Serial.println();
  delay(100);
}
