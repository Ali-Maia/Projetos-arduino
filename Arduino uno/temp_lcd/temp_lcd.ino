#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int pino_dht=9;
float temperatura;
float umidade;
DHT dht(pino_dht,DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  lcd.init();
  lcd.backlight();

}

void loop() {
  //delay(2000);
  temperatura=dht.readTemperature();
  umidade=dht.readHumidity();

  if(isnan(umidade)or isnan(temperatura)){
    lcd.print("Falha na leitura do sensor DHT");
  }

  else{
    lcd.home();
    lcd.print("Temperatura:");//,char(temperatura)," *C ");
    lcd.print(temperatura);
    lcd.print("*C ");
    //delay(3000);

    //lcd.print("\t");

    lcd.setCursor(0,1);
    lcd.print("Umidade:");//,char(umidade),"%");
    lcd.print(umidade);
    lcd.print("%");
    delay(3000);
    lcd.clear();

    //Serial.println();
  }
}
