#include <Servo.h>

Servo MY_SERVO;
int SERVO_POSITION = 20;
int TRIG_PIN = 5;
int ECHO_PIN = 6;
int LED_PIN = 13;

long distance;
float duration;

void setup() {
  // put your setup code here, to run once:
  MY_SERVO.attach(11);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  MY_SERVO.write(SERVO_POSITION);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, LOW);
  delay(2);
  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, 10);
  distance = 0.034 * (duration / 2);

  if (distance < 30) {
    digitalWrite(LED_PIN, HIGH);
    MY_SERVO.write(SERVO_POSITION + 160);
    delay(1000);
  } else {
    digitalWrite(LED_PIN, LOW);
    MY_SERVO.write(SERVO_POSITION);
  }

  delay(300);
}
