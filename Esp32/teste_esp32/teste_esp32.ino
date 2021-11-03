int led = 13; 
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP32 Touch Interrupt Test");
}

void loop()
{
  int cap = touchRead(T5);    
  if (cap < 50)               
  {
    digitalWrite(led, 1);     
    Serial.println("LED ON");

  }
  else {
    Serial.println("LED OFF");
    digitalWrite(led, 0);     

  }
  Serial.println(cap);        
  delay(500);
}
