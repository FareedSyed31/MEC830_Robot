// MEC830 - Robot Car

// Contributers:
// Fareed Syed - 500819438
// Jeremiah Lumbantobing - 500826233
// MP - 500590070
// Add your name - student#
//test
// testing github pull option

#include <Stepper.h>
Stepper stepper(32, 8, 9, 10, 11);

// DC Motor
int enB = 2;
int in1 = 3;
int in2 = 4;
int i = 0;

bool stop_task2 = false;
bool stop_task3 = false;
bool stop_task4 = false;

const int x_key = A1;
const int y_key = A0;

int x_pos;
int y_pos;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Turn off motors - Initial stateppull
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  stepper.setSpeed(1000);

  pinMode (x_key, INPUT) ;  //declaring the joystick inputs
  pinMode (y_key, INPUT) ;
}

void loop() {
  //  Task_1();
  //  Task_2();
  //  Task_3();
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

void Task_1() {
  x_pos = analogRead (x_key) ;  //reading joystick signals
  y_pos = analogRead (y_key) ;
  Serial.print(x_key);
  Serial.print(" ");
  Serial.println(y_key);

  if (x_pos < 300) {

    analogWrite(enB, 255);

    // Turn on motor to Go forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1000);
    // Turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }


  if (x_pos > 700) {

    analogWrite(enB, 255);

    // Turn on motor to Go forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(2500); ;
    // Turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);


  }


  if (y_pos < 300) {

    stepper.step (100) ;

  }

  if (y_pos > 700) {

    stepper.step (-100);

  }
}

void Task_2() {
  delay(2000);
  while (stop_task2 == false) {
    run_DC_motor();
    stepper.step(3000);
    delay(1000);
    run_DC_motor();
    stepper.step(-3000);
    run_DC_motor();
    delay(1000);
    stop_task2 = true;
  }
}

void Task_3() {
  delay(2000);
  while (stop_task3 == false) {
    run_DC_motor();
    stepper.step(-1250);
    run_DC_motor();
    stepper.step(1250);
    run_DC_motor();
    stepper.step(1250);
    run_DC_motor();
    stepper.step(-1250);
    run_DC_motor();
    stop_task3 = true;
  }
}

void Task_4() {
  delay(2000);
  while (stop_task4 == false) {
    run_DC_motor();
    delay(2000);
    i++;
    if (i == 4) {
      stop_task4 = true;
      break;
    }
    stepper.step(3000);
  }
}
