/*
 *                       UNIVERSIDAD TECNICA DEL NORTE 
 *                  FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 * Nombre: Fernanddez Sergio
 * Fecha:05/02/2019
 *                                Deber
 *  Tema:Programa que permita poner al sistema 19 segundos en modo sleep, se despierte, 
 *  realice un lectura del conversor análogo digital, lo imprima por comunicación serial 
 *  y vuelva a dormir 19 segundos.
 */
#include <LowPower.h> //libreria LowPower
int contador = 0;  // Variable de conteo
int valor=0; //Variable para el analogo
void setup() {
  Serial.begin(9600); //Inicializacion de CX
  }

void loop(){
  for (; contador>=19;contador++) {  //conteo y aumento del contador
       LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); // levantar al sistema
  }
   if(contador==19){
   Serial.println("SISTEMA DESPIERTO"); // Mensaje a imprimir
   valor=analogRead(A0); //lee el valor analogo
   Seril.println(valor); // imprimi el valor analogo
   contador=0; // inicializacion del contador
   }
  delay(200);
   }

