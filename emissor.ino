const int ledPin = 9;
String mensagen = "00000000";

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}// end setup

void loop() 
{
  if(Serial.available())
  {
    mensagem = Serial.readString();
  }
  else
  {
    digitalWrite(ledPin,HIGH);
  }
  
}// end loop
