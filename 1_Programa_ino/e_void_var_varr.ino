void var_varr(){

  media = 1; //força cada varredura a não fazer uma média de medidas
  num_varr = 0;
  
  while(num_varr < total_varr){

    //roda uma varredura e conta ela
    uma_varr();
    num_varr++;

    //inverte a direção
    if(dir == 1){ 
      dir = 0; 
    }else if(dir == 0) { 
      dir = 1;
    }

    Serial.print("varredura finalizada:");
    Serial.println(num_varr);
    
  }
 
}
