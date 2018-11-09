#include "datos_entrenamiento.h"
#include "datos_test.h"

int col=0;
int row=0;
float distancia;    // se crea una varialble tipo float para la distancia    
float dist_menor=1000; //almacenar distancia menor
float resultado;   // se crea una varialble tipo float para los resultados     
int dato=0;


void setup() {
  Serial.begin(9600);
 }

void loop() {

if (Serial.available() > 0) { //Si el usuario ingresa algo a la cx serial entra al programa
    dato = Serial.read();   // //dato toma el valor de lo que la cx serial 
  
  int k=1;
 
  while (k < dato){ // Mientras el dato no sea igual al ingresado siga operando
    
  for(;row<120;row++) {  // contador de filas (for lento)
    
     //Calculo de la deistancia mas corta a cada punto mediante formula 
     distancia= sqrt(pow((matriz[row][0]-prueba[15][0]),2)+
                     pow((matriz[row][1]-prueba[15][1]),2)+
                     pow((matriz[row][2]-prueba[15][2]),2)+
                     pow((matriz[row][3]-prueba[15][3]),2));

                   if(distancia < dist_menor){    //comparacion de las distancia para encontrar la mas corta
                   dist_menor=distancia;  //guardamos el valor de la distancia
                   
                   
                   } 
                }
                Serial.println(matriz[row][4]);  //el resultado igual a los puntos de la matriz  
                k++;      
            } 
             
        }
    }
