#include <Arduino.h>
#include <Servo.h>

Servo servo1;  // Erstellen von Objekten für die beiden Servomotoren
Servo servo2;

int pot1 = A0;  
int pot2 = A1;
int centerDet = 13;

void setup() {
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(centerDet, INPUT);
  servo1.attach(6, 900, 2100);  // Anschließen der Servomotoren an digitale Pins + min max Werte
  servo2.attach(9, 900, 2100);
  // Serial.begin(9600);
}

void loop() {
  int pot1ValA = analogRead(pot1);  // Lesen des Werts vom ersten Kreuzpotentiometer PinA
  int pot2ValA = analogRead(pot2);  // Lesen des Werts vom zweiten Kreuzpotentiometer PinA
  // Serial.println((String)"Pot1 = " + pot1ValA);
  // Serial.println((String)"Pot2 = " + pot2ValA);
  
  int servo1Pos;
  int servo2Pos;
    
  if (digitalRead(centerDet) == HIGH){
    servo1Pos = map(pot1ValA, 300, 1023, 0, 180);  // Übersetzung des Potentiometerwerts in einen Servomotorwinkel
    servo2Pos = map(pot2ValA, 300, 1023, 0, 180);  // Übersetzung des Potentiometerwerts in einen Servomotorwinkel
  }
  else {
    servo1Pos = 90;
    servo2Pos = 90;
  }
  // Serial.println((String)"Servo1Pos = " + servo1Pos);
  // Serial.println((String)"Servo2Pos = " + servo2Pos);

  servo1.write(servo1Pos);  // Ansteuern des ersten Servomotors
  servo2.write(servo2Pos);  // Ansteuern des zweiten Servomotors

  delay(30);  // kurze Pause für eine bessere Kontrolle
}