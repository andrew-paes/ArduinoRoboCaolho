
int potenciometro;

void setup()
{
Serial.begin(9600);
}

void loop()
{
potenciometro = analogRead(0);
Serial.println(potenciometro);
delay(50);

}
