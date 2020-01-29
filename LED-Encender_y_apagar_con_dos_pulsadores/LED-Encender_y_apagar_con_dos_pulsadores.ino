//ENCENDER Y APARGAR LED CON 2 PULSADORES
//
//con el primer pulsador enciende el led
//con el segundo pulsador se apaga el led
//
//------------------------
//
//
//DECLARACION DE VARIABLES
//-------------------------
int led=13;        //le damon un nombre al pin 13 mas concretamente led
int pulsador1=2;  //le damos un nombre al pin 2 mas concretamente pulsador1
int pulsador2=4;    //le damos un nombre al pin 3 mas concretamente pulsador2
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
  }
  else if(digitalRead(pulsador2)==HIGH){  //si el pulsador2 esta en alto
    digitalWrite(led,LOW);    //apago el led
  }
}
//-------------------------
//FIN PROGRAMA
