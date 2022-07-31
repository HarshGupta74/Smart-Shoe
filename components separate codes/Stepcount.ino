#include<Wire.h>
#include<LiquidCrystal.h>

int x=0;
int input= A0;
int state=0;


void setup(){
  Serial.begin(9600);
  Serial.println("Number of steps: ");
 
}
void loop(){
  int counter = digitalRead(A0);
 
   if(state==0){
    switch(counter){
      case 1 : state=1 ; x=x+1 ; Serial.print(2*x); break;
      case 0 : state=0; break;
     
    }
   }
if (counter == LOW){
  state=0;
}
}
