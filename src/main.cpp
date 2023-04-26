#include <Arduino.h>
#include <Servo.h>

Servo servo1;  // Erstellen von Objekten für die beiden Servomotoren
Servo servo2;

int pot1 = A0;  
int pot2 = A1;

void setup() {
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  servo1.attach(9);  // Anschließen der Servomotoren an digitale Pins
  servo2.attach(10);
  Serial.begin(9600);
}

void loop() {
  int pot1ValA = analogRead(pot1);  // Lesen des Werts vom ersten Kreuzpotentiometer PinA
  int pot2ValA = analogRead(pot2);  // Lesen des Werts vom zweiten Kreuzpotentiometer PinA
  Serial.println(pot1ValA);
  Serial.println(pot2ValA);
  
  int servo1Pos;
  int servo2Pos;
  
  if (pot1ValA >= 20){
    servo1Pos = map(pot1ValA, 0, 1023, 0, 180);  // Übersetzung des Potentiometerwerts in einen Servomotorwinkel
  }
  if (pot2ValA >= 20){
    servo2Pos = map(pot2ValA, 0, 1023, 0, 180);  // Übersetzung des Potentiometerwerts in einen Servomotorwinkel
  }
  
  servo1.write(servo1Pos);  // Ansteuern des ersten Servomotors
  servo2.write(servo2Pos);  // Ansteuern des zweiten Servomotors

  delay(50);  // kurze Pause für eine bessere Kontrolle
}