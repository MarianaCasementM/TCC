void var_varr(){

  media = 1; //força cada varredura a não fazer uma média de medidas
  num_varr = 0;
  
  for(num_varr >= total_varr){

    //roda uma varredura e conta ela
    uma_var();
    num_varr++;

    //inverte a direção
    if((hor0anti1%2) == 1){ 
      hor0anti1 = 0; 
    }else if((hor0anti1%2) == 0) { 
      hor0anti1 = 1;
    }

    for(byte i=1; i<=10; i++){
      Serial.println(num_varr);
    }
    
  }
 
}
