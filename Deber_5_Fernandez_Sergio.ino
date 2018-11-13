/*
 *                UNIVERSIDAD TECNICA DEL NORTE
 *             FICA-CIERCOM-SISTEMS MICROPROCESADOS
 *  Nombre: Fernandez Sergio Rolando
 *  Fecha:13/11/2018
 *  
 *  VALIDACION DE LA CEDULA DE IDENTIDAD  
 */
unsigned long cedula; // variable para almacenamiento 
int a=0;  //para digito 1
int b=0;  //para digito 1
int c=0;  //para digito 1
int d=0;  //para digito 2
int e=0;  //para digito 3
int f=0;  //para digito 4
int g=0;  //para digito 5
int h=0;  //para digito 6
int i=0;  //para digito 8
int j=0;  //para digito 9
int k=0;  //para digito 10
int spar; //suma pares
int simp; //suma impares
int stotal; //suma total de pares e impares
int aimp;  // variable de almacenamiento de a
int cimp; // variable de almacenamiento de c
int eimp; // variable de almacenamiento de e
int gimp; // variable de almacenamiento de g
int iimp; // variable de almacenamiento de i
int tot; // almacenamiento de valor de comparacion
int validacion;
void setup() {
  Serial.begin(9600); // activar puerto serial
  Serial.println("INGRESE LA CEDULA"); //texto
  }

void loop() {
  
  if(Serial.available()>0){ 
    cedula=Serial.parseInt();  //leemos el valor de entrada del serial
   // Separamos en digitos
    a=cedula/1000000000; // valor del digito 1  (impar)
    b=(cedula-(a*1000000000))/100000000; // valor del digito 2  (par)
    c=(cedula-(a*1000000000+b*100000000))/10000000; // valor del digito 3  (impar)
    d=(cedula-(a*1000000000+b*100000000+c*10000000))/1000000; // valor del digito 4  (par)
    e=(cedula-(a*1000000000+b*100000000+c*10000000+d*1000000))/100000; // valor del digito 5  (impar)
    f=(cedula-(a*1000000000+b*100000000+c*10000000+d*1000000+e*100000))/10000; // valor del digito 6  (par)
    g=(cedula-(a*1000000000+b*100000000+c*10000000+d*1000000+e*100000+f*10000))/1000; // valor del digito 7  (impar)
    h=(cedula-(a*1000000000+b*100000000+c*10000000+d*1000000+e*100000+f*10000+g*1000))/100; // valor del digito 8  (par)
    i=(cedula-(a*1000000000+b*100000000+c*10000000+d*1000000+e*100000+f*10000+g*1000+h*100))/10; // valor del digito 9  (impar)
    j=cedula-(a*1000000000+b*100000000+c*10000000+d*1000000+e*100000+f*10000+g*1000+h*100+i*10); // valor del digito 10 (digito de validacion)
     
   //condiciones para los impares
   
   if((a*2)>9){ //Condicion si la multiplicacion supera de 9
    aimp=(a*2)-9; // valor para a impar
   }
   else{ 
    aimp=a*2;
   }

   if((c*2)>9){ //Condicion si la multiplicacion supera de 9
    cimp=(c*2)-9; // valor para c impar
   }
   else{
    cimp=c*2;
   }
   
   if((e*2)>9){ //Condicion si la multiplicacion supera de 9
    eimp=(e*2)-9; // valor para e impar
   }
   else{
    eimp=e*2;
   }

   if((g*2)>9){ //Condicion si la multiplicacion supera de 9
    gimp=(g*2)-9; // valor para g impar
   }
   else{
    gimp=g*2;
   }
  if((i*2)>9){ //Condicion si la multiplicacion supera de 9
    iimp=(i*2)-9;// valor para i impar
   }
   else{
    iimp=i*2;
   }

   simp=aimp+cimp+eimp+gimp+iimp;  // suma de impares
   spar=b+d+f+h;                   //suma de pares
   stotal=simp+spar;              //suma total
   
   if(stotal>20 &&stotal<30){    //Condicion para obtener un digito
    tot=30-stotal;
   }
   if(stotal>30 &&stotal<40){   //Condicion para obtener un digito
    tot=40-stotal;
   }
   if(stotal>40 &&stotal<50){  //Condicion para obtener un digito
    tot=50-stotal;
   }
   if(stotal>50 &&stotal<60){  //Condicion para obtener un digito
    tot=60-stotal;
   }
   if(stotal>60 && stotal<70){  //Condicion para obtener un digito
    tot=70-stotal;
   }
   if(stotal>70&&stotal<80){  //Condicion para obtener un digito
   tot=40-stotal;
   }
   
   if(tot==j){ // comparacion del valor tot con el digito de validacion
    Serial.println(" CEDULA VALIDA ");  // cuando toot es igual aldigito de validacion
   }
   else{  // caso contrario la cedula es invalida
    Serial.println(" CEDULA INCORRECTA"); 
   }
}
}
