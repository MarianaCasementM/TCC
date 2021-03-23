void setup() { 
  pinMode(Pin1, OUTPUT);  
  pinMode(Pin2, OUTPUT);  
  pinMode(Pin3, OUTPUT);  
  pinMode(Pin4, OUTPUT);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  initializeLVP();
  Serial.println("Setup ok");
} 
