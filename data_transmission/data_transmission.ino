//#include <RH_ASK.h>
//#include <SPI.h>
#include <VirtualWire.h>
//RH_ASK driver;
const int transmit_pin = 12;
int thumbpin = A0;
int indexpin = A1;
int middlepin = A2;
int ringpin = A3;
int pinkypin = A4;
//String transmit = String();



  int thumbmax=500,indexmax=500,middlemax=700,ringmax=650,pinkymax=400;
  int thumbmin=150,indexmin=200,middlemin=300,ringmin=360,pinkymin=200;
  
  double thumbtransmit,indextransmit,middletransmit,ringtransmit, pinkytransmit;
//  int thumbval=500, indexval=500, middleval=500,ringval=500,pinkyval=500;
  int thumbval,indexval,middleval,ringval,pinkyval;
void setup() {
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);
  Serial.begin(9600);
  }



void loop() {
  // put your main code here, to run repeatedly:
  
//  transmit = "";
  thumbval = 3*analogRead(thumbpin);
  indexval = 3*analogRead(indexpin);
  middleval = 3*analogRead(middlepin);
  ringval = 3*analogRead(ringpin);
  pinkyval = 3*analogRead(pinkypin);
//  transmit = "Thumb: ";
//  transmit +=thumbval;
//  transmit += " Index: ";
//  transmit += indexval;
//  transmit += " Middle: ";
//  transmit += middleval;
//  transmit += " Ring: ";
//  transmit += ringval;
//  transmit += " Pinky: ";
//  transmit += pinkyval;
//  Serial.println(transmit);
//  delay(1000);

  thumbtransmit = map(thumbval,thumbmin,thumbmax,0,180);
  indextransmit = map(indexval,indexmin,indexmax,0,180);
  middletransmit = map(middleval,middlemin,middlemax,0,180);
  ringtransmit = map(ringval,ringmin,ringmax,0,180);
  pinkytransmit = map(pinkyval,pinkymin,pinkymax,0,180);

  double allfinger[5] = {thumbtransmit,indextransmit,middletransmit,ringtransmit, pinkytransmit};

  Serial.println();
  vw_send((uint8_t *)allfinger, sizeof(allfinger));
  vw_wait_tx(); // Wait until the whole message is gon
  delay(1000);
  thumbval+=1, indexval+=1, middleval+=1,ringval+=1,pinkyval+=1;
} 
