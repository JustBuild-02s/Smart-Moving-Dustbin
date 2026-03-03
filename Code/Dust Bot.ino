#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN A4
#define ECHO_PIN A5
#define SERVO_PIN 10

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

Servo lidServo;

int openAngle = 0;
int closeAngle = 180;

long duration;
int distance;
bool lidOpened = false;

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;

  return duration * 0.034 / 2;
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void moveForward() {
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lidServo.attach(SERVO_PIN);
  lidServo.write(closeAngle);

  stopMotors();
  delay(2000);
}

void loop() {
  distance = getDistance();
  Serial.println(distance);

  if (distance > 30 && distance <= 60) {
    moveForward();
    lidOpened = false;
  }
  else if (distance > 0 && distance <= 15) {
    stopMotors();

    if (!lidOpened) {
      lidOpened = true;
      lidServo.write(openAngle);
      delay(5000);
      lidServo.write(closeAngle);
    }
  }
  else {
    stopMotors();
    lidOpened = false;
  }

  delay(200);
}
