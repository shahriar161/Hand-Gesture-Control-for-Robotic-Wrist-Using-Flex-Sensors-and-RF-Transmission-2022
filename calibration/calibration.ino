int thumbpin = A0;
int indexpin = A1;
int middlepin = A2;
int ringpin = A3;
int pinkypin = A4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Serial.println("starting 3,2,1");
  delay(3000);
  int thumbmax=0,indexmax=0,middlemax=0,ringmax=0,pinkymax=0;
  int thumbmin=4000,indexmin=4000,middlemin=4000,ringmin=4000,pinkymin=4000;
  int thumbval, indexval, middleval,ringval,pinkyval;
  unsigned long time_count = millis()+5000;
  Serial.println("START!!\n");

  while(millis()<time_count){
      
    thumbval = 3*analogRead(thumbpin);
    indexval = 3*analogRead(indexpin);
    middleval = 3*analogRead(middlepin);
    ringval = 3*analogRead(ringpin);
    pinkyval = 3*analogRead(pinkypin);
    if(thumbval<thumbmin){thumbmin=thumbval;}
    if(indexval<indexmin){indexmin=indexval;}
    if(middleval<middlemin){middlemin=middleval;}
    if(ringval<ringmin){ringmin=ringval;}
    if(pinkyval<pinkymin){pinkymin=pinkyval;}
    
    if(thumbval>thumbmax & thumbval<1000){thumbmax=thumbval;}
    if(indexval>indexmax & indexval<1000){indexmax=indexval;}
    if(middleval>middlemax & middleval<1000){middlemax=middleval;}
    if(ringval>ringmax & ringval<1000){ringmax=ringval;}
    if(pinkyval>pinkymax & pinkyval<1000){pinkymax=pinkyval;}
  }
  Serial.println("Max: ");
  Serial.println((String)"Thumb: "+thumbmax+" Index:"+indexmax+" Middle:"+middlemax+" Ring:"+ringmax+" Pinky:"+pinkymax);
  Serial.println("Min: ");
  Serial.println((String)"Thumb: "+thumbmin+" Index:"+indexmin+" Middle:"+middlemin+" Ring:"+ringmin+" Pinky:"+pinkymin);


  delay(5000);
  Serial.println("____________________________\n\n\n");
  /*
  int thumbval, indexval, middleval,ringval,pinkyval;
  thumbval = 3*analogRead(thumbpin);
  indexval = 3*analogRead(indexpin);
  middleval = 3*analogRead(middlepin);
  ringval = 3*analogRead(ringpin);
  pinkyval = 3*analogRead(pinkypin);
  Serial.println((String)"Thumb: "+thumbval+" Index:"+indexval+" Middle:"+middleval+" Ring:"+ringval+" Pinky:"+pinkyval);
  delay(1000);
*/


  
  /*
  unsigned long time_count=millis()+3000;
  motor_control(150, -150);// eita loop er baire thaka sotteo kaaz kortase kmne??
  while(millis()<time_count){
    for(int i=0; i<10; i++){
      sensor[i]=analogRead(sensor_pin[i]);
      if(sensor[i]<min_value[i]){
        min_value[i]=sensor[i];
      }
      if(sensor[i]>max_value[i]){
        max_value[i]=sensor[i];
      }
    }
  }
*/
}
