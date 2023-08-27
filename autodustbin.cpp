 #include <Servo.h>  
 Servo myservo;   
 int pos = 20;   
 const int trigPin = 10; 
 const int trigpin2= 5;
 const int echopin2= 6; 
 const int echoPin = 11;
 const int led = 12;  
 const int led2=8;
 const int led3=7; 
 
 void setup()   
 {  
  //Serial.begin (9600);
  myservo.attach(9);  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  pinMode(trigpin2, OUTPUT);  
  pinMode(echopin2, INPUT); 
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  
  
  myservo.write(pos);  
 }  
 void loop()   
 {  
  long duration2; 
  float distance2;
  digitalWrite(trigpin2, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigpin2, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigpin2, LOW); 
  duration2=pulseIn(echopin2,HIGH); 
  distance2=0.034*(duration2/2); 
  
  if(distance2<10)
  {
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led,LOW);

    myservo.write(pos); 
  }
   else if(distance2>=10&&distance2<=25)
   {
      digitalWrite(led3,HIGH);
      digitalWrite(led2,LOW);
    long duration; 
    float distance;
    int count=0;
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);  
    distance = 0.034*(duration/2);
    timestep1:
    if (distance < 20)  
    { count ++;
      if(count>=3){
      digitalWrite(led,HIGH);  
      myservo.write(pos+160);
      count=0;} 
      else{delay(750);
        goto timestep1;} 
      delay(3000);  
    }   
    else   
    {  
      digitalWrite(led,LOW); 
      myservo.write(pos);  
    } delay(300);
       
   }
  else      
  { digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    long duration; 
    float distance;
    int count=0;
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);  
    distance = 0.034*(duration/2);
    timestep:
    if (distance < 20)  
    { count ++;
      if(count>=3){
      digitalWrite(led,HIGH);  
      myservo.write(pos+160);
      count=0;} 
      else{
        delay(750);
        goto timestep;} 
      delay(3000);  
    }  
    else   
    {  
      digitalWrite(led,LOW); 
      myservo.write(pos);  
    } delay(300); }
    } 
