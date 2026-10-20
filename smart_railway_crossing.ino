// Automated Smart Railway Crossing and Obstacle Detection System
// Hardware: Arduino Uno (ATmega328P), HC-SR04, SG90 Servo, 16x2 LCD, Buzzer, LEDs
// Simulation Platform: Proteus 8 Professional

#include <LiquidCrystal.h>
#include <Servo.h>

// Pin Configuration
#define TRIG_PIN 9
#define ECHO_PIN 8
#define SERVO_PIN 10
#define BUZZER_PIN 13
#define RED_LED 7
#define GREEN_LED 6

// LCD Pin Interface (RS, E, D4, D5, D6, D7) in 4-bit mode
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo barrierGate;

// Detection Threshold in centimeters
const int criticalDistance = 100;

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  barrierGate.attach(SERVO_PIN);
  barrierGate.write(0); // Gate open initially (0 degrees)
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RAILWAY CROSSING");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM READY");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Ultrasonic Range Measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration * 0.0343) / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < criticalDistance) {
    // Train / Obstacle Detected -> Close Gate
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
    barrierGate.write(90); // Close barrier (90 degrees)
    
    lcd.setCursor(0, 0);
    lcd.print("TRAIN DETECTED! ");
    lcd.setCursor(0, 1);
    lcd.print("GATE CLOSING... ");
  } else {
    // Track Clear -> Open Gate
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    barrierGate.write(0); // Open barrier (0 degrees)
    
    lcd.setCursor(0, 0);
    lcd.print("TRACK CLEAR     ");
    lcd.setCursor(0, 1);
    lcd.print("GATE OPEN       ");
  }

  delay(300);
}
