/*
 *               UNIVERSIDAD TECNICA DEL NORTE
 *           FICA-CIERCOM-SISTEMAS MICROPROCESADOS 
 * Nombre: Fernandez Sergio Rolando
 * Fecha: 06/11/2016
 * 
 * Sistema de conteo automática(sin pulsador, el sistema inicia y empieza a contar sin necesidad de una actividad del usuario). 
   Del 1 al 200 mediante la multiplexación de displays
 */

int A=5; //pin 5 como salida para el display
int B=4; //pin 4 como salida para el display
int C=3; //pin 3 como salida para el display
int D=2; //pin 2 como salida para el display
int uni=6; //pin 6 como salida para activacion del display unidades
int dec=7; //pin 7 como salida para activacion del display decenas
int cen=8; //pin 8 como salida para activacion del display centenas
int unidades; //variable de almacenamiento de unidades
int decenas; //variable de almacenamiento de decenas
int centenas; //variable de almacenamiento de centenas
int i=0; //Variable de incremento

void setup(){
 pinMode(A,OUTPUT); //configuracion del pin 5 como salida.
 pinMode(B,OUTPUT); //configuracion del pin 4 como salida.
 pinMode(C,OUTPUT); //configuracion del pin 3 como salida.
 pinMode(D,OUTPUT); //configuracion del pin 2 como salida.
 pinMode(uni,OUTPUT); //configuracion del pin 6 como salida para activacion del display de unidades 
 pinMode(dec,OUTPUT); //configuracion del pin 7 como salida para activacion del display de decenas
 pinMode(cen,OUTPUT); //configuracion del pin 8 como salida para activacion del display de centenas
}

void loop(){
    if(i<200){  //establecemos un limite de conteo que llegue a los 200
     i++;       //la variable de incremento.
     centenas=i/100; //valor que va a tomar el display de las centenas. 
     decenas= (i-(centenas*100))/10; //valor que va a tomar el display de las decenas.
     unidades= (i%100)%10; //valor que va a tomar el display de las unidades.  
  }
  
   else{
    i=0; // se resetea la variable de incremento 
    unidades=0; //se resetea la variable de almacenamiento de las unidades.
    decenas=0;  //se resetea la variable de almacenamiento de las decenas.
    centenas=0; //se resetea la variable de almacenamiento de las centenas.
   }
   
 digitalWrite(uni,HIGH); //activacion del pin de unidades.
 digitalWrite(dec,LOW); //desactivacion del pin de decenas.
 digitalWrite(cen,LOW); //desactivacion del pin de centenas.
 displ(unidades);       //llamamos al metodo.
 delay(50);  
 
 digitalWrite(uni,LOW);   //desactivacion del pin de unidades.
 digitalWrite(dec,HIGH); //activacion del pin de decenas.
 digitalWrite(cen,LOW);  //desactivacion del pin de centenas
 displ(decenas);         //llamamos al metodo.
 delay(40);
 
 digitalWrite(uni,LOW);   //desactivacion del pin de unidades.
 digitalWrite(dec,LOW);   //desactivacion del pin de decenas.
 digitalWrite(cen,HIGH);  //activacion del pin de centenas.
 displ(centenas);         //llamamos al metodo.
 delay(50);
  }

void displ (int j){    //Método del número en el display 
switch(j){
  //0
  case 0:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//1
 case 1:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//2
case 2:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//3
case 3:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//4
case 4:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//5
case 5:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//6
case 6:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//7
case 7:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//8
case 8:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
//9
case 9:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
}
}
