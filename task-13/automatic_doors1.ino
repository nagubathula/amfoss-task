// C++ code
//
#include <Servo.h>

int distance = 0;

int ldr = 0;

Servo servo_8;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  servo_8.attach(8, 500, 2500);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  servo_8.write(0);
  distance = 0.01723 * readUltrasonicDistance(10, 10);
  ldr = map(analogRead(A0), 0, 1023, 0, 180);
  Serial.println(map(analogRead(A0), 0, 1023, 0, 180));
  if (ldr <= 70) {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }
  if (distance <= 100) {
    servo_8.write(90);
    digitalWrite(9, HIGH);
    Serial.println("object detected");
    delay(10000); // Wait for 10000 millisecond(s)
    servo_8.write(0);
    digitalWrite(9, LOW);
  } else {
    servo_8.write(0);
    digitalWrite(9, LOW);
  }
}