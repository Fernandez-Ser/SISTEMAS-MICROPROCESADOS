/*
 *                   Universidad Tecnica del Norte
 *              Fica-Ciercom-Sistemas Microprocesados
 * Nombre: Fernandez Sergio Rolando
 * Fecha:15/01/2019
 * 
 *                           Deber EEPROM
 * Sistema que guarde en una posición de la memoria EEPROM solo cuando 
   su valor exceda a la anterior lectura.
 */
#include <EEPROM.h> //Libreria de la memoria EEPROM
String valor; // variable Valor string de CX
int v_ent=0; // variable para almacenar el entero
int posicion=0; // contador de posicion 
int numero=0; // variale de almacenamiiento del valor
void setup() {
 Serial.begin(9600);  // Conf CX
 for(;posicion<=255;posicion++ ){ // Contador para encerar la memoria EEPROM
     EEPROM.write(posicion,0);
     delay(1);
 }
 posicion=0;//Inicializacion de variable contador
 Serial.println("INGRESE VALOR");// Caracteres a imprimir
 
}
void loop() {
  if(Serial.available()>0){ // habiltacion de comunicacion serial
    valor=Serial.readString(); // alamacena el valor de entrada en string
    v_ent= valor.toInt(); //convierte el String a entero
    numero=v_ent; // almacena el valor entero
    EEPROM.read(posicion); //posicion de la memoria
    if(numero>EEPROM.read(posicion)){ // condicion de funcionamiento
      posicion++; // conteo de posicion;
      EEPROM.write(posicion,numero); // Escribe el numero y la posicion en la memoria EEPROM
      Serial.print(" --> Se guardo el numero: "); // Caracteres a imprimir
      Serial.print(numero); // Valor a imprimir
      Serial.print("--> En la posicion:"); // Caracteres a imprimir
      Serial.println(posicion);// Posicion a imprimir
      Serial.println("Siguiente Valor"); // Caracteres a imprimir
      }
    else{
        Serial.println("-->Numero menor al guardado"); // Caracteres a imprimir
        Serial.println("INGRESE OTRO VALOR");  // Caracteres a imprimir
        }
    if(posicion==255){
      Serial.println("LA MEMORIA ESTA LLENA");
    }
   }
}
