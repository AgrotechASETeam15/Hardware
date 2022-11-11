float sensorlevel1;

void setup() {
  Serial.begin(9600);
}

void dripIrrigation() {
  int sensorvalue1 = analogRead(A3);
  Serial.println(sensorvalue1);
  sensorlevel1 = (sensorvalue1/577.00)*100;
  Serial.print("Moisture : "); 
  Serial.println(sensorlevel1); 
  Serial.print("\n");
  if(sensorlevel1 >= 50.00){ 
      Serial.print("Solenoid Valve 1 Open \n");
  }else{ 
      Serial.print("Solenoid Valve 1 Close \n");
  }   
}

void loop() {
  dripIrrigation();
}
