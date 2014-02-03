#include <SoftwareSerial.h>


SoftwareSerial mySerial(0,1);//

void setup(){
  
 pinMode(2, INPUT);
 pinMode(3, INPUT);
 pinMode(4, INPUT);
 mySerial.begin(9600);
 
}

void loop(){
  int x,y,z;
  int num;
  x=analogRead(2);
  y=analogRead(3);
  z=analogRead(4);
  ////////////////
  if (x>511)
    x = x-1024;
  if (y>511)
    y = y-1024;
  if (z>511)
    z = z-1024;
  
  ////////////////
  
  //x=(x-350)/60;
  mySerial.println(x,DEC);
  mySerial.println('\n');
  delay(100);
  mySerial.println(',');
    mySerial.println('\n');
  delay(100);
  mySerial.println(y,DEC);
    mySerial.println('\n');
  delay(100);
  mySerial.println(',');
    mySerial.println('\n');
  delay(100);
  mySerial.println(z,DEC);
    mySerial.println('\n');
  delay(100);
  mySerial.println('\n');
    delay(100);
  //num = random(-1,1);
  //Serial.write(num);
  
}
