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
  steps = angle2step(90);
  step1.moveTo(steps);
  
  //For acceleration
  //step1.run();
  
  //For constant speed
  step1.setSpeed(400);
  step1.runSpeedToPosition(); 
  
  Serial.println(step1.currentPosition());

}

int angle2step(int angle){
  int micro_stepping = 8;
  int stepsPerRevolution = 200*micro_stepping;
  int steps = (angle/360.0)*stepsPerRevolution;
  return steps;
}
