/*
Ejemplo de codigo para un sensor SRF02 con I2C basado en el Arduino UNO
Conecciones:
SRF02       Arduino
5v Vcc    -> 5V
SDA       -> A4
SCL       -> A5
Mode      -> no connection
0v Ground -> GND
*/

#include <Wire.h>               // Libreria para comunicarse con el dispositivo I2C
                                // Uno, Ethernet    A4 (SDA), A5 (SCL)
                                // Leonardo	    2 (SDA), 3 (SCL)

void setup()
{
  Wire.begin();                 // Comunicar con I2C
  Serial.begin(9600);           // El interfaz serie tiene un formato estándar de 9600 baudios
}

int reading = 0;                // variable

void loop()
{
  // step 1: Instrucciones para leer del sensor
  Wire.beginTransmission(112);  // Transmite al dispositico #112 (0x70)
                                // La dirección I2C del medidor SRF02 por defecto es 0xE0 (224)
                                // pero el I2C usa 7 bits en nivel alto asi que es 112.
  Wire.write(byte(0x00));       // Revisión de software interno. Registros de comandos (0x00)
  Wire.write(byte(0x51));       // Iniciar una nueva medición real. Resultado en centímetros (0x51)
                                // 0x52 para iniciar una nueva medición real. Resultado en microsegundos
                                // 0x50 para iniciar una nueva medición real. Resultado en pulgadas
  Wire.endTransmission();       // Paro de transmitir

  // step 2: Espera para que la lectura se lleve acabo
  delay(70);                    // El datasheet sugiere sea mas de 65 millisegundos

  // step 3: Instrucciones del sensor para que devuelva un eco particular
  Wire.beginTransmission(112);  // Transmite al dispositivo #112 (0x70)
  Wire.write(byte(0x02));       // // // // Byte alto de la medidad realizada
  Wire.endTransmission();       // Paro de transmitir

  // step 4: Regreso nuevamente al sensor
  Wire.requestFrom(112, 2);    // Solicito 2 Bytes del dispositivo #112 (0x70)

  // step 5: Resivir la lectura del sensor
  if (2 <= Wire.available())   // Si recibe 2 Bytes...
  {
    reading = Wire.read();     // Byte alto de la medidad realizada (sobreescribe)
    reading = reading << 8;    // Cambiar Bytes alto para que sea de 8 bits
    reading |= Wire.read();    // Byte bajo de la medidad realizada
    Serial.print(reading);     // Escribe en consola
    Serial.println("cm"); 
  }

  delay(250);                  // Espera 250 mili segundos para hacer la siguiente lectura-escritura
}
