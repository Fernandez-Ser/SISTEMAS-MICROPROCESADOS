/*             UNIVERSIDAD TECNICA DEL NORTE
 *         FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 *                    LABORATORIO
 *    Integrantes: Cuascota Henry
 *                 Fernandez Sergio
 *                 Ichau Alexander
 *    Fecha:8/11/2018
 *    
 *    Tema: Contador de personas automático.
 * 
 */
 int A=5; // pin de salida para display
int B=4; // pin de salida para display
int C=3; // pin de salida para display
int D=2; // pin de salida para display
int entrando=12; // aviso led de entrada
int salida=13; // aviso led de salida
int reset=8; //  boton de reset
int i=0;  //variable de aumento
int decenas; // almacenamiento de las decenas
int unidades; // almacenamiento de las unidades
int dec=7; // pin de acitivacion de display decenas
int uni=6;  // pin de activacion unidades
int ldr1=A0; // sensor ldr1
int ldr2=A1; // sernsor ldr2
int vldr1=0; // lectura del valor en ldr1
int vldr2=0; // lectura del valor en ldr2
int en=0;  
int sal=0;
int r=0; // alamcenamiento ldr2
int s=0; //alamcenamiento ldr1
int r1=0; // alamcenamiento ldr2
int s1=0; //alamcenamiento ldr1
void setup() {
  Serial.begin(9600);
 pinMode(A,OUTPUT); // configuracion de pin
 pinMode(B,OUTPUT); // configuracion de pin
 pinMode(C,OUTPUT); // configuracion de pin
 pinMode(D,OUTPUT); // configuracion de pin
 pinMode(entrando,OUTPUT); //led de entrada o aumento
 pinMode(salida,OUTPUT); // led de salida
 pinMode(reset,INPUT);  // configuracion de pin COMO ENTRAA
pinMode(dec,OUTPUT); // configuracion de pin
pinMode(uni,OUTPUT); // configuracion de pin
}

void loop() {
  
vldr1=(analogRead(ldr1)*9)/1024; // leemos el valor analogo y convertimos a un voltaje mas bajo
vldr2=(analogRead(ldr2)*9)/1024; // leeos el valor analogo y convertimos a un voltaje mas bajo
 s=vldr1; //alamacenamos el valor analogo
 r=vldr2; //alamacenamos el valor analogo
  s1=vldr1;//alamacenamos el valor analogo
 r1=vldr2;//alamacenamos el valor analogo
  //--------------------------incremento
  if(s<3){ //condicion de comparacion
    en=1; //igualdad al cumplir la condicion
    sal=0;//igualdad al cumplir la condicion
         }
  if(en==1 & r<3) { //condicion anidada para el aumento del contador
        i++;  // aumenta en 1 el contador 
        digitalWrite(entrando,HIGH); // led de aumento de contador en alto
        delay(200);
        digitalWrite(entrando,LOW); // led de aumento de contador en bajo
        en=0;
                  }
                  r=0;
//---------------------------disminuye
if(r1<3){  //condicion de comparacion
    en=0; //igualdad al cumplir la condicion
    sal=1; //igualdad al cumplir la condicion
         }
  if(sal==1 & s1<3) { // condicion anidada para disminucion
        i--; // disminucion  del contador en -1
        digitalWrite(salida,HIGH); // led de disminucion de contador en alto
        delay(200);
        digitalWrite(salida,LOW); //led de disminucion de contador en bajo
        sal=0;
    
    }
    s1=0;
 


     if(i<51){  // condicion del conteo
       decenas=i/10;  // valor de decenas
       unidades= i-(decenas*10); // valor unidades
       }
   
    if(digitalRead(reset)==HIGH){ // el pulsador de reinicio del conteo
      i=0; //conteo se reinicia.
    }
      
 digitalWrite(uni,HIGH); // activacion de pin de unidades
 digitalWrite(dec,LOW);  // desactivacion de pin de decenas
 contador(unidades);    // llamo metodo de visualizacion
 delay(100);  // espero
 
 digitalWrite(uni,LOW);   // desactivacion de pin de unidades
 digitalWrite(dec,HIGH);  // activacion de pin de decenas
 contador(decenas);  // llamo metodo de visualizacion
 delay(100); // espero
}

void contador (int j){
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
