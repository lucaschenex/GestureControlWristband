#include <SoftwareSerial.h>

SoftwareSerial mySerial(1,2);

void setup(){
  
// pinMode(INPUT);
// pinMode{A2,INPUT);
// pinMode(A3, INPUT);
  
 pinMode(0,INPUT);
 pinMode(3, INPUT);
 pinMode(4, INPUT);
 mySerial.begin(9600);
 
}

void loop(){
  int x,y,z;
  int num;
  x=analogRead(0);
  y=analogRead(1);// in lieu of pin 3
  z=analogRead(2);//in lieu of pin 4
  //x=(x-350)/60; 
  
  mySerial.println('X');
  delay(10);
  mySerial.println(x,DEC);
  delay(10);
  mySerial.println('Y');
  delay(10);
  mySerial.println(y,DEC);
  delay(10);
  mySerial.println('Z');
  //mySerial.println('\n');
  delay(10);
  mySerial.println(z,DEC);
  delay(10); 
}
