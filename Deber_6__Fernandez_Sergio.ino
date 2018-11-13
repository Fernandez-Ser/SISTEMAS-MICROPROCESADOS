/*
 *           UNIVERSIAD TECNICA DEL NORTE
 *         FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 * Nombre: Fernandez Sergio Rolando
 * Fecha: 13/11/2018
 * 
 * Realizar el conteo de las vocales en una palabra
 */
String palabra; // variable de almacenamiento de la palabra
int tam;  // variable para tamaño del String
int i=0; // variable conteo tamaño de palabra
int cont=0; // de aumento segun las vocales
char a; // almacenamiento de la palabra para una comparacion

void setup() {
  Serial.begin(9600); // configuracion se serial 
}

void loop() {
  if(Serial.available()>0){ 
    palabra= Serial.readString(); // leemos la palabra de entrada por serial
    tam= palabra.length(); //tamaño de la palabra
     
    for(;i<tam;i++){   //ciclo de conteo segun el numero de palabras
       a=palabra.charAt(i); // almacenamiento de la palabra para una comparacion 
      if( a=='a' || a=='e'|| a=='i'|| a=='o'|| a=='u')  // comparaciones anidadas para encontrar las vocales
      {
      cont=cont+1;    // aumenta la variable segun las vocales encontradas
      }}
Serial.println(cont); // imprimimos el valor numero de vocales
i=0; //inicializacion de variable
cont=0; //inicializacion de variable
}}
