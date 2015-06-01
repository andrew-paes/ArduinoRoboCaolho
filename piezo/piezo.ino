int piezopin=12; // Define o pino 12 como uma variavel.
int x=200; // Tom.

void setup()
{
  Serial.begin(9600);
}

void loop(){

for(x=200; x<2500;x=x+20){ // rotina de incremento de x.
tone(piezopin, x); // Emite sinal de audio no pino 12 com o tom definido por x.
delay(15); //Pausa 15 Ms.
noTone (piezopin); // Corta o sinal de audio no pino 12.
delay (15); // Pausa 15 Ms.
Serial.println(x);// Imprime o valor de x.
}
x=200;
}
