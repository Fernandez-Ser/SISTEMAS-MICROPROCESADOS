/*             UNIVERSIDAD TECNICA DEL NORTE
 *          FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 *  Nombre:Fernandez Sergio       
 *  Fecha: 22/1/2019
 *  
 *                               Deber
 * Realizar un programa que permita que el conversor análogo digital configure al perro guardían 
 * a 10,20,30 y 40 segundos. 
 * Este proceso se visualiza en una lcd.
 */

#include <TimerOne.h> //Libreria Timer 
#include <avr/wdt.h> //Libreria perro guardian
#include <LiquidCrystal.h> //Libreria LCD
int A=13; //PIN PARA LCD
int B=12; //PIN PARA LCD
int C=11; //PIN PARA LCD
int D=10; //PIN PARA LCD
int E=9; //PIN PARA LCD
int F=8; //PIN PARA LCD
LiquidCrystal lcd (A,B,C,D,E,F); //conf lcd
int val_pot=0; //Variable potenciometro
int con_pot=0; // Variable conversor de potenciometro
int a=0; //Variable contador de para 10s
int b=0; //Variable contador de para 20s
int c=0; //Variable contador de para 30s
int d=0; //Variable contador de para 40s
int segundos; //Variable deigualdad de segundos
void setup() {
  lcd.begin(16,2); //Inicializacion LCD
  lcd.clear(); // limpieza lcd
  lcd.setCursor(0,0); //Posicion de impresion
  lcd.print("Valor:");//Caracter a imprimir
  lcd.setCursor(0,1); //Posicion de impresion
  lcd.print("Tiempo:");//Caracter a imprimir
}

void loop() {
 val_pot=analogRead(A0); //lee el valor del potenciometro
  con_pot=(val_pot*4)/1023; //conversion del voltaje
  
 //--------Para 10 segundos-----------------------
  if(con_pot==1){ //Cuando el potenciometro vale 1
  lcd.setCursor(10,0);//Posicion de impresion
  lcd.print("10");
  segundos=2;
  Timer1.initialize(1000000);//Inicializacion Timer
  Timer1.attachInterrupt(diez);//Timer con metodo
  }
 //--------Para 20 segundos----------------------- 
  if(con_pot==2){//Cuando el potenciometro vale 2
    lcd.setCursor(10,0);//Posicion de impresion
    lcd.print("20");
    segundos=12;  
    Timer1.initialize(1000000);//Inicializacion Timer
    Timer1.attachInterrupt(veinte);//Timer con metodo
  }
  //--------Para 30 segundos-----------------------
  if(con_pot==3){//Cuando el potenciometro vale 3
    lcd.setCursor(10,0);//Posicion de impresion
    lcd.print("30");
    segundos=22;
    Timer1.initialize(1000000);//Inicializacion Timer
    Timer1.attachInterrupt(treinta);//Timer con metodo
  }
  //--------Para 40 segundos-----------------------
  if(con_pot==4){//Cuando el potenciometro vale 4
    lcd.setCursor(10,0);//Posicion de impresion
    lcd.print("40");
    segundos=32; 
    Timer1.initialize(1000000); //Inicializacion Timer
    Timer1.attachInterrupt(cuarenta);//Timer con metodo
  }
}
void diez(){
  a++;
  lcd.setCursor(8,1);//Posicion de impresion
  lcd.print(a);//impresion del contador
  if(a==segundos){
    wdt_enable(WDTO_8S);//perro guardian en 8S
  }
 }
void veinte(){
  b++;
  lcd.setCursor(8,1);//Posicion de impresion
  lcd.print(b);//impresion del contador
  if(b==segundos){
    wdt_enable(WDTO_8S);//perro guardian en 8S
  }
}
void treinta(){
  c++;
  lcd.setCursor(8,1);//Posicion de impresion
  lcd.print(c);//impresion del contador
  if(c==segundos){
    wdt_enable(WDTO_8S);//perro guardian en 8S
  }
}
void cuarenta(){
  d++;
  lcd.setCursor(8,1);//Posicion de impresion
  lcd.print(d);//impresion del contador
  if(d==segundos){
    wdt_enable(WDTO_8S);//perro guardian en 8S
  }
}

