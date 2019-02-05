//
//          UNIVERSIDAD TÉCNICA DEL NORTE
//                       FICA
//                      CIERCOM 
//              Sistemas Microprocesados
//
//
//    Juan Carlos Tapia
//
//   Realizar un programa que permita poner al sistema 19 segundos en modo sleep, 
//  se despierte, realice un lectura del conversor análogo digital, lo imprima por comunicación serial y vuelva a dormir 19 segundos.


#include <TimerOne.h>
#include <avr/sleep.h>
#include <avr/power.h>

float valorcad;
int dato;
int i=0;
int on;
int sensor1= A0;  

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(contador);
  attachInterrupt(0,on,LOW);
  set_sleep_mode (SLEEP_MODE_PWR_DOWN); 
  sleep_enable();
  attachInterrupt(1, levantar,LOW);

}

void loop() {
  if (i==19){
    }
  
valorcad=(analogRead(sensor1)*99.00)/1023.0;
    dato=int(valorcad);
}

void levantar(){
  on=1-on;
}

void contador(){
  i++;
}
