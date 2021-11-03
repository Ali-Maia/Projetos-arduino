#include "DHT.h"

const int pino_dht=9;
float temperatura;
float umidade;
DHT dht(pino_dht,DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  delay(2000);
  temperatura=dht.readTemperature();
  umidade=dht.readHumidity();

  if(isnan(umidade)or isnan(temperatura)){
    Serial.println("Falha na leitura do sensor DHT");
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
  }
}
