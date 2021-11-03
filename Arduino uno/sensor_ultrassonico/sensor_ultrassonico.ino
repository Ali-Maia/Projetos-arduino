int const trig=3,echo=4,buzzer=7;
unsigned int intervalo,distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
/*int sensor_ult(int pinotrig,int pinoecho){
    digitalWrite(pinotrig,LOW);
    delayMicroseconds(2);
    digitalWrite(pinotrig,HIGH);
    delayMicroseconds(10);
    digitalWrite(pinotrig,LOW);
    return pulseIn(pinoecho,HIGH)/58;
    }*/
  distancia=sensor_ult(trig,echo);
  Serial.println(distancia);

  if(distancia<10){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    tone(buzzer,1750);
  }

  else if(distancia>60){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    noTone(buzzer);
  }

  else{
    if(distancia<=20){
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      intervalo=100;  
    }
    else if(distancia<=30){
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      intervalo=150;  
    }
 else if(distancia<=40){
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(11,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      intervalo=200;  
    }
 else if(distancia<=50){
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      intervalo=250;  
    }
  else if(distancia<=60){
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);
      intervalo=300;  
    }
  tone(buzzer,1750);
  delay(intervalo);
  noTone(buzzer);
  delay(intervalo);
  }
}

int sensor_ult(int pinotrig,int pinoecho){
    digitalWrite(pinotrig,LOW);
    delayMicroseconds(2);
    digitalWrite(pinotrig,HIGH);
    delayMicroseconds(10);
    digitalWrite(pinotrig,LOW);
    return pulseIn(pinoecho,HIGH)/58;
    }
