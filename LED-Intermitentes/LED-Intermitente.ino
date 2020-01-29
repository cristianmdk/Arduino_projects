//
//APAGAR Y ENCENDER UN LED
//
//Utiliza el pin 13 que incorpora una resistencia para 
//encender y apagar el LED.
//
// Le damos un nombre al pin 13, concretamente led
int led = 13;
void setup() {               
  // determinamos que nuestra variable led será de salida
  pinMode(led, OUTPUT);    
}

// escribimos el sketch
void loop() {
  digitalWrite(led, HIGH);   // enciende el LED (HIGH)
  delay(1000);               // espera durante un segundo (las unidades son milisegundos)
  digitalWrite(led, LOW);    // apaga el LED haciendo nula la tensión
  delay(1000);               // espera de nuevo un segundo
}
// Fin del programa
