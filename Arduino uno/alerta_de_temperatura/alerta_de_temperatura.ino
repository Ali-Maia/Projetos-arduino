#include "DHT.h"

const int pino_dht=9;
const int buzzer=10;
const int led_r=11;
const int led_g=12;
const int led_b=13;

float temperatura;
float umidade;
DHT dht(pino_dht,DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(buzzer,OUTPUT);
  pinMode(led_r,OUTPUT);
  pinMode(led_g,OUTPUT);
  pinMode(led_b,OUTPUT);
}

void loop() {
  delay(2000);
  temperatura=dht.readTemperature();
  umidade=dht.readHumidity();

  if(isnan(umidade)or isnan(temperatura)){
    Serial.println("Falha na leitura do sensor DHT");
    digitalWrite(led_r,HIGH);
    digitalWrite(led_g,HIGH);
    digitalWrite(led_b,HIGH);
  }

  else{
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C ");

    Serial.print("\t");

    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t");

    Serial.println();

    if(temperatura>35 or temperatura<15){
      digitalWrite(led_r,HIGH);
      digitalWrite(led_g,LOW);
      digitalWrite(led_b,LOW);
      tone(buzzer,2000);
      delay(1000);
    }

    else if(temperatura>30 or temperatura<20){
      digitalWrite(led_r,LOW);
      digitalWrite(led_g,LOW);
      digitalWrite(led_b,HIGH);
      tone(buzzer,1000);
      delay(500);
    }

    else{
      digitalWrite(led_r,LOW);
      digitalWrite(led_g,HIGH);
      digitalWrite(led_b,LOW);
    }

    noTone(buzzer);
  }
}
