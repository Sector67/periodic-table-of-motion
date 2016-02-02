/*
Using the following resistor values, with a 5V supply, yields the following voltage readings, which yields the following ADC values.
Use a range for some variability
R1 = 2200
R2 = 3.4k = 3.148V = 644 = 600-700
R3 = 1k = 1.563V = 320 = 300-400
R4 = 620 = 1.099V = 225 = 200-300
R5 = 330 = .652V = 133 = 100-200
R6 = 0 = 0V = 0 = 0-100
*/


int motor_left[] = {1, 2};
int motor_right[] = {3, 10};

//the variable that holds the analog reading
int limit_switches = 1023;

void setup()                    
{
   pinMode(0,INPUT); //limit switches
   pinMode(1,OUTPUT); //MOTOR 1A
   pinMode(2,OUTPUT); //MOTOR 2A
   pinMode(3,OUTPUT); //MOTOR 3A
   pinMode(10,OUTPUT); //MOTOR 4A
}

void loop()                    
{
    delay(10);// arbitrary delay
    
    //read the value of the limit switches
    limit_switches = analogRead(0);
    
    //R6
    if (limit_switches >= 0 && limit_switches < 100){
      drive_forward(); 
    }
    
    //R5
    else if (limit_switches >=100 && limit_switches < 200){
     drive_backward();
    }
    
    //R4
    else if (limit_switches >=200 && limit_switches < 300){
     drive_forward();
    }
    
    //R3
    else if (limit_switches >=300 && limit_switches < 400){
     drive_backward();
    }
    
    //R2
    else if (limit_switches >=600 && limit_switches < 700){
     drive_forward();
    }
    
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
