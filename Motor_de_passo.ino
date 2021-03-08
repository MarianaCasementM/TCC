//original source is http://www.geeetech.com/wiki/index.php/Stepper_Motor_5V_4-Phase_5-Wire_%26_ULN2003_Driver_Board_for_Arduino
// Update by Ahmad Shamshiri for RoboJax.com
// Published on March 27, 2017 in Aajx, ON, Canada.

//*  * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
//* This code has been download from Robojax.com
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//More modifications last made on 16/11/2020 by Mariana Casement.
//*/  

//global variables

int Pin1 = 8; 
int Pin2 = 9; 
int Pin3 = 10; 
int Pin4 = 11; 
int _step = 0; 
boolean dir = true;// false=clockwise, true=counter clockwise
int count = 0;
float result = 0;

void setup() { 
  pinMode(Pin1, OUTPUT);  
  pinMode(Pin2, OUTPUT);  
  pinMode(Pin3, OUTPUT);  
  pinMode(Pin4, OUTPUT);
 
  Serial.begin(115200);
  pinMode(A0, INPUT);
} 


//function to print data at serial port. 

void dado(int count) {
  int mean = 0;
  int med = count % 10; //[POR} resto da divisão: [ENG] will be zero when count is a multiple of 10
  if(med==0){
    while(mean<=10){ //[POR] tirando a média de dez valores com motor parado //[ENG] calculates mean of ten bit of data taken with the motor stopped
      result = result + float(analogRead(A0));
      mean++;
    }
    Serial.println(result/10.); //prints mean at the serial port
    result = 0; //resets variable
    return;
  }else{
    return;
  }
}

 
void loop() { 

  switch(_step){ //each half step of the motor
    case 0: 
      digitalWrite(Pin1, LOW);  
      digitalWrite(Pin2, LOW); 
      digitalWrite(Pin3, LOW); 
      digitalWrite(Pin4, HIGH); 
    break;  
    case 1: 
      digitalWrite(Pin1, LOW);  
      digitalWrite(Pin2, LOW); 
      digitalWrite(Pin3, HIGH); 
      digitalWrite(Pin4, HIGH); 
    break;  
    case 2: 
      digitalWrite(Pin1, LOW);  
      digitalWrite(Pin2, LOW); 
      digitalWrite(Pin3, HIGH); 
      digitalWrite(Pin4, LOW); 
    break;  
    case 3: 
      digitalWrite(Pin1, LOW);  
      digitalWrite(Pin2, HIGH); 
      digitalWrite(Pin3, HIGH); 
      digitalWrite(Pin4, LOW); 
    break;  
    case 4: 
      digitalWrite(Pin1, LOW);  
      digitalWrite(Pin2, HIGH); 
      digitalWrite(Pin3, LOW); 
      digitalWrite(Pin4, LOW); 
    break;  
    case 5: 
      digitalWrite(Pin1, HIGH);  
      digitalWrite(Pin2, HIGH); 
      digitalWrite(Pin3, LOW); 
      digitalWrite(Pin4, LOW); 
    break;  
    case 6: 
      digitalWrite(Pin1, HIGH);  
      digitalWrite(Pin2, LOW); 
      digitalWrite(Pin3, LOW); 
      digitalWrite(Pin4, LOW); 
    break;  
    case 7: 
      digitalWrite(Pin1, HIGH);  
      digitalWrite(Pin2, LOW); 
      digitalWrite(Pin3, LOW); 
      digitalWrite(Pin4, HIGH); 
    break;  
    default: 
      digitalWrite(Pin1, LOW);  
      digitalWrite(Pin2, LOW); 
      digitalWrite(Pin3, LOW); 
      digitalWrite(Pin4, LOW); 
    break;  
  } 
  
  if(dir){ //continues loop in chosen direction
    _step++; 
  }else{ 
    _step--;
  } 
  
  if(_step>7){ //continues loop in chosen direction
    _step=0; 
    count++; 
    dado(count); //collects data if count a multiple of 10, ie, every 80 steps
  } 
  if(_step<0){ //continues loop in chosen direction
    _step=7; 
    count++;
    dado(count);
  }  
  delayMicroseconds(700); //delay between steps: establishes the speed of the motor. Doesn't work for values lower that 560.
  
}
