#include <SoftwareSerial.h>


#define X_AXIS 3  //D3 on the Nano
#define Y_AXIS 4  //D4
#define Z_AXIS A4 //A4

//Serial and SoftwareSerial

SoftwareSerial mySerial(2,3);//

void setup(){
  
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
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
 
 //change mySerial to Serial
  
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
