#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int pinoSensor = 5;                         //pino que está ligado ao LM35 (pino analogico 0)
int valorLido = 0;                          //valor lido na entrada analogica
float temperatura = 0;                      //valorLido convertido para temperatura ºC

void setup() {
  Serial.begin(9600);   //Inicializa comunicação Serial
Serial.flush();
mySerial.begin(9600);
}

void loop() {
  
  valorLido = analogRead(pinoSensor);
  temperatura = (valorLido * 0.00488);       // 5V / 1023 = 0.00488 (precisão do A/D)
  temperatura = temperatura * 100;           //Converte milivolts para graus celcius, 
  Serial.print("Temperatura atual: ");
 mySerial.print("Temperatura Atual: ");
 mySerial.println(temperatura);
  Serial.println(temperatura);
  delay(2000);                               //espera 5 segundos para fazer nova leitura
}

