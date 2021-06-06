#include<Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut1 6//for balls
#define sensorOut2 7//for target colour
#define OutG 8
#define TargetO 9
#define forservo 11
#define sensorwork 12
#define start A1
Servo placing;

int Reda,Redb,Greena,Greenb,Bluea,Blueb,W,analogvalue,servoread;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut1, INPUT);
  pinMode(sensorOut2, INPUT);
  pinMode(OutG,OUTPUT);
  pinMode(TargetO,OUTPUT);
  pinMode(forservo,INPUT_PULLUP);
  pinMode(sensorwork,INPUT_PULLUP);
  pinMode(start,INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  placing.attach(10);
  Serial.begin(9600);
}

//main
void loop() {
   placing.write(70);
   delay(50);
   
  analogvalue=analogRead(start);
  if (analogvalue>500){
    
  //detect the target colour
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency 
  
  Redb = pulseIn(sensorOut2, LOW);
  // Printing the value on the serial monitor 
  
  Serial.print("Redb= ");
  Serial.print(Redb);
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read

  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  
   Greenb = pulseIn(sensorOut2, LOW);
 // Printing the value on the serial monitor
 
  Serial.print("Greenb= ");
  Serial.print(Greenb); 
  Serial.print("  ");
  delay(100);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Bluea = pulseIn(sensorOut2, LOW);
  Serial.print("Blueb= ");//printing name
  Serial.print(Blueb);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  
  if(Redb<55&&Greenb>85){
    digitalWrite(TargetO,HIGH);
    Serial.println("O");
  }
  
  else if(Redb>70&&Greenb<70){
    digitalWrite(TargetO,LOW);
    Serial.println("G");
  }
  }

  // Setting Blue filtered photodiodes to be read

  
 
 //for colors
   int detection=digitalRead(sensorwork);
   if(detection==0){
    for(int i=0;i<9;i++){
    
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Reda = pulseIn(sensorOut1, LOW);
  Serial.print("Reda= ");//printing name
  Serial.print(Reda);//printing RED color frequenc
  Serial.print("  ");
  Serial.print("Redb= ");
  Serial.print(Redb);
  Serial.print("  ");
  delay(100);

  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Greena = pulseIn(sensorOut1, LOW);
  Serial.print("Greena= ");//printing name
  Serial.print(Greena);//printing RED color frequency
  Serial.print("  ");
  Serial.print("Greenb= ");
  Serial.print(Greenb); 
  Serial.print("  ");
  delay(100);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Bluea = pulseIn(sensorOut1, LOW);
  Serial.print("Bluea= ");//printing name
  Serial.print(Bluea);//printing RED color frequency
  Serial.println("  ");
  delay(100);

 
  
    
  //Target Orange
if(Redb<55&&Greenb>85){

 if(Reda>125&&Greena>165&&Bluea>175){
    Serial.println("nothing");
    delay(300);}
  else if(Reda>55&&Greena<140){
    Serial.println ("It's Green"); 
    digitalWrite(OutG,HIGH);
    delay(3000);}
  else if (Reda<55){
    Serial.println("It's Orange,target");
    digitalWrite(OutG,LOW);
    delay(3000);}
}
    
//Target Green
  else if(Redb>70&&Greenb<70){
  
  if(Reda>125&&Greena>165&&Bluea>175){
    Serial.println("nothing");
    delay(300);}
  else if(Reda>55&&Greena<140){
    Serial.println ("It's Green,target");
    digitalWrite(OutG,HIGH);
    delay(3000);
    }
  else if (Reda<50){
    Serial.println("It's Orange");
    digitalWrite(OutG,LOW);
    delay(3000);}

     delay(1000);
      }
    }
   }
   
 //servo motor
 servoread = digitalRead(forservo);
 if(servoread==0){
  
  placing.write(150);
  delay(500);
  delay(3000);
  placing.write(70);
  delay(500);
    
    }
   
  }
 

