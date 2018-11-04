/*
 *      Universidad Técnica del Norte
 *              Fica-CIERCOM
 *       Sistemas Microprocesados
 *       
 * Juan Carlos Tapia
 * Deber Display 2
 * Realizar un programa que medienta un pulsador se aumente el valor de un contador (1 al 40)...
 * ...y mediante otro pulsador se reste ese valor. 
 * El visualización del proceso se lo hace en displays
 * 
 */
int A=5;
int B=4;
int C=3;
int D=2;
int b1=6;
int b2=7;
int i=0;
int dec=9;
int uni=8;
int decenas;
int unidades;

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(dec,OUTPUT);
  pinMode(uni,OUTPUT);
  delay(200);

}

//  Parte del contador que aumenta en cada pulso hasta el 40.
void loop() {
  if(digitalRead(b1)==HIGH){
    delay(200);
    if(i<40){
      i++;
      decenas=i/10;
      unidades= i-(decenas*10);
        
    }
   else{
      i=0;
      unidades=0;
      decenas=0;
    }

  }

//  Parte del contador que resta hasta el 0.
 if(digitalRead(b2)==HIGH){
    delay(200);
    if(i>0){
      i--;
      decenas=i/10;
      unidades= i-(decenas*10);
        
    }
   else{
      i=0;
      unidades=0;
      decenas=0;
    }

  }

  
  digitalWrite(uni,HIGH);
  digitalWrite(dec,LOW);
  display(unidades);
  delay(100);

  digitalWrite(uni,LOW);
  digitalWrite(dec,HIGH);
  display(decenas);
  delay(100);
}

// Forma de mostrar números en el display.

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

  
