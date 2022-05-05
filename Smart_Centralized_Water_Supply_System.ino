#include<Servo.h>
Servo myservo;
int pos = 0;
float d;
float e;
int low=23;
int high=5;

   void setup() {

    Serial.begin(9600);
    pinMode(2,INPUT);//echo pin of ultraSonic1
             
    pinMode(4,OUTPUT);//trig pin of ultraSonic1   

    pinMode(7,INPUT);//echo pin of ultraSonic2         

    pinMode(8,OUTPUT);//trig pin of ultraSonic2   

    pinMode(10,OUTPUT);// relay
    
    myservo.attach(9);

 }

    void vol() //distance calculaion...

 {

    digitalWrite(8,HIGH);

       delayMicroseconds(8);

   digitalWrite(8,LOW);

       delayMicroseconds(2);

   d=pulseIn(7,HIGH);

   d= d / 69;
   delay(100);

 }

    void loop() 
    {

   vol(); while(1)

    {

    b: digitalWrite(10,HIGH);// Pump On...

        delay(2000); vol();

    if(d<high) //check high...
{
    { 
   
   digitalWrite(4,HIGH);

       delayMicroseconds(8);

   digitalWrite(4,LOW);

       delayMicroseconds(8);

       e=pulseIn(2,HIGH);

         e= e / 69;
  }

     {
     for (pos = 0; pos <= 90; pos += 1)   // goes from 0 degrees to 90 degrees
                                      // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 5 ms for the servo to reach the position
    if(e>low)                        //check low...
   

    goto a;

     }
  }

     while(1)

    {

        a: digitalWrite(10,LOW);// pump off...

             delay(100);

     vol(); if(d>low) //check low
    {
      for (pos = 90; pos >= 0; pos -= 1)  // goes from 90 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
         delay(15);                     // waits 15 ms for the servo to reach the position
    }
     

 goto b;

   }
 }}
