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

  // Turn off motors - Initial stateppull
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  stepper.setSpeed(100);
}

void loop() {
  Task_4();
}

// This function lets you control spinning direction of motors
void run_DC_motor() {
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

void Task_4() {
  delay(2000);
  while (stop == false) {
    run_DC_motor();
    //    delay(1000);
    stepper.step(2500);
    delay(2000);
    i++;
    if (i == 4) {
      stop = true;
    }

  }
}
