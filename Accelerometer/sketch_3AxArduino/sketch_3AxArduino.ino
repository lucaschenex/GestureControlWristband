#define X_AXIS 3//D3
#define Y_AXIS 4//D4
#define Z_AXIS A4//A4
 
void setup() {
  Serial.begin(9600); 
}
 
void loop() {
  int x = analogRead(X_AXIS);
  int y = analogRead(Y_AXIS);
  int z = analogRead(Z_AXIS);
 
  Serial.print(x);
  Serial.print('|');
  Serial.print(y);
  Serial.print(':');
  Serial.println(z);
}
