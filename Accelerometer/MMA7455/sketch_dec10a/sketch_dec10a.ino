// Example which uses the MMA_7455 library
// Moritz Kemper, IAD Physical Computing Lab
// moritz.kemper@zhdk.ch
// ZHdK, 20/11/2011

#include <Wire.h> //Include the Wire library
#include <MMA_7455.h> //Include the MMA_7455 library

MMA_7455 mySensor = MMA_7455(); //Make an instance of MMA_7455

char xVal, yVal, zVal; //Variables for the values from the sensor

void setup()
{
  Serial.begin(9600);
  // Set the sensitivity you want to use
  // 2 = 2g, 4 = 4g, 8 = 8g
  mySensor.initSensitivity(2);
  // Calibrate the Offset, that values corespond in 
  // flat position to: xVal = -30, yVal = -20, zVal = +20
  // !!!Activate this after having the first values read out!!!
  // -8, -31, 68
 // mySensor.calibrateOffset(8,31,-4);
   mySensor.calibrateOffset(1,19,-13);
  // it was 
  
}

void loop()
{
  xVal = mySensor.readAxis('x'); //Read out the 'x' Axis
  yVal = mySensor.readAxis('y'); //Read out the 'y' Axis
  zVal = mySensor.readAxis('z'); //Read out the 'z' Axis
  
  Serial.print(xVal, DEC);
  delay(10);
  Serial.print(",");
  delay(10);
  Serial.print(yVal, DEC);
  delay(10);
  Serial.print(",");
  delay(10);
  Serial.println(zVal, DEC);
  delay(10);
  
//  Serial.print(xVal,DEC);
//  Serial.print('|');
//  Serial.print(yVal,DEC);
//  Serial.print(':');
//  Serial.println(zVal,DEC);
  
}
