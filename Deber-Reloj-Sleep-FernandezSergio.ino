/* 
 *                      UNIVERSIDAD TECNICA DEL NORTE 
 *                  FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 * Nombre: Fernanddez Sergio
 * Fecha:05/02/2019
 *                                     Deber
 * Tema:Realizar un reloj dentro del arduino con el menor coste computacional 
 *      que se visualiza en una LCD (apagar los periféricos que no se usen).
 */
#include <EEPROM.h>// Libreria Memoria EEPROM
#include <TimerOne.h>//Libreria Timer1
#include <MsTimer2.h>  // Libreria del Timer Dos
#include <LiquidCrystal.h> //Libreria de la LCD
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
int A=13; //variable para LCD
int B=12; //variable para LCD
int C=11; //variable para LCD
int D=10; //variable para LCD
int E=9;  //variable para LCD
int F=8;  //variable para LCD
LiquidCrystal lcd(13,12,11,10,9,8); //  conf  LCD PINES
int horero=0; //Variable para las horas
int minutero=0; //Variable para los minutos
int segundos=0; //Variable para los segundos
int posicion=0;
int estado=0;
void setup() {
   Serial.begin(9600); //Inicializacion CX
   lcd.clear(); //limpieza lcd
   lcd.begin(16,2); // Inicializacion de la LCD
   MsTimer2::set(1000,reloj); // Timer 1seg con un metodo
   MsTimer2::start();//Inicio del timer
   attachInterrupt(0,despertar,FALLING);
   set_sleep_mode(SLEEP_MODE_PWR_SAVE);
   for(;posicion<=255;posicion++ ){ // Contador para encerar la memoria EEPROM
     EEPROM.write(posicion,0);
     delay(1);
}
}
void loop() {
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);   //DORMIR TODO EL SISTEMA
   sleep_enable();
   
   
}
//--------------------------------------RELOJ---------------------------
void reloj(){
  lcd.clear(); //Limpieza de la LCD
  lcd.setCursor(0,0); //Posicion para la impresion
  lcd.print("La Hora Es:"); // Caracteres a imprimir
  if(segundos<59){
      segundos++;
    }
    else{
         if(minutero<59){
           minutero++; //aumento de valor
           EEPROM.write(0,minutero); //Guarda minutero en la pos 0
           segundos=0;// Inicializacion variable
          }
          else{
              if(horero<24){
                horero++;// Aumento de valor
                EEPROM.write(1,horero);//Guarda minutero en la pos 1
                minutero=0;// Inicializacion variable
                }
                else{
                   horero=0;// Inicializacion variable
                  }
            }
      }

      if(horero<24){ //condicion Horero
        lcd.setCursor(0,1); //Posicion para la impresion
        if(horero<10) //condicion horero menor a 10
        lcd.print("0"); //Caracter a imprimir
        lcd.print(horero); //Variable a imprimir
        }
        lcd.setCursor(2,1);  //Posicion a imprimir
        lcd.print(":"); // Caracter a imprimir
        if(minutero<60){ //condicion minutero
        lcd.setCursor(3,1); //Posicion para la impresion
        if(minutero<10) // condicion minutero menor a 10
        lcd.print("0"); // Caracter a imprimir
        lcd.print(minutero); //Variable a imprimir
        }
        lcd.setCursor(5,1); //Posicion para la impresion
        lcd.print(":"); // Caracter a imprimir
        if(segundos<60){ //Condicion del segundero
        lcd.setCursor(6,1); //Posicion para la impresion
      if(segundos<10) //Condicon del segundero menor a 10
        lcd.print("0");  // Caracter a imprimir
        lcd.print(segundos); //Variable a imprimir
        }}


     void despertar(){
      estado++;
      if(estado==1){
        
        power_adc_enable(); 
      }
      else{
        power_adc_disable();
      }
     }
