#include <ServoTimer2.h>


//#include"ServoTimer2.h"
ServoTimer2 servo1,servo2,servo3,servo4,servo5;
int i,j;
void setup() 
{
servo1.attach(2);   
servo2.attach(3);   
servo3.attach(4);   
servo4.attach(5);   
servo5.attach(6);   
}
void loop() 
{  
//  servo1.write(750);
//    servo2.write(2250);
//    servo3.write(2250);
//    servo4.write(2250);
//    servo5.write(750);
  
  for (i=750;i<=2250;i++){
    j = 2250-i;
    servo1.write(j);
    servo2.write(i);
    servo3.write(i);
    servo4.write(i);
    servo5.write(j);
    delayMicroseconds(1000);
  }
  delay(2000);

  for(i=2250;i>=750;i--){
    j=2250-i;
    servo1.write(j);
    servo2.write(i);
    servo3.write(i);
    servo4.write(i);
    servo5.write(j);
    delayMicroseconds(1000);
  }
  delay(1000);
}
