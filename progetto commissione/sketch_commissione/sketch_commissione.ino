#include <Servo.h> 
Servo servo1;
#include <math.h>
#define echoPin 7 
#define trigPin 8 


long tempo; 
int altezza = 10; //cambiare con il valore della distanza tra i laser 
int distanza;
double angolo1;
int angoloServo;


void setup() {
 //pinMode(trigPin, OUTPUT); inizializzazione pin per sensore
// pinMode(echoPin, INPUT);
 servo1.attach(4);
 Serial.begin (9600);

}

void loop() {
 /*digitalWrite(trigPin, LOW);       istruzioni per la rilevazione dati dal sensore ad ultrasuoni
 delayMicroseconds(2); 
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 tempo = pulseIn(echoPin, HIGH);*/

 distanza = Serial.parseInt();   //tempo*0.034/2; calcolo della distanza in base ai dati del sensore

 Serial.print("Distanza: ");
 Serial.println(distanza);
 double ratio = distanza/altezza;
 angolo1 = round (atan(ratio)*180/3.14); 
 if(angolo1 != 0){
  angoloServo = 90-angolo1;
 
   servo1.write(angoloServo);
   Serial.print("Angolo: ");
   Serial.println(angoloServo);
   delay(2000); } else
   { servo1.write(0);
   Serial.print("Angolo: ");
   Serial.println(0);
   delay(15);}
}
 
 
