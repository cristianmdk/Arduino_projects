//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int led = 13; //Pin donde se encuentra el LED, salida
char leer; //Variable donde se almacena la letra
boolean prendido=false; //Estado LED la primera vez, apagado
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
Serial.begin(9600); //Inicia comunicación serial
pinMode(led, OUTPUT); //Configurar el LED como una salida
}
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{ // cuando este energizado el Arduino
//Guardar en una variable el valor de la consola serial
leer=Serial.read();
// Si es la letra 'a' y además el LED está apagado
if ( (leer=='a') && (prendido==false) )
{
digitalWrite(led,HIGH); // Enciende el LED
prendido=true; // Actualiza el estado del LED
}
// Si es la letra 'a' y además el LED está encendido
else if ( (leer=='a') && (prendido==true) )
{
digitalWrite(led,LOW); // Apaga el LED
prendido=false; // Actualiza el estado del LED
}
}
//Fin programa
