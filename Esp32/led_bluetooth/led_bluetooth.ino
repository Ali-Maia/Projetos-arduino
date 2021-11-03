#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char valorRecebido;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("Dispositivo visível");
  
  pinMode(13,OUTPUT);
}

void loop() {
  
  valorRecebido=(char)SerialBT.read();

  if(Serial.available()){
    Serial.write(Serial.read());
  }

  if(SerialBT.available()){
    if(valorRecebido=='1'){
      SerialBT.println("Led 1 ligado");
      digitalWrite(13,HIGH);  
    }

    if(valorRecebido=='2'){
      SerialBT.println("Led 1 desligado");
      digitalWrite(13,LOW);
    }
  }

  delay(50);
  
}
