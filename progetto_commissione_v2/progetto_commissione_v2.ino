#include <Servo.h> 
Servo servo1;
#include <math.h>
#define echoPin 7 
#define trigPin 8 
#define pinbott 6
#define led 2
#define pinpot A0
long tempo; 
int altezza = 10; //cambiare con il valore della distanza tra i laser 
int distanza;
double angolo1;
int angoloServo;
int angMan;
int bottone = 0;


void setup() {
 pinMode(trigPin, OUTPUT); //inizializzazione pin per sensore
 pinMode(echoPin, INPUT);
 pinMode(pinbott, INPUT);
 pinMode(pinpot, INPUT);
 pinMode(led, OUTPUT);
 servo1.attach(4);
 Serial.begin (9600);

}

void loop() {
 digitalWrite(trigPin, LOW);       //istruzioni per la rilevazione dati dal sensore ad ultrasuoni
 delayMicroseconds(2); 
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 tempo = pulseIn(echoPin, HIGH);

 distanza = tempo*0.034/2; // calcolo della distanza in base ai dati del sensore

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
 delay(1000);
 digitalWrite(led, HIGH);
 Serial.println("pronto");
   if (digitalRead(6)==0){
   Serial.println("automatico");}
   else {delay(3000); while(digitalRead(6) == 0){ Serial.println("manuale");
   angMan = analogRead(pinpot);
   angMan = map(angMan, 0, 1023, 0, 180);
   servo1.write(angMan);
   delay(1000);}}
   
   
}
