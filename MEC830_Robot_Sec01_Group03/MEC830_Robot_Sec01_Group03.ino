// MEC830 - Robot Car

// Contributers:
// Fareed Syed - 500819438
// Jeremiah Lumbantobing - 500826233
// MP - 500590070
// Add your name - student#

// testing github pull option

#include <Stepper.h>
Stepper stepper(255, 8, 9, 10, 11);

// DC Motor
int enB = 2;
int in1 = 3;
int in2 = 4;
int i = 0;
bool stop = false;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  stepper.setSpeed(50);
}

void loop() {

  while (stop == false) {
    directionControl();
    delay(2000);
    stepper.step(2000);
    delay(2000);
    i++;
    if (i == 4) {
      stop = true;
    }

  }
}

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enB, 255);

  // Turn on motor to Go forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);

  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enB, i);
    delay(20);
  }

  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enB, i);
    delay(20);
  }

  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
