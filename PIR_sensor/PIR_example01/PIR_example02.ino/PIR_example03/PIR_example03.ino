int pirSensor = 3;
int LEDpin = 8;

void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(pirSensor);

  if( sensorValue == HIGH )
  {
    digitalWrite(LEDpin, HIGH);
    Serial.print("MOTION\n");
  }
  else
  {
    digitalWrite(LEDpin, LOW);
    Serial.print("NO MOTION\n");
  }

}
