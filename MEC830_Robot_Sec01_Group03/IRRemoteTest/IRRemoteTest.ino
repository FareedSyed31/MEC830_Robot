//IR Sensor
//You may need to install the driver on Arduino, as well as
// moving the folder into your sketch folder

//I have Robot IR Remote Version 2.0 installed

//remove the installed library from the Arduino library folder and replace it with the one provided

//IR.h also needs to be in the program folder as it is used to associate the ir signal with the
// remote button name
// the digital input for the ir receiver is also defined in this file
// digital input is set for 11

//The receiver module has three connections, G, R and Y
//G - Ground
//R - 5v
//Y - Signal

#include "IRremote.h"
#include "IR.h"

IRrecv irrecv(RECEIVER);
decode_results results;


void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}

void loop() {
  int tmpValue;
  if (irrecv.decode(&results)){ //if a signal is received start loop
    for (int i = 0; i < 23; i++){
      if ((keyValue[i] == results.value) && (i < KEY_NUM)){
        Serial.println(keyBuf[i]); //button name
        Serial.println(keyValue[i]); //decimal button value
        int tmpVale = results.value;
      }
      else if (REPEAT==i){ //if the same button is pressed the repeat signal is sent
        results.value = tmpValue;
        Serial.println("REPEAT");
      }
    }
    irrecv.resume();
  }
}
//Power Button - 16753245
//Vol+ - 16736925
//Func/Stop - 16769565
//Fast Back - 16720605
//Pause - 16712445
//Fast Forward - 16761405
//Down - 16769055
//Vol- - 16754775
//Up - 16748655
//0 - 16738455
//Eq - 16750695
//St/Rept - 16756815
//1 - 16724175
//2 - 16718055
//3 - 16743045
//4 - 16716015
//5 - 16726215
//6 - 6734885
//7 - 16728765
//8 - 16730805
//9 - 16732845
