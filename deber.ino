#include "matriz.h"
int i;  // columnas
int j;  //filas
char dato;
void setup() {
  Serial.begin(9600);  // Inicializamos comunicación serie
  Serial.println("*******************OPCIONES********************");
  Serial.println(" ");
  Serial.println("Presione 1 para obtener el promedio de cada fila");
  Serial.println("Presione 2 para obtener el promedio de cada columna");
  Serial.println("Presione 3 para obtener numero mas alto de cada fila");
  Serial.println("Presione 4 para obtener numero mas bajo de cada columna");
  Serial.println("Presione 5 para obtener numero mas alto de toda la matriz");
  Serial.println("Presione 6 para obtener numero mas bajo de toda la matriz");
}


//**************************PROMEDIO FILAS*****************************

void (PromedioFilas) (void) {
  float SumaFila = 0;  // Declaramos variable de la suma de filas
  float PromedioFilas; // Declaramos variable del promedio de filas
  String Resultado;    // Declaramos variable de los resultados
  
  for (j = 0; j < 10; j++) //Se evalua cada fila de la matriz
  {
    for (i = 0; i < 4; i++) //Se evalua cada columna de la matriz
    {
      SumaFila = SumaFila + datos[j][i]; // Se suma todos los valores de fila
    }
    PromedioFilas=(SumaFila/4); // Se obtiene el promedio
    Resultado = String("El promedio de la fila " + String(j + 1) + " es: " + String(PromedioFilas)); // datos a mostrar en pantalla
    Serial.println(Resultado);  // impresion en pantalla
    SumaFila=0; //inicializamos nuevamente para que pase a la siguiente fila
  }
  Serial.println(" "); //imprimimos espacio en blanco
}



//**************************PROMEDIO COLUMNAS*****************************
void (PromedioColumnas) (void) {
  float SumaColumna = 0;   //Declaramos variable de la suma de columnas
  float PromedioColumnas;  // Declaramos variable del promedio de cada columna
  String Resultado;        // Declaramos variable de los resultados
  
  for (i = 0; i < 4; i++)  //Se evalua cada columna de la matriz
  {
    for (j = 0; j < 10; j++) //Se evalua cada fila de la matriz
    {
      SumaColumna = SumaColumna + datos[j][i];  //Se suma todos los valores de la columna
    }
    PromedioColumnas=(SumaColumna/10); // Se obtiene el promedio
    Resultado = String("El promedio de la columna " + String(i + 1) + " es: " + String(PromedioColumnas)); // datos a mostrar en pantalla
    Serial.println(Resultado); // impresion en pantalla
    SumaColumna =0; //inicializamos nuevamente para que pase a la siguiente columna 
  }
  Serial.println(" "); //imprimimos espacio en blanco
}



//**************************VALOR MAS ALTO DE CADA FILA*****************************
void(MasAltoFilas) (void){
  
int valorMaximo = 0;   //Declaramos variable de  valor maximo 
String Resultado;      // Declaramos variable de los resultados

   for (j = 0; j < 10; j++)  //Se evalua cada fila de la matriz
  {
    for (i = 0; i < 4; i++)  //Se evalua cada columna de la matriz
    {
      if (datos[j][i] > valorMaximo) {  //Comparacion de datos en cada fila
      valorMaximo = datos[j][i];        // guardo el dato mayor
      Resultado = String("el valor maximo de la fila " + String(j + 1) + " es: " + String(valorMaximo)); // datos a mostrar en pantalla
      }
     }
    valorMaximo=0;  //inicializamos nuevamente el valor para que pase a la siguiente fila
    Serial.println(Resultado);   // impresion en pantalla
   } 
   Serial.println(" ");  //imprimimos espacio en blanco
}



//**************************VALOR MAS BAJO DE CADA COLUMNA*****************************
void(MasBajoColumnas) (void){
  
int valorMinimo =99;   //Declaramos variable de  valor minimo 
String Resultado;      // Declaramos variable de los resultados

   for (i = 0; i < 4; i++)    //Se evalua cada columna de la matriz
  {
    for (j = 0; j < 10; j++)  //Se evalua cada fila de la matriz
    {
      if (datos[j][i] < valorMinimo) {  //Comparacion de datos en cada columna
      valorMinimo = datos[j][i];        // guardo el dato mayor
      Resultado = String("el valor minimo de la fila " + String(i + 1) + " es: " + String(valorMinimo)); // datos a mostrar en pantalla
      }
    }
    valorMinimo=0; //inicializamos nuevamente el valor para que pase a la siguiente columna
    Serial.println(Resultado);  // impresion en pantalla
  }
  Serial.println(" ");//imprimimos espacio en blanco
}



//**************************VALOR MAS ALTO DE TODA LA MATRIZ*****************************
void(MasAltoMat) (void){
  
int valorMaximo = 0; //Declaramos variable de  valor maximo 
String Resultado;    // Declaramos variable de los resultados

   for (j = 0; j < 4; j++) //Se evalua cada fila de la matriz
  {
    for (i = 0; i < 10; i++)  //Se evalua cada columna de la matriz
    {
      if (datos[i][j] > valorMaximo) { //Comparacion de datos por filas
      valorMaximo = datos[i][j];   // optenemos el valor maximo en cada fila y lo comparamos con las demas
     
      }
    } 
   }
   Resultado = String("el valor maximo de la Matriz  es: " + String(valorMaximo)); // datos a mostrar en pantalla
   Serial.println(Resultado); // impresion en pantalla
   Serial.println(" ");  //imprimimos espacio en blanco
 } 



//**************************VALOR MAS BAJO DE TODA LA MATRIZ*****************************
void(MasBajoMat) (void){
  
int valorMinimo =99; //Declaramos variable de  valor minimo 
String Resultado;    // Declaramos variable de los resultados

   for (i = 0; i < 4; i++)   //Se evalua cada columna de la matriz
   {
    for (j = 0; j < 10; j++)  //Se evalua cada fila de la matriz
    {
      if (datos[j][i] < valorMinimo) {  //Comparacion de datos por columnas
      valorMinimo = datos[j][i];  // optenemos el valor minimo en cada columna y lo comparamos con las demas
      }
    }
   }
   Resultado = String("el valor minimo de la Matriz es: " + String(valorMinimo));   // datos a mostrar en pantalla
   Serial.println(Resultado); // impresion en pantalla
   Serial.println(" "); //imprimimos espacio en blanco
 }
//*******************************FIN CASOS *****************************


void loop() {
  if (Serial.available() > 0) { //Si el usuario ingresa algo a la cx serial entra al programa
    dato = Serial.read();   // //dato toma el valor de lo que la cx serial 
    switch (dato) { //casos dependiendo del valor de del dato
      
      case '1':   //caso si el dato  es igual a 1
        Serial.println(" ");
        PromedioFilas();
        break;

      case '2':   //caso si el dato  es igual a 1
        Serial.println(" ");
        PromedioColumnas();
        break;

       case '3':   //caso si el dato  es igual a 1
        Serial.println(" ");
        MasAltoFilas();
        break;
        
      case '4':  //caso si el dato  es igual a 1
        Serial.println(" ");
        MasBajoColumnas();
        break;

      case '5':   //caso si el dato  es igual a 1
        Serial.println(" ");
        MasAltoMat();
        break;
        
      case '6':   //caso si el dato  es igual a 1
        Serial.println(" ");
        MasBajoMat();
        break;
      
    }
  }
}
