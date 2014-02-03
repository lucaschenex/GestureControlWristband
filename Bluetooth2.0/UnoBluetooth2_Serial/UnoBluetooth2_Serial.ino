#include <SoftwareSerial.h>

double x,y,z;
int num;

SoftwareSerial mySerial(6,7);

void setup(){
  
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 Serial.begin(9600);
 
}

void loop(){
  x=analogRead(A0);
  y=analogRead(A1);
  z=analogRead(A2);
//  x=(x-350)/60;
  
  
  //Serial.println("A");
  
  Serial.println(x,DEC);
  Serial.println(',');
  Serial.println(y,DEC);
  Serial.println(',');
  Serial.println(z,DEC);
  Serial.println('\n');
  delay(10);
  //num = random(-1,1);
  //Serial.write(num);
  
  
  
  
  //worked once with only x and \n with print() and bluesmirf
  
  
  
  
  
}
