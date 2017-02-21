/**********************************************************************************/
/*    Demo program for:          												  */
/*	  Board: BB-VNH3SP30                 										  */
/*    Manufacture: OLIMEX                                                   	  */
/*	  COPYRIGHT (C) 2015														  */
/*    Designed by: Engineer Stefan Mavrodiev                                      */
/*    Module Name    :  main module                                               */
/*    File   Name    :  main.c                                                    */
/*    Revision       :  1.2.0			                                          */
/*    Date           :  26.01.2015                                                */
/*    Built with Arduino C/C++ Compiler, version: 1.0.5                           */
/**********************************************************************************/

// Revision  history
// 
// Revision: 1.2.0 - Fixed the table for the layout of the connections. Added notes 
// about VIN and PWR.
//
// Revision: 1.1.0 - Fixed the table for the layout of the connections. Added note 
// about possible hardware damage.
//
// Revision: 1.0.0 - (initial)
//
// Description: This simple program is designed by using Olimexino-328 board and 
// BB-VNH3SP30 connected to it. We don't use BB-VNH3SP30's VIN to power the motor! 
// In our example the power for the motor is provided by the board's power connector 
// named "PWR". Alternatively, BB-VNH3SP30's VIN can be used but: DO NOT PROVIDE 
// POWER SIMULTANEOUSLY TO BOTH PWR AND BB-VNH3SP30'S VIN!
// 
// BE VERY CAREFUL WITH THE HARDWARE CONNECTIONS. SWAPPING PINS 1 AND 2 MIGHT LEAD 
// TO HARDWARE DAMAGE!
//
//      |---------------------------------------------------------------------------|
//      |            The hardware connections are as follows:                       |
//      |--------------------------------|------------------------------------------|
//      |  Connector at Olimexino-328    |      Connector at BB-VNH3SP30            |
//      |--------------------------------|------------------------------------------|
//      |    Not connected!              |          CTRL<1>,  VIN                   |
//      |    Power<3>, 5V         	     |          CTRL<2>,  +5V                   |
//      |    Power<4>, GND               |          CTRL<3>,  GND                   |
//      |    Digital<9>                  |          CTRL<4>,  INA                   |
//      |    Digital<13>                 |          CTRL<5>,  INB                   |
//      |    Digital<11>                 |          CTRL<6>,  PWM                   |
//      |    Digital<10>                 |          CTRL<7>,  ENA/DIAGA             |
//      |    Digital<12>                 |          CTRL<8>,  ENB/DIAGB             |
//      |--------------------------------|------------------------------------------|
//
//  Connect pot or trimmer on analog pin 0 (A0). According to the value PWM changes 
//	and speed of the rotation of the motor. The motor start to rotate CW. Then when 
//  the BUT is pressed the rotation start. After one more press of BUT the motor 
//  start to rotate CCW direction.


const int inaPin = 13;
const int inbPin = 9;
const int pwmPin = 11;
const int diagaPin = 10;
const int diagbPin = 12;
const int buttonPin = 2;
const int trimPin = A0;

int i = 0;

void setup() {
  pinMode(buttonPin, INPUT);     //pins on motor driver ↓↓
  pinMode(inaPin, OUTPUT);   //5
  pinMode(inbPin, OUTPUT);   //4
  pinMode(pwmPin, OUTPUT);   //6
  pinMode(diagaPin, INPUT);  //7
  pinMode(diagbPin, INPUT);  //8
  pinMode(trimPin, INPUT);   // any sensor
 
}

void loop() {
  
  // CW
  digitalWrite(inaPin, HIGH);
  digitalWrite(inbPin, LOW);
  while(digitalRead(buttonPin) == HIGH){
    i = analogRead(trimPin);
    analogWrite(pwmPin, map(i, 0, 1023, 0, 255));

  }
  while(digitalRead(buttonPin) == LOW);
  delay(500);
  
  //STOP
  digitalWrite(inaPin, LOW);
  digitalWrite(inbPin, LOW);
  while(digitalRead(buttonPin) == HIGH);
  while(digitalRead(buttonPin) == LOW);
  delay(500);
  
  // CCW
  digitalWrite(inaPin, LOW);
  digitalWrite(inbPin, HIGH);
  while(digitalRead(buttonPin) == HIGH){
    i = analogRead(trimPin);
    analogWrite(pwmPin, map(i, 0, 1023, 0, 255)); 
  }
  while(digitalRead(buttonPin) == LOW);
  delay(500);
  
   //STOP
  digitalWrite(inaPin, HIGH);
  digitalWrite(inbPin, HIGH);
  while(digitalRead(buttonPin) == HIGH);
  while(digitalRead(buttonPin) == LOW);
  delay(500);
  
}
