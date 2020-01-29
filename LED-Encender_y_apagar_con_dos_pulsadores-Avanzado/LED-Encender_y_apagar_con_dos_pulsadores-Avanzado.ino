//ENCENDER Y APARGAR LED CON 2 PULSADORES
//
//con el primer pulsador enciende el led
//con el segundo pulsador se apaga el led
//
//AVANZADO:
//si el led esta encendido y pulso el pulsador1 el led parpadea
//si el led esta apagado y pulso el pulsador2 el led parpadea
//
//------------------------
//
//
//DECLARACION DE VARIABLES
//-------------------------
int led=13;        //le damon un nombre al pin 13 mas concretamente led
int pulsador1=2;  //le damos un nombre al pin 2 mas concretamente pulsador1
int pulsador2=4;    //le damos un nombre al pin 3 mas concretamente pulsador2
int aux2=8;
int aux=aux2;
//-------------------------
//
//
//FUNCION PRINCIPAL
//-------------------------
void setup(){    //se ejecuta cada vez que el arduino se ejecuta
  pinMode(led,OUTPUT);      //configuro led como salida
  pinMode(pulsador1,INPUT);  //confiduro pulsador1 como entrada
  pinMode(pulsador2,INPUT);  //configuro pulsador2 como entrada
}
//-------------------------
//
//
//FUNCION CICLICA
//-------------------------
void loop(){    //esta funcion se mantiene ejecutando
  if(digitalRead(pulsador1)==HIGH){  //si el pulsador1 esta en alto
    digitalWrite(led,HIGH);   //encender led
    delay(300);
  }//fin del if
  else if(digitalRead(pulsador2)==HIGH){  //si el pulsador2 esta en alto
    digitalWrite(led,LOW);    //apago el led
    delay(300);
  }//fin del else if
//-------------------------
if(digitalRead(led)==HIGH and digitalRead(pulsador1)==HIGH){ //si el led esta encendido y pulso el pulsador1
  while(aux>=0){ // bucle para parpadear
    digitalWrite(led,LOW); //apago el led
    delay (200);       //espero 200ms
    digitalWrite(led,HIGH);//enciendo el led
    delay (200); //espero 200ms
    aux=aux-1; //resta para contar el numero de parpadeos
    }//fin del while
  aux=aux2;//reinicio el contador de pulsos
}//fin del if
else if(digitalRead(led)==LOW and digitalRead(pulsador2)==HIGH){ //si el led esta apagado y pulso el pulsador2
  while(aux>=0){// bucle para parpadear
    digitalWrite(led,HIGH);//enciendo el led
    delay (200);    //espero 200ms   
    digitalWrite(led,LOW);//apago el led
    delay (200);//espero 200ms
    aux=aux-1;//resta para contar el numero de parpadeos
    }//fin del while
  aux=aux2;//reinicio el contador de pulsos
}//fin del else if
}//fin del void
//-------------------------
//FIN PROGRAMA
