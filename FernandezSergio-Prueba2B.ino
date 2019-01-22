/*
 *                UNIVERSIDAD TECNICA DEL NORTE
 *                        PRUEBA 2 BIMESTRE
 *   Nombre:Fernandez Sergio
 *   
 */
 #include <EEPROM.h>
int A=12;
int B=11;
int C=10;
int contras[]={12,11,10,12,11};
int posicion[5]={};
int conteo=0;
int Ao; 
int Bo; 
int Co;
int a=0;
int b=0;
int c=0; 
int fun;
int estado=0;
int verificador=0;
void setup() {
  Serial.begin(9600);
  pinMode(A,INPUT); // Boton 1 como entrada
  pinMode(B,INPUT); // Boton 2 como entrada
  pinMode(C,INPUT); // Boton 3 como entrada
  attachInterrupt(0,master,FALLING); //Interrepcion como master
}
void loop() {
  if(estado==1){
  Ao=digitalRead(A); 
  Bo=digitalRead(B); 
  Co=digitalRead(C); 
                         
if(Ao){  
  posicion[conteo]=12;    
  conteo++; 
  delay(500);
  Ao=0;                 
 }

if(Bo){ 
  posicion[conteo]=11; 
  conteo++; 
  delay(500);
  Bo=0;   
}
if(Co){
 posicion[conteo]=10; 
 conteo++; 
 
 delay(500);
 Co=0;   
}
  }
if(estado==2){
if(conteo==5){ // validacion 
  if((posicion[0]==contras[0])  
    &&(posicion[1]==contras[1])
    &&(posicion[2]==contras[2])
    &&(posicion[3]==contras[3])
    &&(posicion[4]==contras[4])){
      Serial.println("SE PUEDE ENCENDER EL CARRO");
    }
    else{
       verificador++;
       if(verificador<=2){
        Serial.print("Intente nuevamente:");
        Serial.println(verificador);
        conteo=0;
        estado=1;
        fun=1;
        }
      else{
      Serial.println("Nueva contras");
      a=int(random(10,12));
      b=int(random(10,12));
      c=int(random(10,12));
      contras[0]={a};
      contras[1]={b};
      contras[2]={c};
      contras[3]={a};
      contras[4]={b};
      Serial.print(contras[0]);
      Serial.print(contras[1]);
      Serial.print(contras[2]);
      Serial.print(contras[3]);
      Serial.print(contras[4]);
      verificador=0;

      }
      }
}
}
}
void master(){
  switch(fun){
    case 0:
    Serial.println("ACTIVADO");
    estado=1;
    fun++;
  break;
  case 1:
   Serial.println("VERIFICANDO");
   Serial.println(fun);
   estado=2;
   fun++;
  break;
}
}
