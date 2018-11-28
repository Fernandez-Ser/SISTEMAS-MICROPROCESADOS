/*
                  UNIVERSIDAD TECNICA DEL NORTE
               FICA-CIERCOM-SISTEMAS MICROPROCESADOS
    Integrantes= Cuascota Henry
                 Fernandez Sergio
                 Ichau Alexander
    Fecha:28/11/2018
    LABORATORIO
    Desarrolle un sistema que permita la visualización en dos
    display multiplexados el valor de voltaje en decimales.
    Con interrupcion de encendido y apagado.
    EL limite se ingresa Por CX
*/
int A = 7; // pin de salida para display
int B = 6; // pin de salida para display
int C = 5; // pin de salida para display
int D = 4; // pin de salida para display
int uni = 8; // pin habilitacion de las unidades
int decim = 9; // pin habilitacion de decimales
int unidad; // almacenamiento para el valor la unidad
int decimal;// almacenamiento para el valor decimal
int funcionamiento = 0; // variable de estado en el metodo
float conversor;  //almacenamiento del valor Analogo
float dato;//  variable para la conversion del voltaje
int valor; // almacenamiento voltaje en valor entero
String limite; //Almacenamiento de ingreso por Cx
int Enlimite; //Valor ingresado por Cx en entero
void setup() {
  pinMode(A, OUTPUT); // configuracion de pin
  pinMode(B, OUTPUT); // configuracion de pin
  pinMode(C, OUTPUT); // configuracion de pin
  pinMode(D, OUTPUT); // configuracion de pin
  pinMode(uni, OUTPUT); // configuracion de pin unidades
  pinMode(decim, OUTPUT); // configuracion de pin decimales
  attachInterrupt(0, sistema , FALLING); //Interrepcion del sistema
  Serial.begin(9600); // habilitacion Serial
}
void loop() {
  if (funcionamiento == 1) {
    conversor = analogRead(A0); //lee y almacena el voltaje de entrada en Ao
    dato = (5 * conversor) / 1023; //Conversion a un voltaje de 0 a 5V
    valor = dato * 10; //convertimos el dato en un numero entero
    unidad = valor / 10; //Valor de las unidades
    decimal = valor - (unidad * 10); //Valor decimal
    if (Serial.available() > 0) {
      limite = Serial.readString();//Lectura del valor ingresado por Cx
      Enlimite = limite.toInt(); // Conversion del valor limite en entero
    }
    if (dato <= Enlimite) {//Igualamos voltaje con limite para el rango de funcionamiento.
      digitalWrite(decim, HIGH); // activacion de pin del decimal
      digitalWrite(uni, LOW); // desactivacion de pin de unidades
      displ(decimal); // llamo metodo para visualizar el decimal
      delay(100);
      digitalWrite(decim, LOW); // desactivacion de pin del decimal
      digitalWrite(uni, HIGH); // activacion de pin de unidades
      displ(unidad); // llamo metodo para visualizar las unidades
      delay(10);
      Serial.println(dato);// Impresion del valor del voltaje en CX
      delay(300);
    }}
  else {
    conversor = 0; //Inicializacion de variables
    dato = 0; //Inicializacion de variables
    valor = 0; //Inicializacion de variables

  }}
void sistema() { //--------------------------METODO PARA LA INTERRUPCION-------------------------------------------

  funcionamiento = 1 - funcionamiento;
  if (funcionamiento == 1) { //preionamos 1 vez SISTEMA ON
    Serial.println("SISTEMA ON"); //Impresion SISTEMA ON en CX
    Serial.println("Ingrese limite");// Impresion Ingrese Limite

  }
  else { //preionamos 2 vez SISTEMA OFF
    Serial.println("SISTEMA OFF");  //Impresion SISTEMA OFF en CX
    funcionamiento = 0; // Inicializacion de variable
    digitalWrite(uni, LOW); // Pin de unidades apagado
    digitalWrite(decim, LOW); //Pin de decimales apagado

  }}
void displ (int j) { //-----------------METODO NUMERICO PARA EL DISPLAY ---------------------------------------------
  switch (j) {
    //0
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    //1
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    //2
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    //3
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    //4
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    //5
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    //6
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    //7
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    //8
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    //9
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }}

