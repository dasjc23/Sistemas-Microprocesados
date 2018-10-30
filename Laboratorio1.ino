/*
*
*Nombre: Cristian Ruiz
*Fecha : 25/10/2018
*Tema:   Puertos Entrada/Salida
*/
int cont = 0;
void setup()
{
  for(int i = 0; i < 6; i ++){
    pinMode(i+8, OUTPUT);  
    }
  for(int i = 0; i < 5; i ++){
    pinMode(i+3, INPUT);  
    }
}
void loop()
{   
  int opciones = 0;
  for(int i = 0 ; i < 4 ; i ++){
    opciones += digitalRead(i+4) ==HIGH ? i+4:0;
    }
   
  switch (opciones){
    case 4:
      juego1();
      break;
    case 5:
      juego2();
      break;
    case 6:
      juego3();
      break;
    case 7:
      contador();     
      break;
    default:
      apagar();
      break;
    }
    
}
void contador(){
  imprimirBinario();
  if(digitalRead(3)){
      delay(250);
      cont = cont == 31 ? 0 : cont+1;
      imprimirBinario();
    }
  }
void imprimirBinario(){
  int aux = cont ;
  for (int j = 0 ; j < 6 ; j ++){            
      digitalWrite(13-j,aux%2);
      aux/=2;
    }          
  }
void apagar(){
  for(int i = 0; i < 6; i++)
    digitalWrite(8+i,LOW);
  }
void juego1(){
  for(int i = 0 ; i <= 2; i++){
    digitalWrite(i*2+9,HIGH);
    delay(200); 
    }
  for(int i = 2 ; i >= 0; i--){
    digitalWrite(i*2+9,LOW);
    delay(200); 
    }
  }
  
void juego2(){
  for(int i = 0 ; i <=2; i++){
    digitalWrite(i*2+8,HIGH);
    delay(200);
    digitalWrite(i*2+8,LOW);
    delay(200);  
    }
  }
void juego3(){
  for(int i = 0 ; i <=10; i++){
    int port = random(8,13);
    digitalWrite(port,HIGH);
    delay(100);
    digitalWrite(port,LOW);
    delay(100);  
    }
  }
