
#include <LiquidCrystal.h> 
#include <MsTimer2.h>
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
 */
 
int segundos = 0;
int ajuste = 0;
int dat=0;

LiquidCrystal lcd(13,12,11,10,9,8);
 
void setup() {
dat = analogRead(0);
  MsTimer2::set(500,contador); 
  MsTimer2::start(); }


  

void loop() {
  
  if(ajuste>0){
dat = analogRead(0);
  lcd.setCursor(0,0);
  lcd.print("AJUSTE DEL TIEMPO "+String(ajuste)); 
  lcd.setCursor(0,1);
  lcd.print("El tiempo es : "+String(segundos)); 
  }}

void contador(){
  segundos++;
 if( dat<1024 && dat>=768){
  ajuste = 40;
   if(segundos>=40){
     segundos = 0;  
     wdt_enable(WDTO_15MS);
    }
  }
  if( dat<768 && dat>=512){
 ajuste = 30;
   if(segundos>=30){
    segundos = 0;  
     wdt_enable(WDTO_15MS);
    }
  }
if( dat<512 && dat>=256){
  ajuste = 20;
   if(segundos>=20){
   segundos = 0;  
   wdt_enable(WDTO_15MS);
    }
  }
 if( dat<256){
   ajuste = 10;
  if(segundos>=10){
    segundos = 0;  
    wdt_enable(WDTO_15MS);
    }
  }
  
}
