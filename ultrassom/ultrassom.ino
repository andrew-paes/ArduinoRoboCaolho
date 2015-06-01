
double distancia = 0; 
int trig = 11;
int echo = 12;

void setup()
{
pinMode(trig,OUTPUT); // Pino "trig" (gatilho/disparo) do som.
pinMode(echo,INPUT);  // Pino "echo" (eco / retorno) do som.

Serial.begin(9600);
Serial.flush();

}

void loop()
{

digitalWrite(trig,HIGH);  // Dispara um pulso sonoro
delayMicroseconds(10);   // Espera 10 microsegundos
digitalWrite(trig,LOW);  // Desiga pulso
distancia = pulseIn (echo,HIGH);  // Mede o tempo de retorno do pulso usando a funçao "pulseIn" 

//calcula
distancia=distancia * 340; // Multiplica o valor recebido por 340 (340 metros por segundo é a velocidade do som).
distancia=distancia /2; // divide por 2, pois e o tempo do som ir até o obstáculo e voltar
distancia = distancia /10000;// dividimos por 10000 para ter o valor em centimetros (CM).

Serial.print(distancia);
Serial.println(" cm");

delay(500); //Aguarda meio segundo e lê novamente.
}
