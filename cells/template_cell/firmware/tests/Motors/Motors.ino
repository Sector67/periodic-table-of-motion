int motor_left[] = {1, 2};
int motor_right[] = {3, 10};

long runTime = 500;

void setup()                    
{
   pinMode(1,OUTPUT); //MOTOR 1A
   pinMode(2,OUTPUT); //MOTOR 2A
   pinMode(3,OUTPUT); //MOTOR 3A
   pinMode(10,OUTPUT); //MOTOR 4A
}

void loop()                    
{
  drive_backward();
  delay(runTime);// arbitrary delay
  motor_stop(); 
  delay(runTime);// arbitrary delay
  drive_forward();
  delay(runTime);// arbitrary delay
  motor_stop(); 
  delay(runTime);// arbitrary delay
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
