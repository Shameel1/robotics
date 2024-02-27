// Move the arms to the starting or home position, then type H0 in the Serial monitor
// Now actuate the robot through external software
// Make sure to close the Serial monitor on Arduino

#include <AccelStepper.h>
#include <MultiStepper.h>

AccelStepper step1(AccelStepper::DRIVER, 2, 5);
AccelStepper step2(AccelStepper::DRIVER, 3, 6);

MultiStepper steppers;
long positions[2];

int stepper_enable = 8;
int steps;
bool reached_target = false;
bool previous_state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepper_enable, OUTPUT); 
  digitalWrite(stepper_enable, HIGH); //Disable the steppers
  step1.setMaxSpeed(500);
  
  step2.setMaxSpeed(500);  
  
  steppers.addStepper(step1);
  steppers.addStepper(step2);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    char x = Serial.read();
    float value = Serial.parseFloat();
    if (Serial.peek() == '\n') Serial.read();  // consume LF
    steps = angle2step(value);
    if (x=='X') positions[0] = steps;
    if (x=='Y') positions[1] = steps;
    if (x=='H') set_home();
    if (x=='E') digitalWrite(stepper_enable, !value);
    if (x=='S') set_speeds(value);
 
  }
  reached_target = check_distance();
  if (reached_target!=previous_state) {
    if (reached_target) Serial.print("G");
    previous_state=reached_target;
  }

  steppers.moveTo(positions);
  steppers.run();

}


bool check_distance(){
  return !(step1.distanceToGo()+step2.distanceToGo());
}

void set_home(){
  positions[0] = 0;
  positions[1] = 0;
  
  step1.setCurrentPosition(0);
  step2.setCurrentPosition(0);
  digitalWrite(stepper_enable, LOW); //Enable the stepper
}

void set_speeds(int speeds){
  step1.setMaxSpeed(speeds);
  step2.setMaxSpeed(speeds);
}

int angle2step(float angle){
  int micro_stepping = 8;
  int stepsPerRevolution = 200*micro_stepping;
  int steps = (angle/360.0)*stepsPerRevolution;
  return steps;
}
