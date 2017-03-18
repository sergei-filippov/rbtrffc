#include <Servo.h>
Servo servo;
bool stopline;
int angle, speed1, irda, d1, d2, d3, distanceEdge, speedBeforCrossing;
const int inaPin = 26;
const int inbPin = 27;
const int pwm = 3;
const int diagaPin = 24;
const int diagbPin = 25;
int incomingByte;
void setup() {
  //-----------------//distance detectors
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  //----------------//
  servo.attach(14);    //serva 55-125
  delay(1000);
  pinMode(inaPin, OUTPUT);   //50
  pinMode(inbPin, OUTPUT);   //4
  pinMode(pwm, OUTPUT);   //3
  pinMode(diagaPin, INPUT);  //7
  pinMode(diagbPin, INPUT);  //8


  digitalWrite(inaPin, LOW); // for motors
  digitalWrite(inbPin, HIGH);

  Serial.begin(115200);
  Serial1.begin(115200); //seeeduino
  Serial2.begin(115200); //irda
  Serial3.begin(115200); //stopline
  speed1 = 70;
  distanceEdge = 20;
  speedBeforCrossing = 50;
}

void loop() {
  //----------------------------------//distance attributive
  d1 = 5222 / (analogRead(A6) - 13); //probably it changes values into cm
  d2 = 5222 / (analogRead(A7) - 13);
  d3 = 5222 / (analogRead(A8) - 13);
  if (d1 <= distanceEdge || d2 <= distanceEdge || d3 <= distanceEdge) {
    speed1 = 0;
  }
  //----------------------------------//
  //------------------------------------------------------------//irda things
  irda = Serial2.read();
  if (irda == 0 || irda == 1 || irda == 4) { //if red,red+yellow,yellow
    speed1 = speedBeforCrossing;

  }

  //------------------------------------------------------------//
  //---------------------------------------------//stopline
  if (Serial3.available()) {
    stopline = Serial3.read();
    Serial.println(stopline);
    if (stopline) {
      speed1 = 0;
      Serial.print("STOP");
    }
  }

  //-----------------------------------------------//
  //-----------------------------------------------------------//read from camera
  if (Serial1.available()) {
    // incomingByte = Serial1.read();
    angle = Serial1.read() + 90;
    //     Serial.print(angle);
    //   Serial.print(" ");
    if (angle > 156)
    {
      angle -= 256;
    }
    //    Serial.println(angle);
    //  delay(10);
    servo.write(angle);
    //  Serial.print(angle);
    //Serial.print(incomingByte);
    //    Serial.print(" \n");
  }
  //----------------------------------------------------------//
  /*if (Serial1.available() > 0) {
      // read the oldest byte in the serial buffer:
      incomingByte = Serial1.read();
      Serial.print(incomingByte);
      Serial.print(" \n");
    }*/
  analogWrite(pwm, speed1);      //motor static


}
