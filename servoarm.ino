#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
int motor1; //input data from p5js
Servo myservo;

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
    motor1 = HM10.read();
    motor2 = HM10.read();
  }
  myservo.write(motor1);
}
