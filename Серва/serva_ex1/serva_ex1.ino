#include <Servo.h>
Servo servo;
int p;
bool f;
void setup() {
  servo.attach(14);
  delay(1000);
  Serial.begin(9600);
  servo.write(1500);

}

void loop() {
 /* for(int i =1050;i<1840;i++){
    Serial.println(i);
    servo.write(i);
      delay(10);
  }
  for(int i =1840;i>1050;i--){
    Serial.println(i);
    servo.write(i);
      delay(10);
  }*/
   /*// p=map( analogRead(14), 0, 1023, 0, 180);
   p=analogRead(14);
    Serial.println(p);
  if(p> 1024){
    servo.write(p-1024);
  }else{
    servo.write(p+1000);
  }*/

  


}
