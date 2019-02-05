/* 
 *                  UNIVERSIDAD TECNICA DEL NORTE 
 *                  FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 * Nombre: Fernanddez Sergio
 * Fecha:05/02/2019
 *                     Deber
 * Tema:Sistema que permita configurar por comunicación serial o por pulsadores el modo sleep cada 25 segundos.
 */
#include <LowPower.h> //libreria LowPower
int contador = 0;  // Variable de conteo
void setup() {
  Serial.begin(9600); //Inicializacion de CX
  attachInterrupt(0,sistema,FALLING); //Interrupcion con metodo
  }

 void loop() {
     //FUNCIONAMIENTO CON INTERRUPCION
  }
void sistema() {
  for (; contador>=25;contador++) {  //conteo y aumento del contador
       LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); // levantar al sistema
  }
   if(contador==25){
   Serial.println("SISTEMA DESPIERTO"); // Mensaje a imprimir
   contador=0; // inicializacion del contador
   }
  delay(200);
   }
