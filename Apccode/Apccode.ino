#include <AccelStepper.h>
int buttonpin1 = 11;
int buttonread1 ;
int buttonpin2 = 10;
int buttonread2 ;
AccelStepper stepper1(1, 3, 2); // (Typeof driver: with 2 pins,
STEP, DIR)
int j = 0 ;
int i = 0;
void setup() {
 Serial.begin(19200);
 stepper1.setMaxSpeed(1000); // Set maximum speed value for the
stepper
 stepper1.setAcceleration(1000); // Set acceleration value for the
stepper
 //stepper1.setCurrentPosition(0); // Set the current position to 0
steps
}
void loop() {
 buttonread1 = digitalRead(buttonpin1);
 buttonread2 = digitalRead(buttonpin2);
 if (j==0){
 stepper1.move(100);
 stepper1.runToPosition();
 }
 Serial.println(buttonread1);
 Serial.println(buttonread2);
 if (j < 5){
 if (buttonread1 == 0){
 stepper1.move(100);
 stepper1.runToPosition();
 delay(100);
 j=j+1;
 }
 if (buttonread2 == 0){
 stepper1.move(-100);
 stepper1.runToPosition();
 delay(100);
 j=j+1;
 }
}
else{
 delay(10000);
 j=0;
}
 //Serial.println(j);
}
