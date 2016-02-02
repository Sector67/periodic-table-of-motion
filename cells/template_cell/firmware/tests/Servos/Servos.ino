#include <SoftwareServo.h>

SoftwareServo servo1; //SV1
SoftwareServo servo2; //SV2
int pos = 0;

void setup()
{
  servo1.attach(1);
  servo1.setMaximumPulse(2200);
  servo2.attach(2);
  servo2.setMaximumPulse(2200);
}

void loop()
{
  for(pos = 1; pos < 180; pos += 5)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    //servo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);
  SoftwareServo::refresh();
  } 
  for(pos = 180; pos>=1; pos-=5)     // goes from 180 degrees to 0 degrees 
  {                                
    servo1.write(pos);              // tell servo to go to position in variable 'pos' 
    //servo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);
  SoftwareServo::refresh();
  } 
  /*servo1.write(255);
  servo2.write(255);*/
}
