#include <CapacitiveSensor.h>

CapacitiveSensor   cs_6_7 = CapacitiveSensor(6,7);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

// Variables will change:
int buttonReading;
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int motor_left[] = {1, 2};
int motor_right[] = {3, 10};

int limit_switches = 1023;

long runTime = 4000;

void setup()                    
{
   cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   pinMode(8,OUTPUT); //MOSFET
   pinMode(9,OUTPUT); //MOSFET
   pinMode(1,OUTPUT); //MOTOR 1A
   pinMode(2,OUTPUT); //MOTOR 2A
   pinMode(3,OUTPUT); //MOTOR 3A
   pinMode(10,OUTPUT); //MOTOR 4A
}

void loop()                    
{
    delay(10);// arbitrary delay
    
    limit_switches = analogRead(0);
    
    if (limit_switches < 500){
      motor_stop(); 
    }
    else if (limit_switches < 800){
     drive_backward();
    }
    
    long total1 =  cs_6_7.capacitiveSensor(120);

    if (total1>100){
      buttonReading = 1;
    }
    else {
      buttonReading = 0;
    }
    
  // If the switch changed, due to noise or pressing:
  if (buttonReading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (buttonReading != buttonState) {
      buttonState = buttonReading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        digitalWrite(8,HIGH);
        digitalWrite(9,LOW);
        drive_forward();
      }
    }
  }
  if ((millis() - lastDebounceTime) > debounceDelay+runTime) {
        digitalWrite(9,HIGH);
        digitalWrite(8,LOW);
        motor_stop();
  }
  lastButtonState = buttonReading;
}

void motor_stop(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);
delay(25);
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 
}

void drive_backward(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}
