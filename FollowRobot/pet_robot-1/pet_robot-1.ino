//Code :)
#include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 11);  //  <-(trig pin, echo pin)
int distance;

Servo myservo;  // create Servo object to control a servo
int pos = 0;    // variable to store the servo position

int position_0 = 0;    // for ultrasonic snsor
int position_90 = 0;   // for ultrasonic snsor
int position_180 = 0;  // for ultrasonic snsor
int ENA = 9;           // PWM pin for speed
int IN1 = 2;           // direction pin 1
int IN2 = 3;           // direction pin 2

// Motor B (Right Motor)
int ENB = 10;  // PWM pin for speed
int IN3 = 4;   // direction pin 1
int IN4 = 5;   // direction pin 2

// Speed variables (0–255)
int baseSpeed = 150;  // normal forward speed
int turnSpeed = 100;  // reduced speed for turning


int Distance() {
  distance = ultrasonic.read();  // distance in cm by default
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  myservo.attach(8);  // attaches the servo on pin 9 to the Servo object
  myservo.write(90);  // center position
  delay(2000);        // wait for servo to stabilize
}
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);  // left motor fast
  analogWrite(ENB, turnSpeed);  // right motor slow
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, turnSpeed);  // left motor slow
  analogWrite(ENB, baseSpeed);  // right motor fast
}


void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}



void loop() {
  // Sweep from 0 to 90
  for (pos = 90; pos <= 180; pos++) {
    myservo.write(pos);
    delay(10);  // smoother motion
  }
  position_90 = Distance();


  // Sweep from 90 to 180
  for (pos = 180; pos >= 90; pos--) {
    myservo.write(pos);
    delay(10);
  }
  position_180 = Distance();

  // Sweep from 180 back to 90
  for (pos = 90; pos >= 0; pos--) {
    myservo.write(pos);
    delay(10);
  }
  position_90 = Distance();

  // Sweep from 90 back to 0
  for (pos = 0; pos <= 90; pos++) {
    myservo.write(pos);
    delay(10);
  }
  position_0 = Distance();


  Serial.print("0_position=  ");
  Serial.print(position_0);
  Serial.print(",  90_position= ");
  Serial.print(position_90);
  Serial.print(",  180 _position= ");
  Serial.print(position_180);
  if (position_180 >= 50 & position_180 <= 60) {
    Serial.println("ROTATE RIGHT");
    turnRight();
    delay(2000);
  } else if (position_0 >= 50 & position_0 <= 60) {
    Serial.println("Rotate left");
    turnLeft();
    delay(2000);
  }

  if (position_90 >= 30 & position_90 <= 100) {
    Serial.println("  follow");
    forward();
    delay(2000);
  } else if (position_90 <= 30) {
    Serial.println("  Stop");
    stopRobot();
    delay(3000);
  } else {
    Serial.println("   out of bound");
  }
}
