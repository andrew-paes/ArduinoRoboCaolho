// CONECTE OS PINOS DO BLUETOOTH AOS PINOS 2 E 4 DO ARDUINO CONFORMA A TABELA ABAIXO

//  BLUETOOTH       ARDUINO
//     TX            PINO 4
//     RX            PINO 2
//***********************************************************************************



#include <SoftwareSerial.h>  // biblioteca que permite "criar" mais portas seriais

char dados = '0';

SoftwareSerial Bluetooth(4, 2); // RX, TX inicializa modulo Bluetooth 

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.println("Digite F, R, D ou E para executar as rotinas de teste do Robo!");
  Serial.println("");
}

void loop()
{
if (Serial.available() > 0)  // Se receber dados 
{
dados = Serial.read();   // "guarda" o que recebeu na variavel dados"
}


if (Bluetooth.available() > 0)  // Se receber dados 
{
dados = Bluetooth.read();   // "guarda" o que recebeu na variavel dados"
}



if (dados == 'F')
{
frente();
Serial.println("Frente");
delay(1000);
}

if (dados == 'R')
{
re();
Serial.println("Re");
delay(1000);
}

if (dados == 'D')
{
direita();
Serial.println("Direita");
delay(1000);
}

if (dados == 'E')
{
esquerda();
Serial.println("Esquerda");
delay(1000);
}



pare();  // para o robô


dados = '0'; // "limpa" variavel.


}// fim do loop








// SUB ROTINAS
void pare()
{
digitalWrite(3,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(9,LOW);
}

void frente()
{
digitalWrite(3,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(9,HIGH);
}

void re()
{
digitalWrite(3,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(9,LOW);
}


void direita()
{
digitalWrite(3,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(9,LOW);
}

void esquerda()
{
digitalWrite(3,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(9,HIGH);
}
