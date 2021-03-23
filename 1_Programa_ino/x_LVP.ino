#include <LVP.h>

const word baudRate = 9600;
const byte numEditableData = 6;
const byte numFunctions = 2;

LVP lvp(numEditableData,numFunctions,baudRate);

void initializeLVP(){
  lvp.initialize(); 

  lvp.addFunction("medias", &uma_varr);
  lvp.addFunction("varreduras", &var_varr);
  //lvp.addFunction("dado_media", &dado);
  //lvp.addFunction("andar", &andar);
  lvp.addParameter("vel", &vel);
  lvp.addParameter("direcao", &dir);
  lvp.addParameter("dad_total", &total_dados);
  lvp.addParameter("dist_dad", &dist_dados);
  lvp.addParameter("media_qnt_d", &media);
  lvp.addParameter("qnt_varred", &total_varr);
  //lvp.addParameter("qnt_pass_poss", &max_step_val);
  //lvp.addParameter("qual_step", &_step);
  //lvp.addParameter("qnt_dad_ja", &num_dados);
  //lvp.addParameter("qnt_pass_ja", &count);
  //lvp.addParameter("pare", &pare);  
} 

void serialEvent(){ 
  lvp.getNewCommand();
} 
