#include <Servo.h> 
 
Servo myservo;  
                
 
int pos = 90;    
 
void setup() 
{ 
  myservo.attach(10); 
  delay(200);
  myservo.write(pos);
} 
 
 
void loop() 
{ 
  
} 
