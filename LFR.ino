int ena=3;
int motorin1=7;
int motorin2=8;

int enb=5;
int motorin3=9;
int motorin4=10;


int irLeft=4;
int irRight=5;


int speedy=96;
int speedu=64;



void setup() {
  // put your setup code here, to run once:
  pinMode(ena,OUTPUT);
  pinMode(motorin1,OUTPUT);
  pinMode(motorin2,OUTPUT);
  pinMode(motorin3,OUTPUT);
  pinMode(motorin4,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(irLeft,INPUT);
  pinMode(irRight,INPUT);

  Serial.begin(9600);
}

void loop() {
  bool left=digitalRead(irLeft);
  bool right=digitalRead(irRight);

  if(left==0 && right==0){
    moveForward();
  }
  else if(left==1 && right==1){
    moveStop();
  }
  else if(left==0 && right==1){
    moveLeft();
  }
  else if(left==1 && right==0){
    moveRight();
  }
  // put your main code here, to run repeatedly:


}
  void moveForward(){
    analogWrite(ena,speedy);
    analogWrite(enb,speedy);
    digitalWrite(motorin1,HIGH);
    digitalWrite(motorin2,LOW);
    digitalWrite(motorin3,HIGH);
    digitalWrite(motorin4,LOW);
    Serial.println("forward");
  }

  void moveStop(){
    
    digitalWrite(motorin1,LOW);
    digitalWrite(motorin2,LOW);
    digitalWrite(motorin3,LOW);
    digitalWrite(motorin4,LOW);
    Serial.println("stop");
  }

  void moveLeft(){
    analogWrite(ena,speedy);
    analogWrite(enb,speedu);
    digitalWrite(motorin1,HIGH);
    digitalWrite(motorin2,LOW);
    digitalWrite(motorin3,LOW);
    digitalWrite(motorin4,HIGH);
    Serial.println("left");
  }

  void moveRight(){
    analogWrite(ena,speedu);
    analogWrite(enb,speedy);
    digitalWrite(motorin1,LOW);
    digitalWrite(motorin2,HIGH);
    digitalWrite(motorin3,HIGH);
    digitalWrite(motorin4,LOW);
    Serial.println("right");
  }
