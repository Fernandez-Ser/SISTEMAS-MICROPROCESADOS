/*
 *                  Universidad Tecnica del Norte
 *              Fica-Ciercom-Sistemas Microprocesados
 * Nombre: Fernandez Sergio Rolando
 * Fecha:10/01/2019
 * 
 *                           Deber
 * rograma de un reloj con alarma que sea ingresada por comunicacion serial.
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
String alhora; // Lee la variable hora 
String alminuto;//leee la variable minuto
int alarmah=0; //para almacenar la hora
int alarmam=0; //para almacenar los minutos
int espacio=0; // variable de aumento
int al_aviso=7; // Aviso de la alarma
LiquidCrystal lcd(A,B,C,D,E,F); //  conf LCD
void setup() {
  Serial.begin(9600);//Conf Comunicacion Serial
  lcd.begin(16,2); // Inicializacion de la LCD
  MsTimer2::set(1000,segundero); // Timer 1seg con un metodo
  MsTimer2::start();//Inicio del timer
  pinMode(al_aviso,OUTPUT); //Aviso de la alarma como salida
  Serial.println("---ALARMA---"); //Caracter a imprimir
  Serial.println("INGRESE LA HORA"); //Caracter a imprimir
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
   alarma(); // Llamamos al metodo de la alarma
   if(alarmah==horas&&alarmam==minutos){ //condicion de funcionamiento de la alarma
      digitalWrite(al_aviso,HIGH); //Activacion de la alarma
   }
   else{
    digitalWrite(al_aviso,LOW); // Desactivacion de la alarma
   }
}
  
 void segundero(){//metodo para el Timer 
   segundos++; //conteo de segundos
}
//---------metodo alarma-----
void alarma(){ 
  if(Serial.available()>0){ //Comuniccion serial habilitada para recibir datos
    alhora=Serial.readString(); // lee el dato hora ingresado
    alarmah=alhora.toInt(); // convierte el dato alhora a entero
    espacio++; // aumento para funcionalidad de los minutos
    if(espacio==1){ //condicion para ingreso de minutos
      Serial.println("INGRESE LOS MINUTOS"); //Caracteres a imprimir
      alminuto=Serial.readString(); // lee el dato minutos ingresado
      alarmam=alminuto.toInt();//convierte el dato alminuto en entero
      espacio==0; 
    }
  }}
  


