//function to print data at serial port.

void dado() {
  
  int med = count % dist_dados; //resto da divisão: will be zero when count is a multiple of media
  float result = 0;
  
  if(med==0){
    for(int m=1; m<=media; m++){ //tirando a média de #media valores com motor parado
      result = result + float(analogRead(A0));
    }
    Serial.print(count); //imprime em qual _step (meio-passo) está
    Serial.println(result/media); //imprime dados de fato
    num_dados++;    
  }else{
    return;
  }
  
}
 
