//------------------------------------
//Funcion principal
//------------------------------------
int resistencia=A0;

void setup() // Se ejecuta cada vez que el Arduino se inicia
{
 pinMode(resistencia,INPUT);
 Serial.begin(9600); //Inicia comunicación serial
}
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando 
{ // cuando este energizado el Arduino
 //Guardar en una variable entera el valor del potenciómetro 0 a 1024
 int valor= analogRead(resistencia);
 //Imprime en la consola serial el valor de la variable
 Serial.println(valor);
 //Retardo para la visualización de datos en la consola
 delay(100);
}
//Fin programa

