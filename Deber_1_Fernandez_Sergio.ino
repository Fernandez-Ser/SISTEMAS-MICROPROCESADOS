/*  DEBER N=1 PUERTOS ENTRADA SALIDA
 *  Nombre: Fernandez Sergio Rolando
 *  Fecha: 25/10/2018
 */

 /*
   //1.-REALIZAR UN JUEGO DE LUCES QUE SE PRENDAN SECUENCIALMENTE LOS LEDS IMPARES(1,3,5).

int leds[6]={8,9,10,11,12,13};  // Mi vector de leds del 0 al 5
int i=0; // mi variable de recorrido 

void setup() {
  for( ;i<6;i++){
     pinMode(leds[i],OUTPUT);}  // leds de salida 0 al 5 desde los pines 8 al 13 
  i=0;}

void loop() {
 for( ;i<6;i++){
    digitalWrite(leds[i+1],HIGH);
    delay(100);
    i=i+1;}
 for( ;i>0;i--){
    digitalWrite(leds[i],LOW);
    delay(100);}
 i=0;}
*/

 
/*
 // 2.-REALIZAR UN PROGRAMA QUE SE ENCIENDAN UNO POR UNO LOS LEDS PARES(0,2,4)
int leds[6]={8,9,10,11,12,13};  // Mi vector de leds del 0 al 5
int i=0; // mi variable de recorrido 

void setup() {
  for( ;i<6;i++){
     pinMode(leds[i],OUTPUT);} // leds de salida 0 al 5 desde los pines 8 al 13 
  i=0;}

void loop() {
for( ;i<6;i=i+2){
   digitalWrite(leds[i],HIGH);
   delay(100);
   digitalWrite(leds[i],LOW);
   delay(100);}
i=0;}
 */

//3.- Realizar un juego que se enciendan y apagen los leds de forma aleatoria

int leds[6]={8,9,10,11,12,13};  // Mi vector de leds del 0 al 5 desde los pines 8 al 13 
int rnd=0;  // mi variable que va a tomar valores aleatorios que proporcione el random

void setup() {
  for( ;rnd<=6;rnd++){
     pinMode(leds[rnd],OUTPUT);} // leds de salida 0 al 5 desde los pines 8 al 13 
  randomSeed(analogRead(0));}

void loop() {
  rnd=random(8,13);   // random( valor minimo , valor maximo) me va a generar valores desde el pin 8 al pin 13 
   digitalWrite(rnd,HIGH);  // led aleatorio en alto 
   delay(100);
   digitalWrite(rnd,LOW);   // led aleatorio en bajo 
   delay(100);
}



