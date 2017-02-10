#include <Servo.h>

Servo servo;
Servo servom;

int dist,cm,svet1;
int rotation = 1.31; // starts from 1.31
int speed1 = 1700;
void setup() {
   pinMode(15,OUTPUT); // motor
  servo.attach(14);
  servom.attach(15);
  delay(500);
  Serial.begin(9600);

 pinMode(A8,INPUT); // svet // levo
 pinMode(A7,INPUT); // svet // pravo
 pinMode(15,OUTPUT); //serva
 pinMode(A6,INPUT);// dist
 
}

void loop() {
 
  servom.write(speed1);
 svet1 = analogRead(A7);
 // Serial.print("-");
  servo.write(svet1*rotation +900);
  Serial.println(svet1*rotation +900);
  //Serial.print("\t");
  //Serial.println(svet1);*/
  //delay(90);
  Serial.println(5222/(analogRead(A6)-13));
  if((5222/(analogRead(A6)-13)) <= 20){
    while(true){
      servom.write(0);
      Serial.println(1000);
    }
  }

}
