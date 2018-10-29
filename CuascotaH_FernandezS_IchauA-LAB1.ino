/*                UNIVERSIDAD TECNICA DEL NORTE
 *            FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 *  INTEGRANTES: CUASCOTA HENRY
 *               FERNANDEZ SERGIO
 *               ICHAU ALEXANDER
 *  Fecha: 30/10/2018
 */
//                            LABORATORIO DE SW 
//----------------------------------------------------------------------------------------------

//1.- Realizar un contador binario del 1 al 31

int leds[6]={8,9,10,11,12,13}; // defino leds de salida en que pines 
int cto=0; //el contador inicia en 0
int sw=3; // el pulsador el el pin 9 
int i=0; // variables 
int k =0;
void setup() {
pinMode(sw, INPUT); //declaro sw = a pulsador  como entrada 
for(i=0;i<=6;i++){ // variables de salida 
pinMode(leds[i],OUTPUT);// declaro leds[i] como salida de los datos en binario 
}
}

void loop() {
if (digitalRead(sw)==HIGH){ // si el sw esta en esta alto o si presiono el sw
  delay(300); // delay antirebotes 
cto++; // incremento el contador 
digitalWrite(leds[i],HIGH); // enciendo leds correspondientes
if (digitalRead(sw)==LOW)// si el sw esta en estado bajo 
digitalWrite (leds[i],LOW);// leds apagados 
if (cto>31){ // El contador llega a 31 entonces pasa al estado de cto=0
cto=0; // el contador vuelve a cero 
}
conteo(); // llamo al metodo conteo 
}


}

void conteo (){
  k=cto; // El contador va a variable k
for(i=0; i<=6; i++){ //ciclo para ver que leds debe prenderse 
digitalWrite(leds[i], k%2); // saco el modulo de la division para ver es estado del led si prendido o apagado
k=k/2; // Se divide el cociente entre 2 por cada suma de binario
}  
 }


 //-----------------------------------------------------------------------------------------------------------------------------
/*
   
 //2.- Realizar 4 juegos de luces con activación mediante switchs. 

int leds[6]={8,9,10,11,12,13}; // Mi vector de leds del 0 al 5
int i=0; // mi variable de recorrido 
int rnd=0;  // mi variable que va a tomar valores aleatorios que proporcione el random
int one=7; // sw en el pin 7
int two=6; // sw en el pin 6 
int tree=5; //sw en el pi 5
int four=4; //sw en el pin 4 

void setup() {
  for( ;i<6;i++){
     pinMode(leds[i],OUTPUT);}  // leds de salida 0 al 5 desde los pines 8 al 13 
  i=0;
  for( ;rnd<=6;rnd++)
  pinMode(leds[rnd],OUTPUT); // leds de salida 0 al 5 desde los pines 8 al 13  para el random
  randomSeed(analogRead(0));
  pinMode(one,INPUT);  // pin 7 como entrada 
  pinMode(two,INPUT); // pin 6 como entrada
  pinMode(tree,INPUT); // pin 5 como entrada
  pinMode(four,INPUT); // pin 4 como entrada
  }
void loop() {
  
  //PARA EL SW 1 =JUEGO DE LUCES QUE SE PRENDAN SECUENCIALMENTE LOS LEDS IMPARES(1,3,5).
  
  if(digitalRead(one)==HIGH){  // comparacion de entrada en el pin 7
 for( ;i<6;i++){
    digitalWrite(leds[i+1],HIGH);
    delay(100);
    i=i+1;}
 for( ;i>0;i--){
    digitalWrite(leds[i],LOW);
    delay(100);}
  }
 else{
 i==0;}

 // PARA EL SW 2 REALIZAR UN PROGRAMA QUE SE ENCIENDAN UNO POR UNO LOS LEDS PARES(0,2,4)

if(digitalRead(two)==HIGH){ // comparacion de entrada en el pin 6
for( ;i<6;i=i+2){
   digitalWrite(leds[i],HIGH);
   delay(100);
   digitalWrite(leds[i],LOW);
   delay(100);}
i=0;}
else
i==0;

//PARA EL SW 3 un juego que se enciendan y apagen los leds de forma aleatoria
if(digitalRead(tree)==HIGH){ // comparacion de entrada en el pin 5
  rnd=random(8,13);   // random( valor minimo , valor maximo) me va a generar valores desde el pin 8 al pin 13 
   digitalWrite(rnd,HIGH);  // led aleatorio en alto 
   delay(100);
   digitalWrite(rnd,LOW);   // led aleatorio en bajo 
   delay(100);
}
else
rnd==0;

// PARA EL SW 4 JUEGO DE LUCES ENCENDIDO PARALELOS (0,5) (1,4) (2,3)
if(digitalRead(four)==HIGH){ // comparacion de entrada en el pin 4
for(;i<6;i++){
  digitalWrite(leds[i],HIGH);
  digitalWrite(leds[5-i],HIGH);
  delay(500);
  }i=5;
  for(;i>=0;i--){
  digitalWrite(leds[i],LOW);
  digitalWrite(leds[5-i],LOW);
  delay(400);
  } i=0;}
  else
  i==0;
}
*/
