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
//More modifications last made on 14/11/2020 by Mariana Casement.
//*/  


int Pin1 = 8; 
int Pin2 = 9; 
int Pin3 = 10; 
int Pin4 = 11; 
int _step = 0; 
boolean dir = true;// false=clockwise, true=counter clockwise
int count = 0;
float result = 0;

// tentando salvar dados em .csv (que se tornou inútil ao utilizar o programa em .py
//String dataLabel1 = "count";
//String dataLabel2 = "Intensidade";
//bool label = false; //para o arquivo csv ter labels: true

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
  int med = count % 10; //resto da divisão: will be zero when count is a multiple of 10
  //Serial.print("medida #"); 
  //Serial.println(count); //verificar o valor de count
  if(med==0){
    //Serial.print("mean:");
    //Serial.println(mean); //verificar o valor de mean
    while(mean<=10){ //tirando a média de dez valores com motor parado
      result = result + float(analogRead(A0));
      //Serial.println(result);
      mean++; //mean=mean+1
    }
    //Serial.print("res:");
    Serial.println(result/10.); //imprime dados de fato
    result = 0; //reinicializa valor
    return; //volta para o void loop()
  }else{
    return;
  }
}
 
void loop() { 

  switch(_step){ 
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
  
  if(dir){ 
    _step++; 
  }else{ 
    _step--;
  } 
  
  if(_step>7){ 
    _step=0; 
    count++; 
    dado(count);
  } 
  if(_step<0){ 
    _step=7; 
    count++;
    dado(count);
  }  
  delayMicroseconds(700); //min 562 or not?got it to 560... 
  
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
