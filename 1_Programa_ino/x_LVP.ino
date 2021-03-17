#include <LVP.h>

const word baudRate = 115200;
const byte numEditableData = 20;
const byte numFunctions = 10;

LVP lvp(numEditableData,numFunctions,baudRate);

void initializeLVP(){
  lvp.initialize(); 

  lvp.addFunction("medias", &uma_varr);
  lvp.addFunction("varreduras", &var_varr);
//  lvp.addFunction("dado_media", &dado);
//  lvp.addFunction("andar", &andar);
  lvp.addParameter("vel", &vel);
  lvp.addParameter("pare", &pare);  
  lvp.addParameter("dir", &hor0anti1);
  lvp.addParameter("d_total", &total_dados);
  lvp.addParameter("dist_d", &dist_dados);
  lvp.addParameter("media_qnt_d", &media);
  lvp.addParameter("qnt_varr", &total_varr);
  //lvp.addParameter("qnt_pass_poss", &max_step_val);
  //lvp.addParameter("qual_step", &_step);
  //lvp.addParameter("qnt_dad_ja", &num_dados);
  //lvp.addParameter("qnt_pass_ja", &count);
} 

void serialEvent(){ 
  lvp.getNewCommand();
} 
