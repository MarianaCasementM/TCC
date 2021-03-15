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
//More modifications last made on 21/02/2021 by Mariana Casement.
//*/  

//global variables

byte Pin1 = 8; 
byte Pin2 = 9; 
byte Pin3 = 10; 
byte Pin4 = 11; 
byte _step = 0; 
byte hor0anti1 = 0;// 0=clockwise, 1=counter clockwise
int vel = 570; //minimum 570
int max_step_val = 5000000; //maximum number of steps so that micrometer does not get to end of course (do not know yet, might vary)

byte pare = 0; //se for diferente de 0, para o motor

int total_dados = 50000; //quantos dados a tomar
byte dist_dados = 1; //quantos _step entre cada registro de um dado
byte media = 10; //quantas medidas tomar antes de tirar média a cada dado
int num_dados = 0; 
int count = 0;






//old tests

// tentando salvar dados em .csv (que se tornou inútil ao utilizar o programa em .py
//String dataLabel1 = "count";
//String dataLabel2 = "Intensidade";
//bool label = false; //para o arquivo csv ter labels: true
  
  //Serial.println(count);

  //collecting data from photodiode (tentativa de salvar em .csv)

  //print out labels of each column
    //while(label){ //runs once
        //Serial.print(dataLabel1);
        //Serial.print(",");
        //Serial.println(dataLabel2);
        //label=false;
    //}
  //if (count<= 47000) { //queremos medir 46080 passos
  //}
    //result = analogRead(A0); //leitura da medição
    //Serial.print(count); //se quiser mais dados num arquivo .csv
    //Serial.print(",");
    //Serial.println(result);
  
}
