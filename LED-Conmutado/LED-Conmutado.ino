//LED CONMUTADO
//
//Si el LED esta apagado y pulso el LED se enciende.
//Si el LED esta encendido y pulso el LED se apaga.
//Si mantengo el pulsador presionado el LED parpadea.
//
int ledPin = 13; // pin 13 asignado para el LED de salida
int inPin = 2; // pin 2 asignado para el pulsador

void setup() // Configura entradas y salidas
{
   pinMode(ledPin, OUTPUT); // declara LED como salida
   pinMode(inPin, INPUT); // declara pulsador como entrada
}

void loop()
{
 if (digitalRead(ledPin)==LOW){ // leo el LED para saber si esta apagado
  if (digitalRead(inPin) == HIGH){ // testea si la entrada esta activa HIGH
      digitalWrite(ledPin, HIGH); // enciende el LED
      delay(300); // espera 1 segundo para leer el pulsador
   }
}
 else if (digitalRead(ledPin)==HIGH){ //leo el LED para saber si esta encendido
  if (digitalRead(inPin) == HIGH){ // testea si la entrada esta activa HIGH
      digitalWrite(ledPin, LOW); // enciende el LED
      delay(300); // espera 1 segundo para leer el pulsador
   }
}
}
