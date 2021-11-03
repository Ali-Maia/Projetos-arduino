//definindo os ledds
const int led_a=13;//leds amarelos
const int led_b=12;
const int led_c=11;
const int vermelho=2;
const int verde=3;

//definindo os botões
const int botao_1=9;
const int botao_2=8;
const int botao_3=7;

/*
int leit_b1;
int leit_b2;
int leit_b3;*/

//armazenamento do estado do botão
bool estado_b1=1;
bool estado_b2=1;
bool estado_b3=1;

//definindo a entrada e saida dos momentos 
int moment_e1=0;
int moment_e2=0;
int moment_e3=0;

//resultado do momento conforme o botão apertado
int momento_1=0;
int momento_2=0;
int momento_3=0;

void setup() {  
pinMode(led_a,OUTPUT);
pinMode(led_b,OUTPUT);
pinMode(led_c,OUTPUT);

pinMode(vermelho,OUTPUT);
pinMode(verde,OUTPUT);

pinMode(botao_1,INPUT_PULLUP);
pinMode(botao_2,INPUT_PULLUP);
pinMode(botao_3,INPUT_PULLUP);

Serial.begin(9600);
}

void loop() {
//armazenar o estado dos botões
 if(digitalRead(botao_1) == LOW) // Se o botão for pressionado
  {
    estado_b1= !estado_b1; // troca o estado do LED
    while(digitalRead(botao_1) == LOW);
    delay(100);       
  }

 if(digitalRead(botao_2) == LOW) // Se o botão for pressionado
  {
    estado_b2=!estado_b2; // troca o estado do LED
    while(digitalRead(botao_2) == LOW);
    delay(100);       
  }
 if(digitalRead(botao_3) == LOW) // Se o botão for pressionado
  {
    estado_b3=!estado_b3; // troca o estado do LED
    while(digitalRead(botao_3) == LOW);
    delay(100);       
  }

 /*Serial.println("Estados");
 Serial.println(estado_b1);
 Serial.println(estado_b2);
 Serial.println(estado_b3);
 Serial.println("");
 Serial.println("Momentos");
 Serial.println(momento_1);
 Serial.println(momento_2);
 Serial.println(momento_3);
 Serial.println("");
 delay(500);*/
 
 
 digitalWrite(vermelho,HIGH);
//chamada das funções
  if(moment_e1==0){
    momento1();
   }
  if(moment_e1==1 and moment_e2==0){ 
      momento2();
  }
   if(moment_e2==1 and moment_e3==0){
        momento3();
    }
 
 //Execução caso correta a sequência 
 if(momento_1==1 and momento_2==2 and momento_3==3){
  digitalWrite(led_a,HIGH);
  digitalWrite(led_b,HIGH);
  digitalWrite(led_c,HIGH);
  digitalWrite(verde,HIGH);
  digitalWrite(vermelho,LOW);
 }

//Execução caso sequência errada
if(momento_1>0 and momento_2>0 and momento_3>0){
  if(momento_1!=1 or momento_2!=2 or momento_3!=3){
  digitalWrite(led_a,LOW);
  digitalWrite(led_b,LOW);
  digitalWrite(led_c,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(vermelho,LOW);
  delay(500);
  digitalWrite(vermelho,HIGH);
  delay(500);
  digitalWrite(vermelho,LOW);
  delay(500);
  momento_1=0;
  momento_2=0;
  momento_3=0;
  moment_e1=0;
  moment_e2=0;
  moment_e3=0;
  }
}

}

//Função para definir a variavel momento_1
void momento1(){
 if(moment_e1==0){
  if(estado_b1==LOW){
    momento_1=1;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,LOW);
    digitalWrite(led_c,LOW);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b1=!estado_b1;
    moment_e1=1;
  }
  else if (estado_b2==LOW){
    momento_1=2;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,LOW);
    digitalWrite(led_c,LOW);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b2=!estado_b2;
    moment_e1=1;
  }
  else if(estado_b3==LOW){
    momento_1=3;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,LOW);
    digitalWrite(led_c,LOW);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b3=!estado_b3;
    moment_e1=1;
  }
 }
}

//Função para definir a variavel momento_2
void momento2(){
 if(moment_e1==1){
  if(estado_b1==LOW){
    momento_2=1;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_c,LOW);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b1=!estado_b1;
    moment_e2=1;
  }
  else if (estado_b2==LOW){
    momento_2=2;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_c,LOW);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b2=!estado_b2;
    moment_e2=1;
  }
  else if(estado_b3==LOW){
    momento_2=3;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_c,LOW);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b3=!estado_b3;
    moment_e2=1;
  }
 } 
}

//Função para definir a variavel momento_3
void momento3(){
  if(moment_e2==1){
  if(estado_b1==LOW){
    momento_3=1;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_c,HIGH);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b1=!estado_b1;
    moment_e3=1;
  }
  else if (estado_b2==LOW){
    momento_3=2;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_c,HIGH);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b2=!estado_b2;
    moment_e3=1;
  }
  else if(estado_b3==LOW){
    momento_3=3;
    digitalWrite(led_a,HIGH);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_c,HIGH);
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    estado_b3=!estado_b3;
    moment_e3=1;
  }
 } 
}
