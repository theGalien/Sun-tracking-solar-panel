#include <Servo.h>

Servo myservo;
Servo servo1;
int error = 5;
/*int sensorReading = analogRead(A0);
int sensorReading1 = analogRead(A1);
int sensorReading2 = analogRead(A2);
int sensorReading3 = analogRead(A3);*/




int pos = 90 ;//above plate 
int pos1 = 90;//below plate

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
/*pinMode(  sensorReading, INPUT);
pinMode( sensorReading1, INPUT);
pinMode( sensorReading2, INPUT);
pinMode( sensorReading3, INPUT);*/
myservo.attach(9);
servo1.attach(11);
myservo.write(pos);
servo1.write(pos1);
delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorReading = analogRead(A0);
int sensorReading1 = analogRead(A1);
int sensorReading2 = analogRead(A2);
int sensorReading3 = analogRead(A3);
int D1 = digitalRead(9);
 delay(100); 
int D2 = digitalRead(11);
 delay(100); 
Serial.println(D1);
Serial.println(D2);
/*int diff1=abs(sensorReading - sensorReading1);
int diff2=abs(sensorReading1 - sensorReading);
int diff3=abs(sensorReading2 - sensorReading3);
int diff4=abs(sensorReading3 - sensorReading2);*/
Serial.println(sensorReading);
 delay(100); 
Serial.println(sensorReading1);
 delay(100); 
Serial.println(sensorReading2);
 delay(100); 
Serial.println(sensorReading3);
 delay(100); 

/*if((diff1<=error)||(diff2<=error)||(diff3<=error)||(diff4<=error))*/


  if (sensorReading>sensorReading1)
  {
   pos = --pos;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
  }
  else{
    pos = ++pos;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
 }
   if (sensorReading2>sensorReading3)
    {
   pos1 = ++pos1;
    servo1.write(pos1);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
  }
  else{
    pos1 = --pos1;
    servo1.write(pos1);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
 }

delay(200);
}


