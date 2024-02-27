#include <AccelStepper.h>

AccelStepper step1(AccelStepper::DRIVER, 2, 5);

int stepper_enable = 8;
int steps;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepper_enable, OUTPUT); 
  digitalWrite(stepper_enable, LOW); //Enable the stepper
  step1.setMaxSpeed(200);
  step1.setAcceleration(200);
  step1.setSpeed(200);

}

void loop() {
  // put your main code here, to run repeatedly:
  steps = angle2step(90);
  step1.moveTo(steps);
  step1.runToPosition();

  steps = angle2step(0);
  step1.moveTo(steps);
  step1.runToPosition(); 
}

int angle2step(int angle){
  int micro_stepping = 8;
  int stepsPerRevolution = 200*micro_stepping;
  int steps = (angle/360.0)*stepsPerRevolution;
  return steps;
}
