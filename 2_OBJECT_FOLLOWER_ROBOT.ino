int ir1 = 2; //Define IR sensor for decision making
int ir2 = 19;
int motor1 = 4; //Define motor driver pins
int motor2 = 5;
int motor3 = 7;
int motor4 = 6;
int enA = 10; //pins for speed control
int enB = 9;
void setup()
{
//Define input output pins
pinMode(ir1, INPUT);
pinMode(ir2, INPUT);
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
pinMode(motor3, OUTPUT);
pinMode(motor4, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
analogWrite(enA, 200); //RPM can be between 0-255
analogWrite(enB, 200);
Serial.begin(9600); //initialize the baud rate
}
void loop()
{
int statusSensor1 = digitalRead(ir1);
int statusSensor2 = digitalRead(ir2);
Serial.print(statusSensor1);
Serial.println(statusSensor2);
if (statusSensor1 == HIGH && statusSensor2 == HIGH )
{ // Robot Stops
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW);
digitalWrite(motor4, LOW);
}
if (statusSensor1 == LOW && statusSensor2 == LOW )
{ // Robot Moves Forward
digitalWrite(motor1, HIGH);
digitalWrite(motor2, LOW);
digitalWrite(motor3, HIGH);
digitalWrite(motor4, LOW);
}
if (statusSensor1 == HIGH && statusSensor2 == LOW)
{ // Robot Moves Left
digitalWrite(motor1, HIGH);
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW);
digitalWrite(motor4, LOW);
}
if (statusSensor1 == LOW && statusSensor2 == HIGH)
{ // Robot Moves Right
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, HIGH);
digitalWrite(motor4, LOW);
}
}
