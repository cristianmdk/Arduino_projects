//------------------------------------
//Funcion principal
//------------------------------------
//para una resistencia de 25K
//
//------------------------------------
int resistencia=A0;
float voltaje;
int valor;

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
 //Guardar en una variable entera el valor del potenciómetro 0 a 2560
 valor= analogRead(resistencia);
 valor= map(valor,0,1023,0,2560); //Usamos la funcion map para cambiar el rango de entrada de 0-1023 a 0-2560 (el rango que soporta analogWrite)
 
 
 voltaje = valor* (5.0 / 2560);
 //Imprime en la consola serial el valor de la variable
 Serial.print("Valor Resistencia: ");   //Imprime el texto que esta entre las comillas
 Serial.print(valor);//Imprime el la variable "VALOR" (10 bit's)
 Serial.print("\t");
 Serial.print("Valor Tension: ");
 Serial.println(voltaje);
 

delay(100);//Retardo para la visualización de datos en la consola
 
}
//Fin programa

