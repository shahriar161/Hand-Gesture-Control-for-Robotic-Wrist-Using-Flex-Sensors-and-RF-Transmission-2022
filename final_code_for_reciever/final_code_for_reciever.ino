#include <VirtualWire.h>
//#include <Servotimer2.h>
#include <ServoTimer2.h>  // the servo library
ServoTimer2 pinkyServ,thumbServ,indexServ,middleServ,ringServ;


double thumb, index, middle, ring, pinky;
double sensorArray[5] = {};


const int receive_pin = 11;
int thumb_init = 750;
int index_init = 2250;
int middle_init = 2250;
int ring_init = 2250;
int pinky_init = 750;



void setup() {
  
  pinkyServ.attach(6);
  ringServ.attach(5);
  middleServ.attach(4);
  indexServ.attach(3);
  thumbServ.attach(2);

  thumbServ.write(thumb_init);
  indexServ.write(index_init);
  middleServ.write(middle_init);
  ringServ.write(ring_init);
  pinkyServ.write(pinky_init);
  vw_set_rx_pin(receive_pin);

  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_rx_start();
  
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  // Non-blocking
  if (vw_get_message(buf, &buflen))
  {
    memcpy(sensorArray, buf, buflen);
    //int i;
    // Turn on a light to show received good message
    digitalWrite(13, true);

    // Message with a good checksum received, dump it.
    //for (i = 0; i < buflen; i++)
    //{
      // Fill Sensor1CharMsg Char array with corresponding
      // chars from buffer.
      //sensorArray[i] = char(buf[i]);
     
    //}
   thumb= sensorArray[0];// == x;
   index= sensorArray[1]; //== y;
   middle= sensorArray[2]; //== z;
   ring= sensorArray[3];
   pinky= sensorArray[4];
//thumb & pinky positons are inversed with other three

  thumb = 180 - thumb;
  pinky = 180 - pinky;



  if (thumb<=100){thumb = 0;}
//  else if (thumb>80 && thumb<=100){thumb=90;}
  else {thumb=180;}
  
  if (index<=100){index = 0;}
//  else if (index>80 && index<=100){index=90;}
  else {index=180;}
  
  if (middle<=100){middle = 0;}
//  else if (middle>80 && middle<=100){middle=90;}
  else {middle=180;}
  
  if (ring<=100){ring = 0;}
//  else if (ring>80 && ring<=100){ring=90;}
  else {ring=180;}
  
  if (pinky<=100){pinky = 0;}
//  else if (pinky>80 && pinky<=100){pinky=90;}
  else {pinky=180;}
//data received

//  mapping for servotimer2
  thumb = map(thumb,0,180,750,2250);
  
  index = map(index,0,180,750,2250);
  middle = map(middle,0,180,750,2250);
  ring = map(ring,0,180,750,2250);
  pinky = map(pinky,0,180,750,2250);

  if (thumb>thumb_init) thumbhigh();
  else if(thumb<thumb_init) thumblow();
  
  if (index>index_init) indexhigh();
  else if(index<index_init) indexlow();

  if (middle>middle_init) middlehigh();
  else if(middle<middle_init) middlelow();

  if (ring>ring_init) ringhigh();
  else if(ring<ring_init) ringlow();
  
  if (pinky>pinky_init) pinkyhigh();
  else if(pinky<pinky_init) pinkylow();
  
//  thumbServ.write(thumb);
//  delay(50);
//  indexServ.write(index);
//  delay(50);
//  middleServ.write(middle);
//  delay(50);
//  ringServ.write(ring);
//  delay(50);
//  pinkyServ.write(pinky);
//  delay(50);
   Serial.print("Thumb: ");
    Serial.print(thumb);

    Serial.print("  Index: ");
    Serial.print(index);

    Serial.print("  Middle: ");
    Serial.print(middle);
    
    Serial.print("  Ring: ");
    Serial.print(ring);
    
    Serial.print("  Pinky: ");
    Serial.println(pinky);

    Serial.print("\n__________\n");

   thumb_init = thumb;
   index_init = index;
   middle_init = middle;
   ring_init = ring;
   pinky_init = pinky;
  
  }
//  
//  thumbServ.write(2250);
//  indexServ.write(2250);
//  middleServ.write(2250);
//  ringServ.write(750);
//  pinkyServ.write(2250);
}

//thumb
void thumbhigh(){
  for(int i = thumb_init; i<=thumb; i++){
    thumbServ.write(i);
    delayMicroseconds(500);   
  }
}
void thumblow(){
  for(int i = thumb_init; i>=thumb; i--){
    thumbServ.write(i);
    delayMicroseconds(500);   
  }
}
//index
void indexhigh(){
  for(int i = index_init; i<=index; i++){
    indexServ.write(i);
    delayMicroseconds(500);   
  }
}
void indexlow(){
  for(int i = index_init; i>=index; i--){
    indexServ.write(i);
    delayMicroseconds(500);   
  }
}
//middle
void middlehigh(){
  for(int i = middle_init; i<=middle; i++){
    middleServ.write(i);
    delayMicroseconds(500);   
  }
}
void middlelow(){
  for(int i = middle_init; i>=middle; i--){
    middleServ.write(i);
    delayMicroseconds(500);   
  }
}
//ring
void ringhigh(){
  for(int i = ring_init; i<=ring; i++){
    ringServ.write(i);
    delayMicroseconds(500);   
  }
}
void ringlow(){
  for(int i = ring_init; i>=ring; i--){
    ringServ.write(i);
    delayMicroseconds(500);   
  }
}
void pinkyhigh(){
  for(int i = pinky_init; i<=pinky; i++){
    pinkyServ.write(i);
    delayMicroseconds(500);   
  }
}
void pinkylow(){
  for(int i = pinky_init; i>=pinky; i--){
    pinkyServ.write(i);
    delayMicroseconds(500);   
  }
}
