    #include <Servo.h>
    
    const int LE_horizontal = 6;
    Servo SLE_horizontal;


void setup() 
{
  SLE_horizontal.attach(LE_horizontal);
  Serial.begin(9600);
}

void loop() 
{
  //allign to middle
  SLE_horizontal.write(90);
  delay(1000);

  //slowly yaw
  for( int i {65}; i <= 120; ++i)
  {
    SLE_horizontal.write(i);
    delay(300);
  }
}
