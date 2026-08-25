int ir1 = 2;
int ir2 = 19;
int motor1 = 4;
int motor2 = 5;
int motor3 = 7;
int motor4 = 6;
int enA = 10;
int enB = 9;
void setup() {
pinMode(ir1, INPUT);
pinMode(ir2, INPUT);
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
pinMode(motor3, OUTPUT);
pinMode(motor4, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
analogWrite(enA, 200);
analogWrite(enB, 200);
Serial.begin(9600);
}
void loop()
{
int statusSensor2 = digitalRead(ir2);
int statusSensor1 = digitalRead(ir1);
if (statusSensor1 == HIGH && statusSensor2== HIGH)
{
Forward();
}
else
{
Stop();
delay(1000);
Backward();
delay(1000);
TurnLeft();
delay(500);
Forward();
}
}
// Functions for robot direction;
void Forward()
{
digitalWrite(motor1, HIGH);
digitalWrite(motor2, LOW);
digitalWrite(motor3, HIGH);
digitalWrite(motor4, LOW);
}
void Backward()
{
digitalWrite(motor1, LOW);
digitalWrite(motor2, HIGH);
digitalWrite(motor3, LOW);
digitalWrite(motor4, HIGH);
}
void TurnLeft()
{
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, HIGH);
digitalWrite(motor4, LOW);
}
void Stop()
{
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW);
digitalWrite(motor4, LOW);
}
