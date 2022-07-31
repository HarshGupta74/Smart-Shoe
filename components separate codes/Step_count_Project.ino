#include <SoftwareSerial.h>

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

    pinMode(12,INPUT);
    pinMode(10,OUTPUT);

}
int count = 0;
int steps = 0;
float calories;

void loop() {
  // put your main code here, to run repeatedly:
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
