const int sensor_ldr=A0;
int leitura=0;
float tensao=0.0;
const int led=7;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_ldr,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  leitura=analogRead(sensor_ldr);
  Serial.print("Leitura:  ");
  Serial.print(leitura);
  Serial.print("\t");

  tensao = leitura * 5.0 / 1024.0;
  Serial.print("Tensao: ");
  Serial.print(tensao);
  Serial.print("V");
  Serial.println();
  

  if(leitura<300){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  delay(100);
}
