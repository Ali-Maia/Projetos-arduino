#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 13, 11, 10, 9, 8);// definição das portas do lcd

float sensor_temp=A0; //definiçao da porta do sensor de temperatura e suas variáveis
int temp=0;

int led_g=5; //definição das portas do leds e buzzer
int led_y=4;
int led_r=3;
int buzzer=7;

int sensor_gas=A1;//definição da porta do sensor de gas e suas variáveis 
int valor_gas=0;
int gas=0;

void setup()//configuração dos componentes e sensores
{
  lcd.begin(16, 2);
  pinMode(A0,INPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  valor_gas=analogRead(sensor_gas); //configuração das variáveis
  temp=analogRead(A0);
  float voltage = (temp * 5.0)/1024;
  float milliVolt = voltage * 1000;
  float tempCel = (milliVolt-500)/10;
  
  lcd.clear(); //configuração da exibição do lcd
  lcd.setCursor(0, 0);      
  lcd.print("Temperatura:");
  lcd.print(tempCel);
  lcd.setCursor(0, 1); 
  lcd.print("CO2:");
  lcd.print(valor_gas);
  
  delay(1000);

  //Nível seguro
   if(tempCel<=29 and valor_gas<400){
    digitalWrite(led_g,HIGH);
    digitalWrite(led_y,LOW);
    digitalWrite(led_r,LOW);
    noTone(buzzer); 
    } 
  
  //Nível alerta
  else if ((tempCel>29) and (tempCel<=39)){
      digitalWrite(led_g,LOW);
      digitalWrite(led_y,HIGH);
      digitalWrite(led_r,LOW);
      noTone(buzzer);
      }
  else if((valor_gas>=400) and (valor_gas<500)){
      digitalWrite(led_g,LOW);
      digitalWrite(led_y,HIGH);
      digitalWrite(led_r,LOW);
      noTone(buzzer);
      }
      
  //Nível incêndio
  else if(tempCel>=40){
     if(valor_gas>=500){
      digitalWrite(led_g,LOW);
      digitalWrite(led_y,LOW);
      digitalWrite(led_r,HIGH);
      tone(buzzer,262);
      delay(1000);
      noTone(buzzer);
      delay(1000);
      }
    }
                 
}
