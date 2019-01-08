/*
 *                  Universidad Tecnica del Norte
 *              Fica-Ciercom-Sistemas Microprocesados
 * Nombre: Fernandez Sergio Rolando
 * Fecha:08/01/2019
 * 
 *                           Deber
 * Programa que muestre el segundero, minutero y horero visto en una lcd.
 */
#include <MsTimer2.h>  // Libreria del Timer Dos
#include <LiquidCrystal.h> //Libreria de la LCD
int A=13; //variable para LCD
int B=12; //variable para LCD
int C=11; //variable para LCD
int D=10; //variable para LCD
int E=9;  //variable para LCD
int F=8;  //variable para LCD
int horas=0; //Variable para las horas
int minutos=0; //Variable para los minutos
int segundos=0; //Variable para los segundos
LiquidCrystal lcd(A,B,C,D,E,F); //  conf LCD
void setup() {
  lcd.begin(16,2); // Inicializacion de la LCD
  MsTimer2::set(1000,segundero); // Timer 1seg con un metodo
  MsTimer2::start();//Inicio del timer
}
void loop() {
  lcd.clear(); //Limpieza de la LCD
  lcd.setCursor(0,0); //Posicion para la impresion
  lcd.print("La Hora Es:"); // Caracteres a imprimir
  if(horas<24){ //condicion Horero
        lcd.setCursor(0,1); //Posicion para la impresion
        if(horas<10) //condicion horero menor a 10
        lcd.print("0"); //Caracter a imprimir
        lcd.print(horas); //Variable a imprimir
        }
  else{
        horas=0; //inicializa la variable en 0
        }
        lcd.setCursor(2,1);  //Posicion a imprimir
        lcd.print(":"); // Caracter a imprimir
  if(minutos<60){ //condicion minutero
        lcd.setCursor(3,1); //Posicion para la impresion
        if(minutos<10) // condicion minutero menor a 10
        lcd.print("0"); // Caracter a imprimir
        lcd.print(minutos); //Variable a imprimir
        }
  else{
        horas++; //  Aumento del horero
        minutos=0; //Inicializa el minutero
        }
        lcd.setCursor(5,1); //Posicion para la impresion
        lcd.print(":"); // Caracter a imprimir
  if(segundos<60){ //Condicion del segundero
        lcd.setCursor(6,1); //Posicion para la impresion
      if(segundos<10) //Condicon del segundero menor a 10
        lcd.print("0");  // Caracter a imprimir
        lcd.print(segundos); //Variable a imprimir
        }
  else{
        minutos++; //aumento minutero
        segundos=0;//Inicializa los segundos
        }
   delay(100);
}
  
 void segundero(){//metodo para el Timer 
   segundos++; //conteo de segundos
}
  

