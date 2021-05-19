const int ledPin = 13;      // the pin that the LED is attached to

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  int brightness;
  // check if data has been sent from the computer:
  if (Serial.available() > 0) 
  {
    brightness = Serial.read();
    if(brightness == 1)
    {
      digitalWrite(ledPin, HIGH);
    }
    else if(brightness == 0)
    {
      digitalWrite(ledPin, LOW);
    }
  }
  else
  {
    Serial.print("Nothing\n");
  }
}
