float sensorlevel1;
const int buzzer = 10;
const int redLed = 13;
int sensorThres = 80;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
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
  if (sensorlevel1 >= 50.00)
  {
    Serial.print("Solenoid Valve 1 Open \n");
  }
  else
  {
    Serial.print("Solenoid Valve 1 Close \n");
  }
}
void smokeDetector()
{
  int analogSensor = analogRead(A2);

  Serial.print("Smoke : ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    delay(100);
    digitalWrite(redLed, LOW);
    delay(100);

    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  }
}
void loop()
{

  dripIrrigation();
  smokeDetector();
}
