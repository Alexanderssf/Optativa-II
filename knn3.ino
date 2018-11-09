#include "datos_entrenamiento.h"
#include "datos_test.h"

int col=0;
int row=0;
float distancia;    // se crea una varialble tipo float para la distancia   
float distancia1;   // se crea una varialble tipo float para la distancia1 
float distancia2;   // se crea una varialble tipo float para la distancia2 
float dist_menor=1000; //almacenar distancia menor
float dist_menor1=800; //almacenar distancia menor1
float dist_menor2=600; //almacenar distancia menor2
float resultado;   // se crea una varialble tipo float para los resultados     
float resultado1;  // se crea una varialble tipo float para los resultados  
float resultado2;  // se crea una varialble tipo float para los resultados  


void setup() {
  Serial.begin(9600);
 }

void loop() {

  for(;row<120;row++) {  // contador de filas (for lento)
    
     //Calculo de la deistancia mas corta a cada punto mediante formula 
     distancia= sqrt(pow((matriz[row][0]-prueba[15][0]),2)+
                     pow((matriz[row][1]-prueba[15][1]),2)+
                     pow((matriz[row][2]-prueba[15][2]),2)+
                     pow((matriz[row][3]-prueba[15][3]),2));

                   if(distancia < dist_menor){    //comparacion de las distancia para encontrar la mas corta
                   dist_menor=distancia;  //guardamos el valor de la distancia
                   resultado = matriz[row][4];  //el resultado igual a los puntos de la matriz
                   
                   }         
     //Calculo de la segunda deistancia  mas corta a cada punto mediante formula               
     distancia1= sqrt(pow((matriz[row][0]-prueba[15][0]),2)+
                      pow((matriz[row][1]-prueba[15][1]),2)+
                      pow((matriz[row][2]-prueba[15][2]),2)+
                      pow((matriz[row][3]-prueba[15][3]),2));

                   if(distancia1<dist_menor1&&distancia1>dist_menor){  //comparacion de las distancia para encontrar la mas corta
                   dist_menor1=distancia1;   //guardamos el valor de la distancia
                   resultado1= matriz[row][4];   //el resultado igual a los puntos de la matriz
                   
                   }
     //Calculo de la tercera deistancia  mas corta a cada punto mediante formula                  
    distancia2= sqrt(pow((matriz[row][0]-prueba[15][0]),2)+
                     pow((matriz[row][1]-prueba[15][1]),2)+
                     pow((matriz[row][2]-prueba[15][2]),2)+
                     pow((matriz[row][3]-prueba[15][3]),2));

                   if(distancia2<dist_menor2&&distancia2>dist_menor1){  //comparacion de las distancia para encontrar la mas corta
                   dist_menor2=distancia2;   //guardamos el valor de la distancia
                   resultado2= matriz[row][4];   //el resultado igual a los puntos de la matriz
                   
        }
          
     } 
     //Impresion de la distancia mas corta y el grupo al que pertenece  
     Serial.print("distancia = ");            
     Serial.print(dist_menor);
     Serial.print(',');
     Serial.print("pertenece al grupo ");
     Serial.println(resultado);
     delay(1000);
     
     //Impresion de la distancia1 mas corta y el grupo al que pertenece  
     Serial.print("distancia1= "); 
     Serial.print(dist_menor1);
     Serial.print(',');
     Serial.print("pertenece al grupo ");
     Serial.println(resultado1);
     delay(1000);

     //Impresion de la distancia2 mas corta y el grupo al que pertenece  
     Serial.print("distancia2= "); 
     Serial.print(dist_menor2);
     Serial.print(',');
     Serial.print("pertenece al grupo ");
     Serial.println(resultado2);
     delay(1000);  
    
 }
