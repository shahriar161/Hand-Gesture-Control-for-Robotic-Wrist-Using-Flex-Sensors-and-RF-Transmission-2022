#include <VirtualWire.h>

// pin denote
#define RED_LED 3
#define BLUE_LED 5
int thumbpin = A0;
int indexpin = A1;
int middlepin = A2;
int ringpin = A3;
int pinkypin = A4;
const int transmit_pin = 12;


// variable declaration
  int thumbmax,indexmax,middlemax,ringmax,pinkymax;
  int thumbmin,indexmin,middlemin,ringmin,pinkymin;
  int thumbval, indexval, middleval,ringval,pinkyval;
  double thumbtransmit,indextransmit,middletransmit,ringtransmit, pinkytransmit;
  

void setup() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);
  Serial.begin(9600);
  calibration();
  Serial.println("_________\nCalibration Done\n___________\n\n\n");
  Serial.println("Max: ");
  Serial.println((String)"Thumb: "+thumbmax+" Index:"+indexmax+" Middle:"+middlemax+" Ring:"+ringmax+" Pinky:"+pinkymax);
  Serial.println("Min: ");
  Serial.println((String)"Thumb: "+thumbmin+" Index:"+indexmin+" Middle:"+middlemin+" Ring:"+ringmin+" Pinky:"+pinkymin);

  
}

void loop() {
  digitalWrite(BLUE_LED, HIGH);
//  delay(1000);
  //sensor live reading
  thumbval = analogRead(thumbpin);
  indexval = analogRead(indexpin);
  middleval = analogRead(middlepin);
  ringval = analogRead(ringpin);
  pinkyval = analogRead(pinkypin);
  thumbtransmit = map(thumbval,thumbmin,thumbmax,0,180);
  indextransmit = map(indexval,indexmin,indexmax,0,180);
  middletransmit = map(middleval,middlemin,middlemax,0,180);
  ringtransmit = map(ringval,ringmin,ringmax,0,180);
  pinkytransmit = map(pinkyval,pinkymin,pinkymax,0,180);

  Serial.print("Thumb:  ");
  Serial.print(thumbtransmit);
  Serial.print("   Index:  ");
  Serial.print(indextransmit);
  Serial.print("   Middle:  ");
  Serial.print(middletransmit);
  Serial.print("   Ring:  ");
  Serial.print(ringtransmit);
  Serial.print("   Pinky:  ");
  Serial.println(pinkytransmit);
  delay(500);  

//Transmission code
  double allFingers[] = {thumbtransmit,indextransmit,middletransmit,ringtransmit, pinkytransmit};  
  vw_send((uint8_t *)allFingers, sizeof(allFingers));
  vw_wait_tx();
  delay(1000);
}


//calibration for getting highest and lowest values of fingers




void calibration() {
  digitalWrite(RED_LED,HIGH);
  int i;
  int calibration_number = 4;
  thumbmax=0,indexmax=0,middlemax=0,ringmax=0,pinkymax=0;
  thumbmin=0,indexmin=0,middlemin=0,ringmin=0,pinkymin=0;
  
  int thumbmaxtemp,indexmaxtemp,middlemaxtemp,ringmaxtemp,pinkymaxtemp;
  int thumbmintemp,indexmintemp,middlemintemp,ringmintemp,pinkymintemp;
  for(i=1;i<=calibration_number;i++){
  //  Serial.println("starting 3,2,1");
    
    delay(1000);
    thumbmaxtemp=0,indexmaxtemp=0,middlemaxtemp=0,ringmaxtemp=0,pinkymaxtemp=0;
    thumbmintemp=4000,indexmintemp=4000,middlemintemp=4000,ringmintemp=4000,pinkymintemp=4000;
//  int thumbval, indexval, middleval,ringval,pinkyval;
    unsigned long time_count = millis()+3000;
    Serial.println("START!!\n");
    digitalWrite(RED_LED, HIGH);
    while(millis()<time_count){
      
      thumbval = analogRead(thumbpin);
      indexval = analogRead(indexpin);
      middleval = analogRead(middlepin);
      ringval = analogRead(ringpin);
      pinkyval = analogRead(pinkypin);
      if(thumbval<thumbmintemp){thumbmintemp=thumbval;}
      if(indexval<indexmintemp){indexmintemp=indexval;}
      if(middleval<middlemintemp){middlemintemp=middleval;}
      if(ringval<ringmintemp){ringmintemp=ringval;}
      if(pinkyval<pinkymintemp){pinkymintemp=pinkyval;}
      
      if(thumbval>thumbmaxtemp & thumbval<1000){thumbmaxtemp=thumbval;}
      if(indexval>indexmaxtemp & indexval<1000){indexmaxtemp=indexval;}
      if(middleval>middlemaxtemp & middleval<1000){middlemaxtemp=middleval;}
      if(ringval>ringmaxtemp & ringval<1000){ringmaxtemp=ringval;}
      if(pinkyval>pinkymaxtemp & pinkyval<1000){pinkymaxtemp=pinkyval;}
    }
    thumbmax +=thumbmaxtemp/calibration_number;
    indexmax +=indexmaxtemp/calibration_number;
    middlemax +=middlemaxtemp/calibration_number;
    ringmax +=ringmaxtemp/calibration_number;
    pinkymax +=pinkymaxtemp/calibration_number;
    
    thumbmin +=thumbmintemp/calibration_number;
    indexmin +=indexmintemp/calibration_number;
    middlemin +=middlemintemp/calibration_number;
    ringmin +=ringmintemp/calibration_number;
    pinkymin +=pinkymintemp/calibration_number;

    
    Serial.println("Max temp: ");
    Serial.println((String)"Thumb: "+thumbmaxtemp+" Index:"+indexmaxtemp+" Middle:"+middlemaxtemp+" Ring:"+ringmaxtemp+" Pinky:"+pinkymaxtemp);
    Serial.println("Min temp: ");
    Serial.println((String)"Thumb: "+thumbmintemp+" Index:"+indexmintemp+" Middle:"+middlemintemp+" Ring:"+ringmintemp+" Pinky:"+pinkymintemp);
    Serial.println("count done.\nWait for 2sec.\n");
    digitalWrite(RED_LED, LOW);
    delay(1000);
    
  }
  
//  delay(5000);
//  Serial.println("____________________________\n\n\n");
}
