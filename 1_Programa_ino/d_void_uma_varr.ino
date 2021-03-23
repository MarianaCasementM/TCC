void uma_varr(){

  num_dados = 0;

  while(num_dados < total_dados){
    //Se valor de count maior que limite o programa para de rodar
    if(count > max_step_val){
      return;
    }

    //entra com o número do _step, coloca motor nas fases correspondentes
    andar(); 
    count++; //number of half-steps given

    //entra com alguns valores, pega um valor do sinal, escreve na porta serial e retorna com novo num_dados
    dado();

    //delay to establish speed of motor
    if (vel < 565){
      Serial.println("vel nao pode ter um valor abaixo de 570, por favor insira um valor valido");
      return;
    }else{
      delayMicroseconds(vel); //min 562 or not?got it to 560... 
    }
  
  }
 
}
