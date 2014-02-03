int num;

void setup() {
  Serial.begin(9600); 
}
 
void loop() {
  
  num = random(-1,1);
  Serial.write(num);
  
}
