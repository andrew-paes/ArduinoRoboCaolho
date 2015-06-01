int sensorEsquerdo = A0;
int sensorDireito  = A1;
int velocidade = 90;   // ajustar os valores entre 0 (parado) e 255 (velocidade maxima).

// novas variaveis 
int ServoCentro   = 90;
int ServoDireita  = 5;
int ServoEsquerda = 175;

int distancia;
int trig = 11;
int echo = 12;



#include <Servo.h>  // Biblioteca de controle do servo
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>  

Servo meuServo; // Cria o objeto "meuServo"

// Declara valoes dedicados ao display I2C
#define I2C_ADDR    0x3F  // Define Endereço "0X3F" do I2C 
#define BACKLIGHT_PIN  3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
#define  LED_OFF  0
#define  LED_ON  1

// declara pinos
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);  // Pinos Arduino A4 = SDA   e A5 = SCL  Display 


void setup()
{
  Serial.begin(9600);
  Serial.flush();
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  
  meuServo.attach(10); // define o pino 10 para o servo
  
  // Pino do sonar
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
    
  meuServo.write(ServoCentro); // posiciona o sonar a frente 
  
  // Inicialização do display
  lcd.begin (16,2);             // inicializa o lcd 16 colunas x 2 linhas  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.clear();                  // Limpa display 
  lcd.home();                   // Manda o cursor para a posição "zero" 
  lcd.setBacklight(LED_ON);     // Ativa backlight
  lcd.print("  ROBO PRONTO!  ");// Escreve
}

void loop()
{

sonar();

if (distancia >= 30)
{
frente();            // anda para frente 
}

if (distancia < 30)
{
pare();
pensa();
}

delay(200);
lcd.setCursor(0,1);  // posiciona o cursor na linha de baixo.
lcd.print("     FRENTE     ");


if (analogRead(sensorEsquerdo) < 500)  // testa se o sensor foi disparado
{
 lcd.setCursor(0,1); 
 lcd.print(" DESVIO DIREITA ");
}
while (analogRead(sensorEsquerdo) < 500)
{
direita();
}

if (analogRead(sensorDireito) < 500)
{
  lcd.setCursor(0,1);
  lcd.print("DESVIO ESQUERDA ");
}
while (analogRead(sensorDireito) < 500)
{
esquerda();
}
}// fim do loop



