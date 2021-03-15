//function to print data at serial port.

int dado() {
  
  int med = count % dist_dados; //resto da divisão: will be zero when count is a multiple of media
  float result = 0;
  if(med==0){
    for(int mean=1; mean<=media; mean++){ //tirando a média de #media valores com motor parado
      result = result + float(analogRead(A0));
    }
    Serial.println(result/media); //imprime dados de fato
    num_dados++;
    return num_dados; //volta para o void loop() com novo valor de num_dados
  }else{
    return num_dados;
  }
  
}
 
