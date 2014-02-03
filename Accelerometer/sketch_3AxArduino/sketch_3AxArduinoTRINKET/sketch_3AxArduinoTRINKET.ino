#include <SoftwareSerial.h>

#define X_AXIS 1 //Pin2
#define Y_AXIS 3 //Pin3 
#define Z_AXIS 2 //Z-Axis in line with Pin4 but named 2

SoftwareSerial mySerial(1,0);
 
void setup() {
  mySerial.begin(9600); 
}
 
void loop() {
  int x = analogRead(X_AXIS);
  int y = analogRead(Y_AXIS);
  int z = analogRead(Z_AXIS);
  mySerial.print(x);
  mySerial.print('|');
  mySerial.print(y);
  mySerial.print(':');
  mySerial.println(z);
  delay(1000);
 

//  Serial.print(x);
//  Serial.print('|');
//  Serial.print(y);
//  Serial.print(':');
//  Serial.println(z);
}
