#include <SoftwareSerial.h>


SoftwareSerial mySerial(7,9);// RX, TX 

void setup(){
  
 pinMode(3, INPUT); //X to D3
 pinMode(4, INPUT); //Y to D4
 pinMode(A4, INPUT); //Z to A3
 mySerial.begin(9600);
 
}

void loop(){
  int x,y,z;
  int num;
  x=analogRead(3);
  y=analogRead(4);
  z=analogRead(A4);
  ////////////////
//  if (x>511)
//    x = x-1024;
//  if (y>511)
//    y = y-1024;
//  if (z>511)
//    z = z-1024;
  
  ////////////////
  
  //x=(x-350)/60;
  mySerial.println(x,DEC);
  mySerial.println('\n');
  delay(10);
  mySerial.println(',');
    mySerial.println('\n');
  delay(10);
  mySerial.println(y,DEC);
    mySerial.println('\n');
  delay(10);
  mySerial.println(',');
    mySerial.println('\n');
  delay(10);
  mySerial.println(z,DEC);
    mySerial.println('\n');
  delay(10);
  mySerial.println('\n');
    delay(10);
  //num = random(-1,1);
  //Serial.write(num);
  
}
