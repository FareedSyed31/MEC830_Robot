
#define MOVE_FORWARD 16736925
#define MOVE_BACK 16754775
#define TURN_LEFT 16720605
#define TURN_RIGHT 16761405
#define TASK1 16724175
#define TASK2 16718055
#define TASK3 16743045
#define TASK4 16716015
#define REPT 4294967295
#define STOP 16756815
#include "IRremote.h"
#include "Stepper.h"
//in1,in2,in3,in4 for stepper setup
Stepper stepper(32, 8, 10, 9, 11);

//DC Motor
int enB = 2;
int in3 = 4;
int in4 = 3;
int i = 0;
bool stop_task3 = false;

bool stop = false;

IRrecv irrecv(12); //change to pin for IR remove signal
decode_results results;

int move_status = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("IR Receiver Button Test");
  irrecv.enableIRIn();
  stepper.setSpeed(500);
}

void loop() {
  if (irrecv.decode(&results)){
    switch (results.value){
      case MOVE_FORWARD:
        Serial.println("+");
        move_status = 1;
        break;
      case MOVE_BACK:
        Serial.println("-");
        move_status = 2;
        break;
      case TURN_LEFT:
        Serial.println("Left");
//        stepper.step(1024);
        move_status = 3;
        break;
      case TURN_RIGHT:
        Serial.println("Right");
        move_status = 4;
        break;
      case TASK1:
        Serial.println("1");
        move_status = 0;
        break;
      case TASK2:
        Serial.println("2");
        move_status = 0;
        break;
      case TASK3:
        Serial.println("3");
        Task_3();
        move_status = 0;
        break;
      case TASK4:
        Serial.println("Task 4 GO!");
        move_status = 0;
        break;
      case STOP:
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        digitalWrite(enB, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        move_status = 0;
      default:
        switch (move_status){
          case 1:
            Serial.println("+ cont");
            analogWrite(enB, 255);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
//            delay(16);
//            digitalWrite(enB, 0);
//            digitalWrite(in3, LOW);
//            digitalWrite(in4, LOW);
            break;
          case 2:
            Serial.println("- cont");
            break;
          case 3:
            Serial.println("left cont");
            stepper.step(10);
            break;
          case 4:
            Serial.println("right cont");
            stepper.step(-10);
            break;
          default:
            Serial.println(results.value);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            break;
        }
    }
    irrecv.resume();
  }
}
void run_DC_motor() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enB, 255);

  // Turn on motor to Go forward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(1000);

  // Turn off motors
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
}
void Task_3(){
  delay(2000);
  while (stop_task3 == false){
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
