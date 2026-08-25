int LDR1 = A7, LDR2 = A6;
int motor1 = 4,motor2 = 5,motor3 = 7,motor4 = 6;
int enA = 10, enB = 9;
int sensorValue1 = 0, sensorValue2 = 0;

void setup() {
 pinMode(LDR1, INPUT);
 pinMode(LDR2, INPUT);

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
void loop(){
int sensorValue1 = analogRead(LDR1);
int sensorValue2 = analogRead(LDR2);
Serial.print(sensorValue1);
Serial.print("\t");
Serial.println(sensorValue2);
if(sensorValue1>=600&&sensorValue2>=400&&sensorValue2<=700)
 {
 digitalWrite(motor1,HIGH);
 digitalWrite(motor2,LOW);
 digitalWrite(motor3,HIGH);
 digitalWrite(motor4,LOW);
 } 
 else if(sensorValue1>=700 && sensorValue2 >= 500)
 {
 digitalWrite(motor1,LOW);
 digitalWrite(motor2,LOW);
 digitalWrite(motor3,HIGH);
 digitalWrite(motor4,LOW);
 } 
 else if(sensorValue1>=800 && sensorValue2 <= 300)
 {
 digitalWrite(motor1,HIGH);
 digitalWrite(motor2,LOW);
 digitalWrite(motor3,LOW);
 digitalWrite(motor4,LOW);
 } 
 else
 {
 digitalWrite(motor1,LOW);
 digitalWrite(motor2,LOW);
 digitalWrite(motor3,LOW);
 digitalWrite(motor4,LOW);
 } 
}
