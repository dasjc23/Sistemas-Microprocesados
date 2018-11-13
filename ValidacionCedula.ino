/**
 *        UNIVERSIDAD TECNICA DEL NORTE
 *                FICA-CIERCOM
 *          Sistemas Microprocesados
 *
 *Juan Carlos Tapia 
 *13 de Noviembre de 2018
 *
 *Validar una cédula ecuatoriana.
 */

String ced;
void setup() {
    Serial.begin(9600);
}

void loop() {

// Aquí se presenta como la respuesta va según que cédula se digita. El proceso no solo tiene 2 variables
//sino que al poner un doble if nos aseguramos de que va a existir un mensaje coherente para valorar según nuestra 
//restriccion.

  if(Serial.available()>0){
    String ced=Serial.readString();
    if(ValFormato(ced)){
        validacion(ced) ? Serial.println("Cédula Válida"):Serial.println("Cédula Inválida");  
      }
    else{
      Serial.println("Ingrese una valor de cédula real");
      }
    Serial.println(cedula); 
    }}

 // 1ero verificamos que se escriba un formato válido de cédula antes de validar.
bool ValFormato(String ced ){
    if(ced.length()!=11)
      return false;
    for (int i = 0; i < 11; i++){
      if(!isDigit(ced.charAt(i)) && i!=9)
        return false;
      if(ced.charAt(i)!='-' && i==9)
        return false;
      }
    return true;
  }
  
/*  Para validar una cédula necesitamos entender ciertos características antes de programar.
 *      Los 2 primeros digitos no seran mayores a 24 ni menores a 0
 *      El 3er digito debe ser menor a 6
 *      Los siguientes hasta el 9no son un número consecutivo
 *      El 10mo es un dígito verificador
 *      Para este digito usaremos un módulo.
 */
 
bool validacion(String ced){
  int prov =  ced.substring(0,2).toInt();
  if(prov<=0 || prov>24)
    return false;
  int serie =  ced.substring(2,3).toInt();
  if(serie<0 || serie>=6 )
    return false;    
  ced.replace("-","");
  int suma=0;
  int coef[9]={2,1,2,1,2,1,2,1,2};
  for(int i = 0;  i < 9; i ++){
    int valor = coef[i]*ced.substring(i,i+1).toInt();
    if(valor>=10){
      valor = String(valor).substring(0,1).toInt()+String(valor).substring(1,2).toInt();
      }
    suma+=valor;
    }
    int verificador = (suma%10)==0 ? (suma%10):10-(suma%10);     
    return ced.substring(9).toInt() == verificador ? true:false;
  }  
  
