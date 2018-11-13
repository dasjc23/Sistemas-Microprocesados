/**
 *        UNIVERSIDAD TECNICA DEL NORTE
 *                FICA-CIERCOM
 *          Sistemas Microprocesados
 *
 *Juan Carlos Tapia 
 *13/11/2018
 *
 *Realizar un sistema que permite determinar el número de vocales dentro de una palabra.
 */

String palabra;  // Asignamos una variable del tipo string para nuestra palabra.
int i=0;
int j=0;
int vec=0; 

void setup() {
  Serial.begin(9600);  
}

void loop() {
  if(Serial.available()>0){
    palabra=Serial.readString();
    palabra.toLowerCase();
    vec=palabra.length();
    
for(;i<vec;i++){    //Este es el que va ir letra por letra a la palabra.

 // Aquí vamos a usar un OR el cual va ir viendo si las letras son iguales a las vocales de forma continua (==)     
  if (palabra.charAt(i)=='a' || palabra.charAt(i)=='e'  || palabra.charAt(i)=='i' || palabra.charAt(i)=='o' || palabra.charAt(i)=='u'){
      j=j+1;    
        }
    }
    Serial.println(j);
    i=0;
    j=0;
    
  }
  

}
