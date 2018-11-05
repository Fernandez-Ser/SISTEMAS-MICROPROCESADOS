/*
 *               UNIVERSIDAD TECNICA DEL NORTE
 *           FICA-CIERCOM-SISTEMAS MICROPROCESADOS 
 * Nombre: Fernandez Sergio Rolando
 * Fecha: 06/11/2016
 * 
 * Realizar un programa que medienta un pulsador se aumente el valor de un contador (1 al 40) 
 * y mediante otro pulsador se reste ese valor.
 */

int A=5; //pin 5 como salida para el display
int B=4; //pin 4 como salida para el display
int C=3; //pin 3 como salida para el display
int D=2; //pin 2 como salida para el display
int uni=6; //pin 6 como salida para activacion del display unidades
int dec=7; //pin 7 como salida para activacion del display decenas
int unidades; //variable de almacenamiento de unidades
int decenas; //variable de almacenamiento de decenas
int aum=8; //pulsador de aumento
int decrem=9;// pulsador de decremento
int i=0; //Variable de incremento y decremento
void setup(){
 pinMode(A,OUTPUT); //configuracion del pin 5 como salida.
 pinMode(B,OUTPUT); //configuracion del pin 4 como salida.
 pinMode(C,OUTPUT); //configuracion del pin 3 como salida.
 pinMode(D,OUTPUT); //configuracion del pin 2 como salida.
 pinMode(uni,OUTPUT); //configuracion del pin 6 como salida para activacion del display de unidades 
 pinMode(dec,OUTPUT); //configuracion del pin 7 como salida para activacion del display de decenas
 pinMode(aum,INPUT); //configuracion del pin 8 como entrada.
 pinMode(decrem,INPUT); // configuracion del pin 9 como entrada.
}

void loop(){
  if(digitalRead(aum)==HIGH){  //condicion de funcionamiento del pin de aumento.
    delay(200); //  delay antirebotes
    if(i<40){  //establecemos un limite de conteo que llegue al 40
     i++;      //la variable de incremento. 
     decenas= i/10; //valor que va a tomar el display de las decenas.
     unidades= i-(decenas*10); //valor que va a tomar el display de las unidades.  
  }
   else{
    i=0; // se resetea la variable de incremento 
    unidades=0; //se resetea la variable de almacenamiento de las unidades.
    decenas=0;  //se resetea la variable de almacenamiento de las decenas.
    }}
    
   if(digitalRead(decrem)==HIGH){ // condicion de la variable de decremento.
    delay(200);
    i--;       //la variable de que va decreciendo. 
    decenas= i/10; //valor que va a tomar el display de las decenas.
    unidades= i-(decenas*10); //valor que va a tomar el display de las unidades.  
   }
 
 digitalWrite(uni,HIGH); //activacion del pin de unidades.
 digitalWrite(dec,LOW); //desactivacion del pin de decenas.
 displ(unidades);       //llamamos al metodo.
 delay(50);  
 
 digitalWrite(uni,LOW);   //desactivacion del pin de unidades.
 digitalWrite(dec,HIGH); //activacion del pin de decenas.
 displ(decenas);         //llamamos al metodo.
 delay(40);
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
