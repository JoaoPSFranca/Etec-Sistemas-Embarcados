// C++ code

#include <Servo.h>

#define buzzer1 11
#define buzzer2 12

int pos = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);
  pinMode(buzzer1,OUTPUT);
  pinMode(buzzer2,OUTPUT);  
}

void loop()
{
  for (pos = 0; pos <= 180; pos+= 4) {
    servo_9.write(pos);
    delay(10);
  }
  
  for (pos = 180; pos >= 0; pos-= 4) {
    servo_9.write(pos);
    delay(10);
  }
}