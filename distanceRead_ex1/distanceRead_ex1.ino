void setup() {
  Serial.begin(9600);
 // pinMode(A10,INPUT);
  pinMode(A9,INPUT);

}

void loop() {
 // Serial.println(analogRead(A10));
  Serial.println(analogRead(A9));
  //delay(200);

}
