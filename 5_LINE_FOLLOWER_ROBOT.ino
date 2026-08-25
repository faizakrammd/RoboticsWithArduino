int ir1 = 2, ir2 =19;
int motor1 = 4, motor2 = 5, motor3 = 7, motor4 = 6;
int enA = 10, enB = 9;
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
if(statusSensor2 == HIGH && statusSensor1 == HIGH)
{
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW);
digitalWrite(motor4, LOW);
}
if(statusSensor2 == LOW && statusSensor1 == LOW )
{
digitalWrite(motor1, HIGH);
digitalWrite(motor2, LOW);
digitalWrite(motor3, HIGH);
digitalWrite(motor4, LOW);
}
if (statusSensor2 == LOW && statusSensor1 == HIGH)
{
digitalWrite(motor1, LOW);
digitalWrite(motor2, LOW);
digitalWrite(motor3, HIGH);
digitalWrite(motor4, LOW);
}
if (statusSensor2 == HIGH && statusSensor1 == LOW )
{
digitalWrite(motor1, HIGH);
digitalWrite(motor2, LOW);
digitalWrite(motor3, LOW);
digitalWrite(motor4, LOW);
}
}
