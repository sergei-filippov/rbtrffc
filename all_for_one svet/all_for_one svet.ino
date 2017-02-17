#include <Servo.h>

Servo servo;
Servo servom;

int distStop = 10;
int dist, cm, svet1, svet2, black, white, midLight;
int rotation = 1.31;  //roatain *
int k = 900;          // rotation +
int speed1 = 1650;    // normal spped

void buzz3sec() {
  for (int i = 0; i < 1500; i++) {
    digitalWrite(10, HIGH);
    delay(1);
    digitalWrite(10, LOW);
    delay(1);

  }
}

void setup() {
  pinMode(15, OUTPUT); // motor
  servo.attach(14);    //1050 - straight right   1800 - straight left
  servom.attach(15);
  delay(500);
  Serial.begin(9600);
  pinMode(10, OUTPUT); // buzz
  pinMode(27, INPUT);  // button
  pinMode(A8, INPUT);  // svet // levo
  pinMode(A7, INPUT);  // svet // pravo
  pinMode(15, OUTPUT); // serva
  pinMode(A6, INPUT);  // dist
  digitalWrite(27, HIGH);

  //---------------------------------------------------------------//
  while (true) {
    bool flag = 0;
    if (digitalRead(27) == LOW) {
      buzz3sec();

      black = analogRead(A7);
      while (true) {
        if (digitalRead(27) == LOW) {
          buzz3sec();
          delay(1000);
          white = analogRead(A7);                     //----------------------------// detecting white and black values at this very place
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        break;
      }
    }
  }
  Serial.println(white);
  Serial.println(black);
  midLight = (white + black) / 2;
}
//----------------------------------------------------------------------//
void loop() {

  servom.write(speed1);        //  speed things

  //-----------------------------------------------------------------------------//driving
  svet1 = analogRead(A7);          // white-850; black - 220
  svet2 =  analogRead(A8);
  if (svet1 > midLight && svet1 < white) {
    servo.write(1050);
  } else {
    servo.write(1800);
  }
  Serial.println(svet1);



  // servo.write();


  //-----------------------------------------------------------------//

  //-------------------------------------------------------------------------------//
  if ((5222 / (analogRead(A6) - 13)) <= distStop) {
    while (true) {
      servom.write(0);                                                                   // stop in case of another car
      Serial.println(1000);
    }
  }
  //-------------------------------------------------------------------------------------//
}
