#include <SoftwareSerial.h>

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}

void loop() {
  
  Serial.println("temp. sensor");
  long int x = analogRead(4);
  float temp = x/2.048;
  
  Serial.println(temp);
  delay(200);
  
  if(temp>50)
  {
    digitalWrite(8,1);
   
  }
  else
  {
    digitalWrite(8,0);
  }
  
}
