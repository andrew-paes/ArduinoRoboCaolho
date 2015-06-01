
void setup()
{
  pinMode(13,OUTPUT);
Serial.begin(9600);
Serial.flush();

}

void loop()
{

if (analogRead(0)>700)
{ 
digitalWrite(13,LOW);
}
else
{
digitalWrite(13,HIGH);
}
Serial.println(analogRead(0));
delay(200);
}
