//------------------------------------
//Funcion principal
//para una resitencia de 10K
//------------------------------------
int resistencia=A0;
int led=13;
float voltaje;

void setup() // Se ejecuta cada vez que el Arduino se inicia
{
 pinMode(resistencia,INPUT);
 pinMode(led,OUTPUT);
 Serial.begin(9600); //Inicia comunicación serial
}
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando 
{ // cuando este energizado el Arduino
 //Guardar en una variable entera el valor del potenciómetro 0 a 1024
 digitalWrite (led,LOW);
 int valor= analogRead(resistencia);
 //Imprime en la consola serial el valor de la variable
 
 if(valor < 500)
 digitalWrite(led,HIGH);
 
 voltaje = valor* (5.0 / 1024.0);
 
 Serial.print("Valor Resistencia: ");   //Imprime el texto que esta entre las comillas
 Serial.print(valor);//Imprime el la variable "VALOR" (10 bit's)
 Serial.print("\t");
 Serial.print("Valor Tension: ");
 Serial.println(voltaje);
 //Retardo para la visualización de datos en la consola
 

 delay(100);
 
 
}
//Fin programa

