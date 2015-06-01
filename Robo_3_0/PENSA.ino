void pensa()
{
  int distanciaD = 0;
  int distanciaE = 0;
  
delay(500);
meuServo.write(ServoDireita);
delay(500);
sonar();
distanciaD = distancia;
 
meuServo.write(ServoEsquerda);
delay(500);
sonar();
distanciaE = distancia;

meuServo.write(ServoCentro);

if (distanciaD > distanciaE)
{
direita();
}

if (distanciaE > distanciaD)
{
esquerda();
}

}
