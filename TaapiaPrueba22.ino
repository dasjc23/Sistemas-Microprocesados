
#include <EEPROM.h>
#include <avr/wdt.h>


/*
 *          UNIVERSIDAD TECNICA DEL NORTE 
 *                      FICA
 *                    CIERCOM
 *            Sistemas Microcprocesados
 *            
 *Juan Carlos Tapia Vivero            
 *22 de enero de 2019
 *
 *Se necesita emular el funcionamiento de un control de auto ChevyStar. Para ello, se tienen las siguientes características.
• Se cuenta con 4 botones, uno máster y 3 para la contraseña.
• La contraseña es de 5 dígitos que debe ser la combinación de los 3 botones.
• El sistema al presionar una vez (solo botón máster) y sin contraseña envía por comunicación serial 
  el mensaje de activado o desactivado.
• Si es digitada la contraseña es correcta (se presiona la combinación de los 3 botones y luego el máster), 
  envía por mensaje serial que se puede encender el carro. 
  Caso contrario, se tendrá hasta 2 intentos más para acertar a la contraseña. 
  Si no es el caso, el control se reinicia y genera otra contraseña de forma aleatoria de la combinación de los pulsadores. 
  La nueva contraseña se envía por comunicación serial.
 *
 * 
 *Nota: Al usar los pulsadores hacerlo lento para que funcione bien todo. =)
 *
 * 
 */


int PUL1 =10;
int PUL2 =11;
int PUL3 =12;
int PUL4 =3;
int nuevo1;
int nuevo2;
int nuevo3;
int nuevo4;
int nuevo5;
int clave[]={1,1,1,1,1};
int vali[]={100,100,100,100};
int estado = 0;
int intentos= 2;
int on=0;
int ledR=7;
int ledV=8;
int mas=0;

void setup (){
  Serial.begin(9600);
  pinMode(ledV, OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(PUL1,INPUT);
  pinMode(PUL2,INPUT);
  pinMode(PUL3,INPUT);
 attachInterrupt(1, master,FALLING);
  
}

void loop (){ 

  if(digitalRead(PUL1)){
    vali[estado]=1;
    estado++;
    Serial.println(estado);
    delay(500);
    
  }
  if(digitalRead(PUL2)){
    vali[estado]=2;
    estado++;
    Serial.println(estado);
    delay(500);
  }
   if(digitalRead(PUL3)){
    vali[estado]=3;
    estado++;
    Serial.println(estado);
    delay(500);
  }
  
  if(estado==5){
    if(digitalRead(PUL4)){
    if((vali[0]==clave[0])&&(vali[1]==clave[1])&&(vali[2]==clave[2])&&(vali[3]==vali[3])){
//      EEPROM.write(0,clave[0]);
//      EEPROM.write(1,clave[1]);
//      EEPROM.write(2,clave[2]);
//      EEPROM.write(3,clave[3]);
      digitalWrite(ledV,HIGH);
      Serial.println("Contraseña Válida. Encienda el carro");
      delay(500);
      intentos=2;
    }
    else {
      Serial.println("ERROR");
      intentos--;
      digitalWrite(ledR,HIGH);
      delay(500);
    }
    digitalWrite(ledV,LOW);
    digitalWrite(ledR,LOW);
    estado=0;
    }
    }
    
if(intentos==0){
  reset();
  }
       
  if(digitalRead(PUL4)){
  if(estado==0){
    Serial.println("Desactivado");
    digitalWrite(ledR,HIGH);
    delay(500);
    }
else{
  Serial.println("Activado");
    digitalWrite(ledR,HIGH);
    delay(500); 
  }
  
  }}
 

void reset(){

 Serial.println("Reinicio de Contraseña");
 delay(500);
 nuevo1=random(1,4);
 nuevo2=random(1,4);
 nuevo3=random(1,4);
 nuevo4=random(1,4);
 nuevo5=random(1,4);

  EEPROM.update(0,nuevo1);
  EEPROM.update(1,nuevo2);
  EEPROM.update(2,nuevo3);
  EEPROM.update(3,nuevo4);
  EEPROM.update(4,nuevo5);

Serial.println("Códiogo Aleatorio es: "+String(EEPROM.read(0))+String(EEPROM.read(1))+String(EEPROM.read(2))+String(EEPROM.read(3))+String(EEPROM.read(4)));

delay(500);
intentos=2;
estado=0;
wdt_enable(WDTO_1S);

}

void master(){

     }
  
