/*
  Controls the LEDs of the board.
  8 = PB2 = LED2 = 5V supply
  9 = PB1 = LED1 = 12V supply
 */
 
int led1 = 9;
int led2 = 8;

void setup() {
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);
  delay(1000);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, HIGH);
  delay(1000);               // wait for a second
}
