#include <LVP.h>

const word baudRate = 115200;
const byte numEditableData = 20;
const byte numFunctions = 10;

LVP lvp(numEditableData,numFunctions,baudRate);

void initializeLVP(){
  lvp.initialize(); 

  lvp.addFunction("media", &uma_varr);
  lvp.addFunction("dado_media", &dado);
  lvp.addFunction("andar", &andar);
  //lvp.addFunction("varreduras", &var_varr);
  lvp.addParameter("In1", &Pin1);
  lvp.addParameter("In2", &Pin2);
  lvp.addParameter("In3", &Pin3);
  lvp.addParameter("In4", &Pin4);
  lvp.addParameter("vel", &vel);
  lvp.addParameter("pare", &pare);  
  lvp.addParameter("dir_rot", &hor0anti1);
  lvp.addParameter("dad_no_tot", &total_dados);
  lvp.addParameter("pass_entr_dad", &dist_dados);
  lvp.addParameter("med_qnt_dad", &media);
  //lvp.addParameter("qnt_pass_poss", &max_step_val);
  //lvp.addParameter("qual_step", &_step);
  //lvp.addParameter("qnt_dad_ja", &num_dados);
  //lvp.addParameter("qnt_pass_ja", &count);
} 

void serialEvent(){ 
  lvp.getNewCommand();
} 
