#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;

SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
int p5jsData; //input data from p5js  
String inData = "";
int ledPin = 13;

void setup()
{
  myservo1.attach(8);
  myservo2.attach(9);
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(ledPin, OUTPUT);
}

void loop()
{
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
    myservo1.detach();
    myservo2.detach();
    Serial.println("MOTOR OFF");
    digitalWrite(ledPin, LOW);
  }
  if (inData == "1") 
  {
    Serial.println("MOTOR ON");
    myservo1.attach(8);
    myservo2.attach(9);
    myservo1.write(180);
    myservo2.write(-180);
    digitalWrite(ledPin, HIGH);
    delay(15);
  }
}
