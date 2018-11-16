/*
 *              UNIVERSIDAD TECNICA DEL NORTE 
 *           FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 *  INTREGRANTES:  CUASCOTA HENRY
 *                 FERNANDEZ SERGIO
 *                 ICHAU ALEXANDER
 *  TEMA: SISTEMA DE VALIDACION DE CONTRASEÑA
 *  FECHA: 18/11/2018
 */
int A=12; // Pulsador A 
int B=11; // Pulsador B 
int C=10; // Pulsador C 
int D=9; // Pulsador D
int correcto=7; //LED VERDE
int incorrecto=6;//LED ROJO
int contras[]={'A','B','C','D','A','B'}; // MATRIZ CONTRASEÑA
int posicion[6]={}; // Matriz de almacenamiento;
int conteo=0; // variable de aumento
int Ao; // almacenamiento del pulsador A 
int Bo; // almacenamiento del pulsador B 
int Co; // almacenamiento del pulsador C 
int Do; // almacenamiento del pulsador D 

void setup() {
pinMode(A,INPUT); // Pulsador A como entrada
pinMode(B,INPUT); // Pulsador B como entrada
pinMode(C,INPUT); // Pulsador C como entrada
pinMode(D,INPUT); // Pulsador D como entrada
pinMode(correcto,OUTPUT);  //LED VERDE COMO SALIDA 
pinMode(incorrecto,OUTPUT); //LED ROJOCOMO SALIDA
Serial.begin(9600);  // CONFIGURACION DEL SERIAL
attachInterrupt(0,SISTEMA,FALLING); // interrupcion LLAMA AL METODO SISTEMA
}

void loop() {
 
  Ao=digitalRead(A); // lee el estado del pulsador A y almacena
  Bo=digitalRead(B); // lee el estado del pulsador B y almacena
  Co=digitalRead(C); // lee el estado del pulsador C y almacena
  Do=digitalRead(D); // lee el estado del pulsador D y almacena
                         
if(Ao){  // configuracion 
  posicion[conteo]='A';   //el pulsador 12 equivales a A Y ALMACENA 
  conteo++; // VARIABLE DE AUMENTO
  delay(500);
  Ao=0;     //REINICION DE VARIABLE            
 }

if(Bo){ // CONFIGURACION
  posicion[conteo]='B'; //el pulsador 11 equivales a B Y ALMACENA 
  conteo++; // VARIABLE DE AUMENTO
  delay(500);
  Bo=0; //REINICION DE VARIABLE   
}
if(Co){
 posicion[conteo]='C'; //el pulsador 10 equivales a C Y ALMACENA 
 conteo++; // VARIABLE DE AUMENTO
 delay(500);
 Co=0; //REINICION DE VARIABLE   
}
if(Do){
  posicion[conteo]='D';  //el pulsador 9 equivales a D Y ALMACENA 
  conteo++; // VARIABLE DE AUMENTO
  delay(500);
  Do=0; //REINICION DE VARIABLE   
}
if(conteo==6){ // configuracion si el conteo es igual a 6
  if((posicion[0]==contras[0])  
    &&(posicion[1]==contras[1])
    &&(posicion[2]==contras[2])
    &&(posicion[3]==contras[3])
    &&(posicion[4]==contras[4])
    &&(posicion[5]==contras[5])){   //validacion  compara el vector en cada posicion respectivaente 
      
    digitalWrite(correcto,HIGH);  // si la validacion es correcta , led correcto encendido
    //delay(3000);
    Serial.println(" CONTRASEÑA CORRECTA "); // mensaje en serial
    }

  else{ // caso contrario
    digitalWrite(incorrecto,HIGH); // led incorrecto encendido
    Serial.println(" CONTRASEÑA INCORRECTA "); // mensaje en serial
       }}
}
 
  void SISTEMA (){ // metodo para el attach
    
    Serial.println(" SISTEMA OFF ");
    posicion[0]=0;  //reicio cada poscion a cero
    posicion[1]=0;
    posicion[2]=0;
    posicion[3]=0;
    posicion[4]=0;
    posicion[5]=0;
    posicion[6]=0;
    conteo=0; // reinicio de conteo
    digitalWrite(correcto,LOW); // led correcto apagado
    digitalWrite(incorrecto,LOW);// led incorrecto apagado
    Serial.println(" SISTEMA ON ");
   }
  
   
   


