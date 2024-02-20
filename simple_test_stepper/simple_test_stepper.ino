#include <AccelStepper.h>

AccelStepper step1(AccelStepper::DRIVER, 2, 5);

int stepper_enable = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepper_enable, OUTPUT); 
  digitalWrite(stepper_enable, LOW); //Enable the stepper
  step1.setMaxSpeed(200);
  step1.setAcceleration(200);
  step1.setSpeed(200);

  step1.moveTo(400);
  step1.runToPosition(); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
