// This example by David Jonas uses the Sonar library

#include <Servo.h>
#include <Sonar.h>

int motorPin = 10;
int max_distance = 20;
int motorPosition = 0;
int motorSpeed = 4;
boolean debug = false;
Servo motor;
Sonar s1(7,6);
Sonar s2(11,12);

void setup(){
  if(debug)
  {
    Serial.begin (9600);
  }
  
  motor.attach(motorPin);
  motor.write(0);
}

void loop() {
  long distance = s1.getDistance();
  long distance2 = s2.getDistance();

  //Two hand motor control
  if(distance < max_distance && distance2 < max_distance)
  {
    if (distance > distance2)
    {
      moveRight();
    }
    else
    {
      moveLeft();
    }
  }

  //Arm move
//  if(distance < max_distance)
//  {
//     motor.write(map(distance, 0, max_distance, 0, 180));
//  }
//  else
//  {
//    motor.write(180);
//  }
  
  
  if(debug)
  {
    Serial.print("Distance1: ");
    Serial.print(distance);
    Serial.println("cm");
    Serial.print("Distance2: ");
    Serial.print(distance2);
    Serial.println("cm");
  }
  delay(100);
}

void moveLeft()
{
  if(motorPosition > 0)
  {
    motorPosition -= motorSpeed;
    motor.write(motorPosition);
  }
}

void moveRight()
{
  if(true || motorPosition < 180)
  {
    motorPosition += motorSpeed;
    motor.write(motorPosition);
  }
}


