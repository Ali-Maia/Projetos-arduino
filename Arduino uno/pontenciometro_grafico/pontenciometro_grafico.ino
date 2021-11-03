const int pontenciometro=A0;
int leitura=0;
float tensao=0.0;

void setup() {
  Serial.begin(9600);
  pinMode(pontenciometro,INPUT);

}

void loop() {
  leitura=analogRead(pontenciometro);
  tensao=leitura*5.0/1024.0;
  Serial.println(tensao);
  delay(100);

}
