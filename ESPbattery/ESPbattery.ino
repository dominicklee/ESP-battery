//Written by Dominick Lee
//Last revision 11/11/2018
//Published under MIT License

int R1 = 33000;  //fixed ohms
int R2 = 7500; //fixed ohms
float knownVolts = 0.775; //the higher the voltage, higher Vbatt output
int knownRaw = 818;	//known raw ADC value at knownVolts
float Vbatt = 0;	//output variable
float battPercent = 0;	//output variable

void setup() {
  Serial.begin(115200);	//start serial
}

void loop() {
  int rawLevel = analogRead(A0);	//get raw ADC (from 0~1023)
  Vbatt = (((knownVolts / (knownRaw / 1023.0)) * (rawLevel / 1023.0)) * (R1 + R2)) / R2;	//our magical equation
  battPercent = (-488.9356452 / (Vbatt - 6.169904932)) - 147.9167234;   //battery discharge curve (your battery may vary)
  battPercent = constrain(battPercent, 0, 100);	//make sure our battPercent is not going negative or beyond 100

  //show the results
  Serial.print(Vbatt);
  Serial.print("V \tBatt % ");
  Serial.println(battPercent);
  delay(1000);
}
