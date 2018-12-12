/**
 * PROYECTO BIMESTRAL
 */
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(13,12,11,10,9,8);
int passwds[5]={11111,22222,33333,44444,99999};
String users [5]={"CR","PZ","JT","PR","AD"};
String names [5]={"Cris R.","Paul Z.","JuanK","Paul R.","Master"};
int states [5] = {0,0,0,0,0}; 
String loggeduser = "";
String temppasswd = "";
String alarmpasswd = "";
const int rows=3;
const int cols=3;
const char hexaKeys[rows][cols]={
    {'7','8','9'},
    {'4','5','6'},
    {'1','2','3'}
  };
 bool admin = false;
 int count = 0;
 int user = -1;
 String id;
 String newpasswd;
 const byte rowpins[rows]={7,6,5};
 const byte colpins[cols]={4,1,0};
 bool blocked = false;
 bool entering = false;
 bool commingout = false; 
 bool counteractived = false;
 Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowpins,colpins,3,3);
 int sys = 0;
 const String msg =  "Presione:1 vez/INGRESO-SALIDA,2 veces/CAMBIO PASSWD,3 veces/ACTIVAR/DESACTIVAR ALARMA,4 veces/CONTADOR,5 veces/INICIO";
 const String msg2 = "Presione tecla: 1)Cris R. 2)Paul Z. 3)Juank 4)Paul R. 5)Cancelar";
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  attachInterrupt(0,control,LOW);
  pinMode(3,OUTPUT);
  //attachInterrupt(1,counter,LOW);   
  
}

void loop() {
  if(counteractived){
    counter();
    lcd.setCursor(0,1);
    lcd.print("Visitantes :" +String(count));  
  }else{
    clear2();
  }
  if(sys==0){
    lcd.setCursor(0,0);
    message(msg);
  }
  if(sys==1){
    char key = customKeypad.getKey();
    readPasswd(key);
  }
  if(sys==2){
    if(admin){
      if(user==-1){
        lcd.setCursor(0,0);
        lcd.print("1CR/2PZ/3JT/4PR");
        char key5 = customKeypad.getKey();
        if(key5){
          user = String(key5).toInt() - 1;
        }
      }
      if(user > (-1) ){
        if(user < 4 ){
          if(newpasswd.length()<5){
            clear1();
            lcd.setCursor(0,0);
            lcd.print("Pass: ");
            char key4 = customKeypad.getKey();
            newpasswd+=String(key4);
          }else{
            //admin=false; 
            changePasswd();
            sys=0;
            id="";
            newpasswd="";
            user=-1;
          }
        }else{
          clear1();
          lcd.setCursor(0,0);
          lcd.print(id+" no existe");
          delay(2000);
          sys=0;
          id="";
          newpasswd="";
          user=-1;     
        }
      }  
    }else{
      char key2 = customKeypad.getKey();
      readPasswd(key2);
    }
  }
  if(sys==3){
    if(!blocked){
      if(alarmpasswd.length()<5){
        char key7 = customKeypad.getKey();
        if(key7){
          lcd.print("*");
          alarmpasswd+=String(key7);   
        }
      }else{
        temppasswd="";
        blocked=true;
        clear1();
        lcd.setCursor(0,0);
        lcd.print("ALARMA ACTIVA:");
      }
    }else{
      if (analogRead(0)>512 || analogRead(1)>512){
        digitalWrite(3,HIGH);
      }
      if(temppasswd.length()<5){
        char key8 = customKeypad.getKey();
        if(key8){
          temppasswd+=String(key8);      
        }  
      }else{
        if(alarmpasswd==temppasswd){
          blocked=false;
          sys=0;
          temppasswd="";
          alarmpasswd=""; 
          clear1();
          lcd.setCursor(0,0);
          lcd.print("ALARMA DESACTIVADA");
          digitalWrite(3,LOW);          
          delay(2000);
          
        }else{
          
          clear1();
          lcd.setCursor(0,0);
          lcd.print("CLAVE INCORRECTA");
          delay(2000);
          clear1();
          lcd.setCursor(0,0);
          lcd.print("ALARMA ACTIVA:");
          temppasswd="";
          //alarmapasswd=""; 
        }
      }
    }
  }
  
  if(sys==4){
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print(counteractived ? "Desactivar Contador?":"Activar Contador?");
    lcd.setCursor(0,1);
    lcd.print("1)SI   2)NO");
    char key = customKeypad.getKey();
    if(key){
      if(String(key).toInt()==1){
        counteractived = !counteractived;  
        count=0;
        lcd.clear();
        sys=0;
      }
      if(String(key).toInt()==2){
        sys=0;
        lcd.clear();
      }
    }
  }
}
void changePasswd(){
  bool repeat = false;
  for(int i = 0; i < 5; i++){
    int pass = newpasswd.toInt();
    if(passwds[i]==pass){
      repeat =true;
      break;
    }
  }
  if(repeat){
    clear1();
    lcd.setCursor(0,0);
    lcd.print("Clave Repetida!");
    delay(2000);
  }else{
    passwds[user]=newpasswd.toInt();
    clear1();
    lcd.setCursor(0,0);
    lcd.print("Clave Actualizada");
    delay(2000);  
  }
}
void control(){
  temppasswd = "";
  admin=false;
  if(!blocked){
    switch(sys){
      case 0:
        clear1(); 
        lcd.setCursor(0,0);
        lcd.print("PASS: ");
        sys++;
      break;
      case 1:
        clear1(); 
        lcd.setCursor(0,0);
        lcd.print("MASTER: ");
        sys++;
      break;
      case 2:
        clear1(); 
        lcd.setCursor(0,0);
        lcd.print("PWD ALARMA: ");
        sys++;
      break;
      case 3:
        sys++;
      break;
      case 4:
        sys=0;
      break;
    }   
  }
}
void enter(){
  int passwd = temppasswd.toInt();
  bool success = false;
  for(int i = 0; i < 5; i++ ){
    
    if(passwds[i]==passwd){
      admin = i == 4 ? true:false;
      loggeduser=names[i];
      clear1();
      lcd.setCursor(0,0);
      if(!admin)
        lcd.print(states[i]==0 ? loggeduser+" ingreso":loggeduser+" sali");
      else{
        lcd.print("Clave Master ok!") ; 
      }
      states[i]=1 - states[i];
      success=true; 
      admin = false;
      delay(2000);
      break;
    }
  }
  if(!success){
    clear1();
    lcd.setCursor(0,0);
    lcd.print("Clave no existe");
    delay(2000);
  }
  sys = 0;
  temppasswd = "";
}
void counter(){
  delay(250);
  if(analogRead(0)>512){
    if(commingout){
      commingout=false;
    }else{
      entering=true;
    }
  }
  if(analogRead(1)>512){
    if(entering){
      entering=false;
      count++;
    }else{
      commingout=true;
    }
  }
}
void message(String msgx){
    String blancos = "";
    for (int i = 0; i <= msgx.length(); i++){        
        if(i+15==msgx.length())
          blancos+=" ";
        if(sys==0){
          lcd.setCursor(0,0);
          lcd.print(msgx.substring(i,i+16)+ blancos);
          delay(100);
        }
    }
}
void readPasswd(char key){
  if(key){
    lcd.print("*");
    temppasswd+= String(key);
    if(temppasswd.length()==5){
      if(sys==1){
        enter();
      }
      if(sys==2){
        int pass=temppasswd.toInt();
        if(passwds[4]==pass){
          admin=true;
          //lcd.setCursor(14,1);
          //lcd.print("ok");
        }else{
          clear1();
          lcd.setCursor(0,0);
          lcd.print("No Autorizado");
          delay(2000);
          sys=0;
          temppasswd="";
        }
      }
    }
  }  
}
int searchUser(String id){
  int success= -1;
  for(int i = 0; i < 4 ; i++){
    if(users[i]==id){
      success=i;
      break;  
    }
  }
  if(success=-1)
    sys = 0;
  return success;
}
void clear1(){
  lcd.setCursor(0,0);
  lcd.print("                  ");
  }
void clear2(){
  lcd.setCursor(0,1);
  lcd.print("                  ");
  }
