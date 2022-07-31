#include <SoftwareSerial.h>

const int trigPin = 2;
const int echoPin = 4;

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void setup() {
  Serial.begin(9600);
  // Ultrasonic sensor
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,INPUT);

  // Temp. sensor
  pinMode(8,OUTPUT);  

  //Step Count
  pinMode(12,INPUT);
  pinMode(10,OUTPUT);

}

int count = 0;
int steps = 0;
float calories = 0;

void loop() {
      long duration, inches, cm;
     
      pinMode(trigPin, OUTPUT);
      digitalWrite(trigPin, LOW);
     
      delayMicroseconds(2);
    
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
    
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);
    
      duration = pulseIn(echoPin, HIGH);
      inches = microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
    
      Serial.print(inches);
      Serial.print("in, ");
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();
      delay(100);
    
      if(inches <= 5)
      {
        for(int i = 1; i <= 5;i++)
        {
          digitalWrite(6,1);
          digitalWrite(7,1);
          delay(500);
          digitalWrite(6,0);
          digitalWrite(7,0);
          delay(500);
         
        }
       
      }
    
      // Temperatue sensor
   if ( Serial.available())
  {
    char ch = Serial.read();

     if (ch == 't')
     {
        Serial.println("temp. sensor");
        long int x = analogRead(4);
        float temp = x / 2.048;
        
        Serial.println(temp);
        delay(200);
      
        if (temp > 50)
        {
          digitalWrite(8,1);
        }
        else
        {
          digitalWrite(8,0);
        }
     }
    // Step Count
    
     if (ch == 's')
     {
        if (digitalRead(12) == 1)
        {
          while(digitalRead(12) == 1);
    
          count++;
          steps = count / 2;
          Serial.println("Steps = ");
          Serial.print(steps);
          calories = 0.063 * steps;
          Serial.println("Calories = ");
          Serial.print(calories);
        
        }
     }
  }
}
