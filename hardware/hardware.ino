float sensorlevel1;
const int buzzer = 10;
const int warningLight = 13;
int sensorThres = 150;
int ledPin = 12;
const int dripMotor=8;
int value = 0;
int flag = 0;

void setup()
{
  pinMode(warningLight, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(dripMotor, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(A5, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  digitalWrite(2,LOW);
  Serial.begin(9600);
}
void dripIrrigation()
{
  int sensorvalue1 = analogRead(A3);
  Serial.println(sensorvalue1);
  sensorlevel1 = (sensorvalue1 / 577.00) * 100;
  Serial.print("Moisture : ");
  Serial.println(sensorlevel1);
  Serial.print("\n");
  
  if (sensorlevel1 <= 70.00)
  {
    
    digitalWrite(dripMotor,LOW);
    Serial.print("Solenoid Valve 1 Close \n");
    
  }
  else
  {
   if(flag==0){
     digitalWrite(ledPin,HIGH);
    digitalWrite(dripMotor,HIGH);
    Serial.print("Solenoid Valve 1 Open \n");
   }
   else{
     
     digitalWrite(ledPin,LOW);
     
    digitalWrite(dripMotor,LOW);
   }
    
  }
}
void smokeDetector()
{
  int analogSensor = analogRead(A5);

  Serial.print("Smoke : ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    flag =1;
    digitalWrite(warningLight, HIGH);
    delay(100);
    digitalWrite(warningLight, LOW);
    delay(100);

    tone(buzzer, 1000, 200);
  }
  else
  {
    flag = 0;
    digitalWrite(warningLight, LOW);
    noTone(buzzer);
  }
}

void loop()
{
digitalWrite(ledPin,HIGH);
  dripIrrigation();
  smokeDetector();
}
