#include <Servo.h> 
Servo servo1;
#include <math.h>
#define echoPin 7 
#define trigPin 8 
#define pinbott 6
#define led 2
#define pinpot A0
#define bottp 8
#define bottm 9
#define led2 10
#define led3 3


long tempo; 
int altezza = 10; //cambiare con il valore della distanza tra i laser 
int distanza;
double angolo1;
int angoloServo;
int copia;
int diff;
int angMan;
int bottone = 0;
int lum1;
int lum2;

void setup() {
 pinMode(trigPin, OUTPUT); //inizializzazione pin per sensore
 pinMode(echoPin, INPUT);
 pinMode(pinbott, INPUT);
 pinMode(pinpot, INPUT);
 pinMode(led, OUTPUT);
 pinMode(bottp, INPUT);
 pinMode(bottm, INPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
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
 Serial.println("pronto");
   if (digitalRead(6)==0){
   Serial.println("automatico"); } else 
   {Serial.println("manuale");
   delay(3000); 
   while(digitalRead(6)==0)
   {digitalWrite(led, HIGH); 
   if (digitalRead(8) != 0 && digitalRead(9) == 0)
   {angoloServo += 1; 
   servo1.write(angoloServo);
   Serial.println(angoloServo);
   delay(500);}
   else if (digitalRead(9)!= 0 && digitalRead(8) == 0)
   {angoloServo -= 1; 
   servo1.write(angoloServo);
   Serial.println(angoloServo);
   delay(500);}
   }
   angoloServo = 0;
   digitalWrite(led, LOW);
   }        
   
   
}
