/*
 * Deber #1
 * Nombre:  Juan Carlos Tapia Vivero  
 * Fecha:   25 de Octubre de 2018
 * Deber:   Realizar los juegos detallados en el aula virtual
 * 
 */

int leds[6]={8,9,10,11,12,13}; // definimos vector de los leds
int i=0; // variable del recorrido o para el contador


void setup() {  

  for (;i<6;i++){
    pinMode(leds[i],OUTPUT);
    }
    i=0;


}

void loop() {
 
     // Ejercicio #1 (1-3-5)
for (;i<3;i++){
  digitalWrite(leds[2*i+1],HIGH); // Se usa la lógica de números impares 2x+1
  delay(300);
  digitalWrite(leds[2*i+1],LOW);
  delay(300);  
   }

i=0;


    //  Ejercicio #2 (0-2-4)
for (;i<3;i++){
  digitalWrite(leds[i+i],HIGH); // Un número siempre va a ser par si 2x 
  delay(300);
  digitalWrite(leds[i+i],LOW);
  delay(300);  
   } 

 i=0;
 

    //  Ejercicio #3 (Aleatorio)
    
 i = random(6); // variable random
  digitalWrite(leds[i],HIGH); // La forma aleatoria para encender los leds.
  delay(200);
  digitalWrite(leds[i],LOW); // La forma aleatoria para encender los leds.
  delay(200);
  

 
 
}
