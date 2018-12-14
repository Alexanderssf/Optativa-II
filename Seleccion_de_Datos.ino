
#include "datos_entrenamiento.h" // amtriz principal 
#include"datos_test.h"

// variables que se van usar en elprograma

float matriz_final[60][5];
float matriz_final_1 [5];
float matriz_final_2 [5];
float matriz_final_3 [5];
float dist = 0;
float dist_total = 0;
float dist_2 = 0;
float dist_total_2 = 0;
float dist_3 = 0;
float dist_total_3 = 0;
float vec_dist_1[40];
float vec_c_dist_1[40];
float vec_divi_1[40];
float vec_dist_2[40];
float vec_c_dist_2[40];
float vec_divi_2[40];
float vec_dist_3[40];
float vec_c_dist_3[40];
float vec_divi_3[40];
int i; // variable columnas
int j;  // variable  filas
float mayor;
float divi;
int cont;
float mayor_2;
float divi_2;
int cont_2;
float mayor_3;
float divi_3;
int cont_3;
int cont_total;
int cont_f = 0;
float promedio; // variable de promedio
float suma = 0; // variable para suamatoria
int on = 0, a = 0, b = 0, total = 0;
float result;



void setup() {
  Serial.begin(9600);
  
  float r=0.35;/////RADIO
  float r1=0.42;////RADIO
  
  for (i = 0; i <= 3; i++) {  // para recorrer las columnas
    for ( j = 0; j <= 39; j++) {   // para recorrer las filas
      suma +=  matriz[j][i]; // se guarda en la variable
      promedio = suma / 40.0;   // la suma total se divide para el numero de datos
    }
    matriz_final_1[i] = promedio;
    matriz_final_1[4] = 1;
    suma = 0;      // se reinicia la suma
    promedio = 0;
    for ( j = 40; j <= 79; j++) {   // para recorrer las filas
      suma +=  matriz[j][i]; // se guarda en la variable
      promedio = suma / 40.0;   // la suma total se divide para el numero de datos
    }
    matriz_final_2[i] = promedio;
    matriz_final_2[4] = 2;
    suma = 0;      // se reinicia la suma
    promedio = 0;
    for ( j = 80; j <= 119; j++) {   // para recorrer las filas
      suma +=  matriz[j][i]; // se guarda en la variable
      promedio = suma / 40.0;   // la suma total se divide para el numero de datos
    }
    matriz_final_3[i] = promedio;
    matriz_final_3[4] = 3;
    suma = 0;      // se reinicia la suma
    promedio = 0;
  }



  for ( int k = 0; k <= 39; k++) {   // para recorrer las filas
    for (int l = 0; l <= 3; l++) {  // para recorrer las columnas
      dist = dist + pow(matriz[k][l] - matriz_final_1[l], 2);
    }
    dist_total = sqrt(dist);
    vec_dist_1[k] = dist_total;
    vec_c_dist_1[k] = dist_total;
    dist = 0;
    dist_total = 0;
  }
  for (int z = 0; z < 40; z++) {
    if (vec_c_dist_1[z] > mayor) { //
      mayor = vec_c_dist_1[z];
    }
  }
  for (int z = 0; z < 40; z++) {
    divi = vec_dist_1[z] / mayor;
    vec_divi_1[z] = divi;
  }
  for (int z = 0; z < 40; z++) {
    if (vec_divi_1[z] >= r && vec_divi_1[z] <= r1 ) { //
      cont++;
    }
  }



  for ( int k = 40; k <= 79; k++) {   // para recorrer las filas
    for (int l = 0; l <= 3; l++) {  // para recorrer las columnas
      dist_2 = dist_2 + pow(matriz[k][l] - matriz_final_2[l], 2);
    }
    dist_total_2 = sqrt(dist_2);
    vec_dist_2[k - 40] = dist_total_2;
    vec_c_dist_2[k - 40] = dist_total_2;
    dist_2 = 0;
    dist_total_2 = 0;
  }
  for (int z = 0; z < 40; z++) {
    if (vec_c_dist_2[z] > mayor_2) { //
      mayor_2 = vec_c_dist_2[z];
    }
  }
  for (int z = 0; z < 40; z++) {
    divi_2 = vec_dist_2[z] / mayor_2;
    vec_divi_2[z] = divi_2;
  }
  for (int z = 0; z < 40; z++) {
    if (vec_divi_2[z] >= r && vec_divi_2[z] <= r1) { //
      cont++;
    }
  }


  
  for ( int k = 80; k <= 119; k++) {   // para recorrer las filas
    for (int l = 0; l <= 3; l++) {  // para recorrer las columnas
      dist_3 = dist_3 + pow(matriz[k][l] - matriz_final_3[l], 2);
    }
    dist_total_3 = sqrt(dist_3);
    vec_dist_3[k - 80] = dist_total_3;
    vec_c_dist_3[k - 80] = dist_total_3;
    dist_3 = 0;
    dist_total_3 = 0;
  }
  for (int z = 0; z < 40; z++) {
    if (vec_c_dist_3[z] > mayor_3) { //
      mayor_3 = vec_c_dist_3[z];
    }
  }
  for (int z = 0; z < 40; z++) {
    divi_3 = vec_dist_3[z] / mayor_3;
    vec_divi_3[z] = divi_3;
  }
  for (int z = 0; z < 40; z++) {
    if (vec_divi_3[z] >= r && vec_divi_3[z] <= r1) { //
      cont++;
    }
  }

  
 
  matriz_final[cont][5];
  for (int z = 0; z < 40; z++) {
    if (vec_divi_1[z] >= r && vec_divi_1[z] <= r1) { //
      cont_f++;
      for (int x = 0; x <= 3; x++) {
        matriz_final[cont_f - 1][x] = matriz[z][x];
        matriz_final[cont_f - 1][4] = 1;
      }
    }
  }
  for (int z = 0; z < 40; z++) {
    if (vec_divi_2[z] >= r && vec_divi_2[z] <= r1) { //
      cont_f++;
      for (int x = 0; x <= 3; x++) {
        matriz_final[cont_f - 1][x] = matriz[z + 40][x];
        matriz_final[cont_f - 1][4] = 2;
      }
    }
  }
  for (int z = 0; z < 40; z++) {
    if (vec_divi_3[z] >= r && vec_divi_3[z] <= r1) { //
      cont_f++;
      for (int x = 0; x <= 3; x++) {
        matriz_final[cont_f - 1][x] = matriz[z + 80][x];
        matriz_final[cont_f - 1][4] = 3;
      }
    }
  }
  Serial.print("Datos obtenidos = ");Serial.println(cont);
  for ( int k = 0; k < cont; k++) {   // para recorrer las filas
    for (int l = 0; l <= 4; l++) {  // para recorrer las columnas
      Serial.print(matriz_final[k][l]);
        Serial.print(',');
      }
      Serial.println(' ');
    }
  }


  
  void loop() {
  if (on == 0) {
    for (int i = 0; i <= 29; i++) {
      result = knn(cont, 5, 3, 3, prueba[i]);
      if (result == prueba[i][4]) {
        a++;
      }
      else {
        b++;
      }
    }
    Serial.println("Ya comprobados con la matriz prueba ");
    Serial.println("Aciertos: ");
    Serial.println(a);
    Serial.println("Erroneos: ");
    Serial.println(b);

    total = (a * 100) / 30;
    Serial.println("Eficiencia");
    Serial.println(total);

    on = 1;
  }
}


////// ///////////////////usamos knn ///////////////////////////////////

float knn (int fila, int col, int k, int label, float datos[]) {
  int c = 0; // movernos en columnas
  int f = 0; // movernos en fila
  float k_vecinos_dist[k]; // vector de almacenamiento de k distancias menores
  float etiquetas [2][label]; // matriz y conteo de etiquetas
  float distk = 0; // variable que almacena cada distancia
  float dist_totalk = 0; // varaible para almacenamiento de distancia
  // llenar vector k_vecinos_dist con valores altos
  float eti_menor[k]; //vector de etiquetas de distancia menor
  int k_cont = 0;
  int i = 0;
  float clase; // retornar etiqueta
  float comparacion; // comparar k-vecino mayor
  for (; c < k; c++) {
    k_vecinos_dist[c] = 2000.0 + c; // valores altos y ordenados
  }
  c = 0; // reiniciar varaible
  // llenar matriz etiquetas
  for (; c < label; c++) {
    etiquetas[0][c] = c + 1; // lleno con valores de etiqueta
    etiquetas[1][c] = 0; // lleno con el conteo de etiqueta
  }
  c = 0; //renicio variable
  // la distacia mas corta del nuevo punto hacia la matriz

  for (; f < fila; f++) {
    for (; c < col - 1; c++) {
      distk = distk + pow((matriz_final[f][c] - datos[c]), 2); // distancia entre dos puntos
    }
    dist_totalk = sqrt(distk); // raiz de la formula
    // Serial.println(dist_total);
    for (; k_cont < k; k_cont++) { // determinar las k distancias menores y ordenarlas
      if (dist_totalk < k_vecinos_dist[k_cont]) {
        k_vecinos_dist[k_cont] = dist_totalk; // asignar nuevo valor a vector de distancias menores
        eti_menor[k_cont] = matriz_final[f][col - 1]; // col =5 , 4
      }
    }
    k_cont = 0;
    distk = 0;
    dist_totalk = 0;
    c = 0;
  } //for fila

  // seleccion de los k vecino
  for (; c < label; c++) {
    for (; k_cont < k; k_cont++) { // recorro cada posicion de eti_menor y comparo con etiquetas y cuento si son iguales
      if (etiquetas[0][c] == eti_menor[k_cont]) {
        i++;
        etiquetas[1][c] = i;
      }
    }
    k_cont = 0;
    i = 0;
  }
  c = 1;
  comparacion = etiquetas[1][0];
  clase = etiquetas[0][0];
  for (; c < label; c++) {
    if (etiquetas[1][c] > comparacion) { // comparacion entre valores de suma de etiqueta
      clase = etiquetas[0][c];
      comparacion = etiquetas[1][c];
    }
  }
  comparacion = 0;
  c = 0;
  return clase;
}
