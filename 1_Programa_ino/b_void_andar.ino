//code that comands motor at each half-step

void andar() {
  
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

  //aumenta ou diminui o valor de _step para que passe para a próxima posição, que vai depender da direção estabelecida
    if(dir == 1){ 
      _step++; 
    }else if(dir == 0) { 
      _step--;
    }else{
      Serial.println("Por favor insira um valor valido: 0 ou 1.");
      return;
    }

    //recomeça o valor de _step ao final de um ciclo
    if(_step>7){ 
      _step=0; 
    } 
    if(_step<0){ 
      _step=7; 
    }  
}
