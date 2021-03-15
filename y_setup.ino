void setup() { 
  pinMode(Pin1, OUTPUT);  
  pinMode(Pin2, OUTPUT);  
  pinMode(Pin3, OUTPUT);  
  pinMode(Pin4, OUTPUT);
  Serial.begin(115200);
  pinMode(A0, INPUT);
  initializeLVP();
  Serial.print("Setup ok");
} 
