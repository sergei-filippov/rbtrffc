#include <Servo.h>
Servo servo;

int angle;
void setup() {
  pinMode(14,OUTPUT); // serva
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  angle = Serial1.read();
  delay(10);
  servo.write(angle+45);
  

}
