#include <SoftwareSerial.h>
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
int p5jsData; //input data from p5js  
String inData = "";
int outputPin = 12;

void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(outputPin, OUTPUT); // onboard LED
  digitalWrite(outputPin, LOW); // switch OFF LED
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
    Serial.println("LED OFF");
    digitalWrite(outputPin, LOW); // switch OFF LED
  }
  if (inData == "1") 
  {
    Serial.println("LED ON");
    digitalWrite(outputPin, HIGH); // switch OFF LED
  }
}
