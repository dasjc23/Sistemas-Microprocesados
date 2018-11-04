/*
 *      Universidad Técnica del Norte
 *              Fica-CIERCOM
 *       Sistemas Microprocesados
 *       
 * Juan Carlos Tapia
 * Display 7 segmentos
 * Estimados estudiantes realizar un sistema que permita contar de forma automática 
 *(sin pulsador, el sistema inicia y empieza a contar sin necesidad de una actividad del usuario)... 
 * .. Del 1 al 200 mediante la multiplexación de displays.
 *
 * 
 */
int A=5;
int B=4;
int C=3;
int D=2;
int i=0;
int dec=9;
int uni=8;
int cen=10;
int decenas;
int unidades;
int centenas;

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(dec,OUTPUT);
  pinMode(uni,OUTPUT);
  pinMode(cen,OUTPUT);
  delay(200);

}

void loop() {

    if(i<200){
      i++;
      centenas= (i% 1000)/100;      // Aplica el razonamiento de la decena pero en un x10 mayor. (Intente solo i/100 pero me saltaba un error al llegar a los cientos)
      decenas= (i % 100)/10;       // El i % 100 nos devuelve la unidad y decena, por lo cual el /10 nos devuelve solo el entero de la decena.
      unidades= i % 10;           // Nos devuelv el entero de dividir por 10, osea la unidad.
        
    }
   else{
      i=0;
      unidades=0;
      decenas=0;
      centenas=0;
    }

      digitalWrite(uni,HIGH);
  digitalWrite(dec,LOW);
  digitalWrite(cen,LOW);
  display(unidades);
  delay(100);

     digitalWrite(uni,LOW);
  digitalWrite(dec,HIGH);
  digitalWrite(cen,LOW);
  display(decenas);
  delay(100);

      digitalWrite(uni,LOW);
  digitalWrite(dec,LOW);
  digitalWrite(cen,HIGH);
  display(centenas);
  delay(100); 
  
}

void display(int j){
  switch(j){

    case 0:
 //0
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);

  break;

    case 1:
  //1
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);

  break;
    case 2:
  //2
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);

  break;
  
    case 3:
  //3
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);

  break;
  
    case 4:
  //4
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);

  break;
  
    case 5:
  //5
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;

    case 6:
  //6
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);

  break;
  
    case 7:
  //7
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
 
  break;
  
    case 8:
  //8
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);

    break;
    
    case 9:
  //9
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);

   break;     
  }
}

  
