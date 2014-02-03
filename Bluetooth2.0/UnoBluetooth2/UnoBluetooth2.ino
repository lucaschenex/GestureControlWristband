#include <SoftwareSerial.h>

double x,y,z;
int num;

SoftwareSerial mySerial(6,7);

void setup(){
  
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 mySerial.begin(9600);
 
}

void loop(){
  x=analogRead(A0);
  y=analogRead(A1);
  z=analogRead(A2);
//  x=(x-350)/60;
  mySerial.println(x,DEC);
  mySerial.println(',');
  mySerial.println(y,DEC);
  mySerial.println(',');
  mySerial.println(z,DEC);
//  mySerial.print('\n');
  delay(10);
  //num = random(-1,1);
  //Serial.write(num);
  
  
  
  
  //worked once with only x and \n with print() and bluesmirf
  
  
  
  
  
}
