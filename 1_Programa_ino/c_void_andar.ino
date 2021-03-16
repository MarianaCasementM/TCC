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
}
