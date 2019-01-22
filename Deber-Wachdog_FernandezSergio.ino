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

#include <TimerOne.h>
#include <avr/wdt.h>
#include <LiquidCrystal.h> 
int A=13;
int B=12;
int C=11;
int D=10;
int E=9;
int F=8;
LiquidCrystal lcd (A,B,C,D,E,F);
int val_pot=0;
int con_pot=0;
int a=0;
int b=0;
int c=0;
int d=0;
int segundos;
int mostrador=0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Valor:");
  lcd.setCursor(0,1);
  lcd.print("Tiempo:");
}

void loop() {
 val_pot=analogRead(A0);
  con_pot=(val_pot*4)/1023;
  
 //--------Para 10 segundos-----------------------
  if(con_pot==1){ 
  lcd.setCursor(10,0);
  lcd.print("10");
  segundos=2;
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(diez);
  }
 //--------Para 20 segundos----------------------- 
  if(con_pot==2){
    lcd.setCursor(10,0);
    lcd.print("20");
    segundos=12;  
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(veinte);
  }
  //--------Para 30 segundos-----------------------
  if(con_pot==3){
    lcd.setCursor(10,0);
    lcd.print("30");
    segundos=22;
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(treinta);
  }
  //--------Para 40 segundos-----------------------
  if(con_pot==4){
    lcd.setCursor(10,0);
    lcd.print("40");
    segundos=32; 
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(cuarenta);
  }
}
void diez(){
  a++;
  lcd.setCursor(8,1);
  lcd.print(a);
  if(a==segundos){
    wdt_enable(WDTO_8S);
  }
 }
void veinte(){
  b++;
  lcd.setCursor(8,1);
  lcd.print(b);
  if(b==segundos){
    wdt_enable(WDTO_8S);
  }
}
void treinta(){
  c++;
  lcd.setCursor(8,1);
  lcd.print(c);
  if(c==segundos){
    wdt_enable(WDTO_8S);
  }
}
void cuarenta(){
  d++;
  lcd.setCursor(8,1);
  lcd.print(d);
  if(d==segundos){
    wdt_enable(WDTO_8S);
  }
}

