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

long runTime = 4000;

int led1 = 9;
int led2 = 8;

void setup()                    
{
   cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()                    
{
    delay(10);// arbitrary delay
        
    long total1 =  cs_6_7.capacitiveSensor(30);

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
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
      }
    }
  }
  if ((millis() - lastDebounceTime) > debounceDelay+runTime) {
        digitalWrite(led2,HIGH);
        digitalWrite(led1,LOW);
  }
  lastButtonState = buttonReading;
}
