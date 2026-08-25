int motor1 = 4; //Define motor driver pins
int motor2 = 5;
int motor3 = 7;
int motor4 = 6;

int enA = 10;  //pins for speed control
int enB = 9;

char inputByte;

void setup() {
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

void loop() {
  inputByte= Serial.read();
  Serial.println(inputByte);
  
  if (inputByte=='F'){
 // BACKWARD();
  FORWARD(); //in all bots
  }
  else if (inputByte=='B'){
 // FORWARD();
  BACKWARD();
  } 
  else if (inputByte=='R'){
//  TURN_LEFT();
  TURN_RIGHT(); 
  } 
  else if (inputByte=='L'){
 //   TURN_RIGHT(); 
    TURN_LEFT();
  } 
  if (inputByte=='Y'){
  STOP();
  }

  }

void FORWARD()
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  Serial.println("FORWARD ");    
}
void BACKWARD()
{ 
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  Serial.println("BACKWARD");
}
void STOP()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  Serial.println("STOP");
}
void TURN_RIGHT()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  Serial.println("TURN LEFT");
}
void TURN_LEFT(){
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  Serial.println("TURN RIGHT");
}
