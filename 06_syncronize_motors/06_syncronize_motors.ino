// Then try running X0Y0, and X45Y90. What do you observe this time?
// Try adding commands to enable and disable the steppers

#include <AccelStepper.h>
#include <MultiStepper.h>

AccelStepper step1(AccelStepper::DRIVER, 2, 5);
AccelStepper step2(AccelStepper::DRIVER, 3, 6);

MultiStepper steppers;
long positions[2];

int stepper_enable = 8;
int steps;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepper_enable, OUTPUT); 
  digitalWrite(stepper_enable, LOW); //Enable the stepper
  step1.setMaxSpeed(500);
  step1.setAcceleration(1000);
  
  step2.setMaxSpeed(500);  
  step2.setAcceleration(1000);
  
  steppers.addStepper(step1);
  steppers.addStepper(step2);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    char x = Serial.read();
    int angle = Serial.parseInt();
    if (Serial.peek() == '\n') Serial.read();  // consume LF
    steps = angle2step(angle);
    if (x=='X') positions[0] = steps;
    if (x=='Y') positions[1] = steps;

  }
  
  steppers.moveTo(positions);
  steppers.run();

}

int angle2step(int angle){
  int micro_stepping = 8;
  int stepsPerRevolution = 200*micro_stepping;
  int steps = (angle/360.0)*stepsPerRevolution;
  return steps;
}
