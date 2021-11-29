#define MOVE_FORWARD 16736925
#define MOVE_BACK 16754775
#define TURN_LEFT 16720605
#define TURN_RIGHT 16761405
#define TASK1 16724175
#define TASK2 16718055
#define TASK3 16743045
#define TASK4 16716015
#define REPT 4294967295
#include "IRremote.h"
#include "Stepper.h"

Stepper stepper(255, 8, 9, 10, 11);

//DC Motor
int enB = 2;
int in3 = 4;
int in4 = 2;
int i = 0;

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
  stepper.setSpeed(100);
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
        move_status = 0;
        break;
      case TASK4:
        Serial.println("Task 4 GO!");
        stepper.step(2500);
        move_status = 0;
        break;
      default:
        switch (move_status){
          case 1:
            Serial.println("+ cont");
            break;
          case 2:
            Serial.println("- cont");
            break;
          case 3:
            Serial.println("left cont");
            break;
          case 4:
            Serial.println("right cont");
            break;
          default:
            Serial.println(results.value);
            break;
        }
    }
    irrecv.resume();
  }
}
