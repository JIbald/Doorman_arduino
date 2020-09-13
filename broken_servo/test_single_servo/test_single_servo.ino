#include <Servo.h>

const int eyelids = 10;
Servo SEyelids;

void setup() 
{
  SEyelids.attach(eyelids);

  Serial.begin(9600);
}

void loop() 
{
  SEyelids.write(200);
  delay(1000);
  SEyelids.write(60);
  delay(1000);
}
