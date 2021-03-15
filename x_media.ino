void uma_varr(){

  for(num_dados >= total_dados){
    //Se valor de pare for diferente de 0, count maior que limite ou  programa para de rodar
    if(pare != 0 || count > max_step_val){
      delay(5);
      return;
    }

    //entra com o número do _step, coloca motor nas fases correspondentes
    andar(); 

    //entra com alguns valores, pega um valor do sinal, escreve na porta serial e retorna com novo num_dados
    num_dados = dado();
  
    //aumenta ou diminui o valor de _step para que passe para a próxima posição, que vai depender da direção estabelecida
    if((hor0anti1%2) == 1){ 
      _step++; 
    }else if((hor0anti1%2) == 0) { 
      _step--;
    }else{
      Serial.println("Por favor insira um valor valido: 0 ou 1.");
      hor0anti1 = Serial.read();
    }

    //recomeça o valor de _step ao final de um ciclo
    if(_step>7){ 
      _step=0; 
    } 
    if(_step<0){ 
      _step=7; 
    }  

    count++; //number of half-steps given

    //delay to establish speed of motor
    if (vel < 565){
      Serial.println("vel nao pode ter um valor abaixo de 570, por favor insira um valor valido");
      vel = Serial.read();
      delayMicroseconds(570);
    }else{
      delayMicroseconds(vel); //min 562 or not?got it to 560... 
    }
  
  }
 
}
