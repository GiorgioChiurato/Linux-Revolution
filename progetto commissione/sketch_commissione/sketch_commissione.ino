#include <SoftwareServo.h> 
SoftwareServo servo1;
#include <math.h>
#define echoPin 7 
#define trigPin 8 


long tempo; 
int altezza = 1; //cambiare con il valore della distanza tra i laser 
int distanza;
int angolo1;
int angoloServo;


void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 servo1.attach(4);
 Serial.begin (9600);

}

void loop() {
  
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 tempo = pulseIn(echoPin, HIGH);
 
 distanza = tempo*0.034/2;

 Serial.print("Distanza: ");
 Serial.println(distanza);
 
 angolo1 =  atan2(distanza, altezza); 
 if(angolo1 != 0)
 { angoloServo = 90-angolo1;
 
   servo1.write(angoloServo);
   Serial.print("Angolo: ");
   Serial.println(angoloServo);
   delay(15); }else
   { servo1.write(0);
   Serial.print("Angolo: ");
   Serial.println(0);
   delay(15);}
}
 
 
