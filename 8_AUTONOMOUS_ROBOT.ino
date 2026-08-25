#include <Servo.h>       
#include <NewPing.h>     

const int motor1 = 4, motor2 = 5, motor3 = 7, motor4 = 6;
int enA = 10, enB = 9;
#define TRIGGER_PIN  11  
#define ECHO_PIN     8  
#define MAX_DISTANCE 500 

Servo servo_motor;  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

boolean goesForward = false;
int distance = 300; //in Cm 


void setup()
{
  
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);  

  analogWrite(enA, 255); 
  analogWrite(enB, 255);
  
  servo_motor.attach(3);  
  servo_motor.write(115);  
  delay(2000);             
  distance = readPing();    
  delay(100);    
  Serial.begin(9600);        
}

void loop()
{  
  Serial.println(distance);
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 40)
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(300);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft)
    {
      turnRight();
      delay(300);
      moveStop();
    }
    else
    {
      turnLeft();
      delay(300);
      moveStop();
    }
  
  }
  else
  {
    moveForward(); 
  }

    distance = readPing();
}

int lookRight()   
{  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft()      
{
  servo_motor.write(180);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int readPing()     
{
  delay(100);               
  int cm = sonar.ping_cm();  
  if (cm==0)
  {
    cm=250;
  }
  return cm;
}

void moveStop()       
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}

void moveForward() 
{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
}

void moveBackward()  
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}

void turnRight()   
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}

void turnLeft()      
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}
