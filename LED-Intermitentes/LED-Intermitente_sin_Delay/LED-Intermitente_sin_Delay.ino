//
//APAGAR Y ENCENDER UN LED sin delay()
//
//Utiliza el pin 13 que incorpora una resistencia para 
//encender y apagar el LED.
//
// Le damos un nombre al pin 13, concretamente led

/* Parpadeo sin delay()
Enciende y apaga un LED conectado a un pin digital sin utilizar la función delay(). Esto significa que otro código se puede ejecutar al mismo tiempo sin ser interrumpido por el código que controla el parpadeo del LED
Circuito: Un LED conectado entre el pin 13 y el pin GND.
Nota: en muchos Arduinos hay un LED en la placa conectado al pin 13, por lo que no sería necesario un LED externo para este ejemplo.
Creado en 2005 por David A. Mellis, modificado el 8/2/2010 por Paul Stoffregen.
Este ejemplo es de dominio público*/

// las constantes no cambian. Las usamos aquí para establecer los números de los pines.
int ledPin = 13;   // el número del pin conectado al LED

//  variables que cambiarán de valor.
int ledState = LOW;   // ledState se usará para establecer el estado del LED

long previousMillis = 0;   // almacenará la última vez que el estado del LED
//se actualizó

// la siguiente variable es del tipo long por que el tiempo medido en
// milisegundos supera rápidamente al número que puede ser almacenado en una
// variable del tipo int
long interval = 1000;   // intervalo del parpadeo (en milisegundos)

void setup() 
{
// establece el pin digital como salida:
pinMode(ledPin, OUTPUT);
}

void loop()
{
// Aquí es donde pondríamos el código que debe ejecutarse durante todo el
// tiempo.

// Se comprobará si es el momento de parpadear el LED, esto es, si la
// diferencia entre el tiempo transcurrido y el tiempo en que parpadeó
// por última vez el LED es mayor que el intervalo que establecimos en
// la declaración de variables.

unsigned long currentMillis = millis();    // Se toma el tiempo actual

// se comprueba si el tiempo actual menos el tiempo en que el LED cambió
// de estado por última vez es mayor que el intervalo.
if (currentMillis - previousMillis > interval){

// Si se cumple la condición se guarda el nuevo tiempo
// en el que el LED cambia de estado
previousMillis = currentMillis;

// Y ahora cambiamos de estado el LED, si está encendido a
// apagado o viceversa.
if (ledState == LOW)
ledState = HIGH;
else
ledState = LOW;

// Hacemos que el contenido de la variable llegue al LED
digitalWrite(ledPin, ledState);
}
}
