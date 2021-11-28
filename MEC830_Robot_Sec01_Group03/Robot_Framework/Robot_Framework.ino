#define MOVE_FORWARD 16736925
#define MOVE_BACK 16754775
#define TURN_LEFT 16720605
#define TURN_RIGHT 16761405
#define TASK1 16724175
#define TASK2 16718055
#define TASK3 16743045
#define TASK4 16716015
#include "IRremote.h"

IRrecv irrecv(//SINGAL PIN HERE//);
decode_results results;

void setup() {
irrecv.enableIRIn();
}

void loop() {
  int tmpValue;
  if (irrecv.decode(&results)){
    switch (results.value){
      case MOVE_FORWARD:
        Serial.println("+");
        break;
      case MOVE_BACK:
        Serial.println("-");
        break;
      case TURN_LEFT:
        Serial.println("Left");
        break;
      case TURN_RIGHT:
        Serial.println("Right");
        break;
      case TASK1:
        Serial.println("1");
        break;
      case TASK2:
        Serial.println("2");
        break;
      case TASK3:
        Serial.println("3");
        break;
      case TASK4:
        Serial.println("4");
        break;
      default:
        Serial.println("none");
        break;
    }
    irrecv.resume();
  }
}
