/*
Software für Arduino Nano (Uno) zur Ansteuerung von 2x Servomotoren für eine Ventilsteuerung.
Für TWO.
*/


#include <Arduino.h>
#include <Servo.h>

// Erstellen von Objekten für die beiden Servomotoren
Servo servo1;  
Servo servo2;

int pot1 = A0;  
int pot2 = A1;
int centerDet = 13;

void setup() {
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(centerDet, INPUT);

  // Anschluss Servomotoren digitale Pins + Einstellung min- max-Werte Servo
  servo1.attach(6, 900, 2100);
  servo2.attach(9, 900, 2100);
  // Serial.begin(9600);                                  // zum debuggen
}

void loop() {
  // Lesen Analogwert Kreuz-Hebel-Schalter
  int pot1ValA = analogRead(pot1);
  int pot2ValA = analogRead(pot2);
  // Serial.println((String)"Pot1 = " + pot1ValA);        // zum debuggen
  // Serial.println((String)"Pot2 = " + pot2ValA);        // zum debuggen
  
  int servo1Pos;
  int servo2Pos;
    
  if (digitalRead(centerDet) == HIGH){
    // Übersetzung Analogwerte >> Servowinkel
    servo1Pos = map(pot1ValA, 300, 1023, 0, 180);
    servo2Pos = map(pot2ValA, 300, 1023, 0, 180);
  }
  else {
    servo1Pos = 90;
    servo2Pos = 90;
  }
  // Serial.println((String)"Servo1Pos = " + servo1Pos);  // zum debuggen
  // Serial.println((String)"Servo2Pos = " + servo2Pos);  // zum debuggen

  // Ansteuerung Servomotoren
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
  
  // Kurze Pause zur besseren Kontrolle, ggf. nach Motortyp anpassen
  delay(30);
}