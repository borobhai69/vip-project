/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
int p5jsData; //input data from p5js
String inData = "";
Servo myservo;
int outputPin = 12;

int pos = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
}

void loop() {
  HM10.listen();  // listen the HM10 port
  while (HM10.available() > 0) 
  {   
    // if HM10 sends something then read
    p5jsData = HM10.read();
    inData = String(p5jsData);  // save the data in string format
    Serial.write(p5jsData);
  }
  
  if (Serial.available()) 
  {           
    // Read user input if available.
    delay(10);
    HM10.write(Serial.read());
  }
  
  if (inData == "0") 
  {
    Serial.println("LED OFF");
    myservo.write(180);
    digitalWrite(outputPin, LOW);
  }
  if (inData == "1") 
  {
    Serial.println("LED ON");
    myservo.write(0);
    digitalWrite(outputPin, HIGH); 
  }
}
