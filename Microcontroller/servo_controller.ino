#include <Servo.h>

const int SERVO_RANGE = 165;

Servo servo;
void setup() 
{
  Serial.begin(9600);
  servo.attach(A0);
  servo.write(SERVO_RANGE);
}

void turnServo(int data)
{
    if (data >= 0 && data < SERVO_RANGE)
      servo.write(SERVO_RANGE - data);
}

void loop() { 
  if (Serial.available() > 0)
  {
    int data = Serial.read();
    turnServo(data);
  }
}
