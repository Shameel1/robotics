#include <AccelStepper.h>

AccelStepper step1(AccelStepper::DRIVER, 2, 5);

int stepper_enable = 8;
int steps;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepper_enable, OUTPUT); 
  digitalWrite(stepper_enable, LOW); //Enable the stepper
  step1.setMaxSpeed(1000);
  step1.setAcceleration(1000);
  step1.setSpeed(1000);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    int angle = Serial.parseInt();
    if (Serial.peek() == '\n') Serial.read();  // consume LF
    steps = angle2step(angle);
    step1.moveTo(steps);
  }
  step1.run();
}

int angle2step(int angle){
  int micro_stepping = 8;
  int stepsPerRevolution = 200*micro_stepping;
  int steps = (angle/360.0)*stepsPerRevolution;
  return steps;
}
