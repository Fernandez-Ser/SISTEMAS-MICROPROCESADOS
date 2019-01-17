/*                              UNIVERSIDAD TECNICA DEL NORTE
 *                           FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 * Integrantes: Cuascota Henry
 *              Fernandez Sergio
 *              Ichau Alexander
 * Tema:
 * Realizar el sistema domótico que tenga 3 sensores ubicados en puertas y ventana. 
 * Debe guardar la hora en la memoria EEPROM cuando suceda algún inconveniente 
   después que la casa sea asegurada. 
   Para ello, debe ingresar un contrasena de 5 digitos (guardados en la EEPROM)
   que dará 25 segundos para salir de la casa y que los sensores se activen.
   Si la alarma se enciende, obligatoriamente debe digitar la contraseña para apagarla. 
   Además, debe tener una función de poder cambiarla en caso de necesitarlo.  
   Toda la información del estado de la alarma se lo debe visualizar en una lcd.
 */
#include <EEPROM.h>// Libreria Memoria EEPROM
#include <TimerOne.h>//Libreria Timer1
#include <Keypad.h> //Libreria Teclado
#include <MsTimer2.h>  // Libreria del Timer Dos
#include <LiquidCrystal.h> //Libreria de la LCD
const byte ROWS = 3; //filas
const byte COLS = 3; //columnas
char hexaKeys[ROWS][COLS] = { //Matriz del teclado
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
};
byte rowPins[ROWS] = {4,3,2};//Pines del teclado en filas
byte colPins[COLS] = {7,6,5}; //Pines del teclado en columnas
char pwd [5]={'1','2','3','4','5'}; //Contraseña
char pwdof [5]={'1','2','3','4','5'}; //Contraseña
char usuario1 [5]; //Almacenador de digitos para contraseña
char usuarioof [5]; //Almacenador de digitos para contraseña
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
int h=0; //estado de funcionamiento
int i=0; //contador para contraseña
int a=0;//contador para contraseña
int m=0; //estado de funcionamiento
int posicion=0; // contador de posicion
int mostrador=0;
int ldrvent_1=A0; //Sensor ventana1
int ldrpuerta=A1; //Sensor puerta
int ldrvent_2=A2;//Sensor ventana2
int contador=0;
int alerta=A3;
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);//Conf teclado
void setup() {
  Serial.begin(9600); //Inicializacion CX
  pinMode(alerta,OUTPUT); // pin de salida para alarma
  lcd.clear(); //limpieza lcd
  lcd.begin(16,2); // Inicializacion de la LCD
  MsTimer2::set(1000,reloj); // Timer 1seg con un metodo
  MsTimer2::start();//Inicio del timer
  for(;posicion<=255;posicion++ ){ // Contador para encerar la memoria EEPROM
     EEPROM.write(posicion,0);
     delay(1);
}}

void loop() {
  funcionamiento();
    } 
 //-----------------------------------------Metodo CONTEO---------------------------   
void conteo(){
  contador++;
  if(contador>=25){
     mostrador=1;
    if(mostrador==1){
      Serial.println("Sensores Activados");
      lcd.setCursor(9,1); //Ubicacion de impresion
      lcd.print("A-ON");
    }
    sensores(); //llamamos metodo sensores
  }
  }
 //---------------------------------------FUNCIONAMIENTO CONTRA--------------------------   
void funcionamiento(){
  if(h==0){
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY) {
        usuario1[i]=customKey;
        i++;}
    }
    if(i==5){
     if(usuario1[0]==pwd[0]&&
        usuario1[1]==pwd[1]&&
        usuario1[2]==pwd[2]&&
        usuario1[3]==pwd[3]&&
        usuario1[4]==pwd[4]){ //validacion de Contraseña
        a=0;
       Serial.println("CONT-CORRECTA"); //Catacteristicas a imprimir
       Timer1.initialize(100000); ///Timer 1 en 1 seg
       Timer1.attachInterrupt(conteo);//Inicializa Timer
       m++;
       i=0;}
       }
       if(m==1){
        Serial.println("Inicio conteo"); //Caracteristicas a imprimir
          m=0;
          h++;
       }
       
       if(h==1){
        char customKeyof = customKeypad.getKey();
    if (customKeyof != NO_KEY) {
        usuarioof[a]=customKeyof;
        a++;
    }
    }
    
    if(a==5){
     if(usuarioof[0]==pwdof[0]&&
        usuarioof[1]==pwdof[1]&&
        usuarioof[2]==pwdof[2]&&
        usuarioof[3]==pwdof[3]&&
        usuarioof[4]==pwdof[4]){//validacion de Contraseña
        contador==0;
        mostrador==0;
        m==0;
        ldrvent_1=10;
        ldrpuerta=10;
        ldrvent_2=10;  
       Serial.println("Alarmas Apagadas");//Caracteristicas a imprimir
       digitalWrite(alerta,LOW);
       lcd.setCursor(9,1);//Lugar de impresion
       lcd.print("A-OF");//Estado de la alarma apagado
       h=0;
       }
      }
      }
//--------------------------------SENSORES-------------------------------
void sensores(){
   ldrvent_1=(analogRead(A0)*100)/1023; //lee y convierte el voltaje del ldr
   ldrpuerta=(analogRead(A1)*100)/1023; //lee y convierte el voltaje del ldr
   ldrvent_2=(analogRead(A2)*100)/1023; //lee y convierte el voltaje del ldr
   if(ldrvent_1<=2){
    Serial.println("ALERTA VENTANA 1 ABIERTO");
    EEPROM.write(10,horero);//Guarda horero en la pos 10
    EEPROM.write(11,minutero);//Guarda minutero en la pos 11
    digitalWrite(alerta,HIGH);//Aviso de alarma encendido
    delay(500);
   }
   delay(500);
   if(ldrpuerta<=2){
    Serial.println("ALERTA PUERTA ABIERTA");
    EEPROM.write(10,horero);//Guarda horero en la pos 10
    EEPROM.write(11,minutero);//Guarda minutero en la pos 11
    digitalWrite(alerta,HIGH);//Aviso de alarma encendido
    delay(500);
   }
   if(ldrvent_2<=2){
    Serial.println("ALERTA VENTANA 2 ABIERTO");
    EEPROM.write(10,horero);//Guarda horero en la pos 10
    EEPROM.write(11,minutero);//Guarda minutero en la pos 11
    digitalWrite(alerta,HIGH);//Aviso de alarma encendido
    delay(500);
   }
   
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
