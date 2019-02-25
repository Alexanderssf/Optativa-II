#include "datos_entrenamiento.h"
#include"datos_test.h"
// definicion de matricez de CNN
float matriz_s [60][5];  // datos validos
float matriz_r [20][5]; // datos rnn
float matriz_d [90][5]; // datos de desecho
float matriz_dr [90][5]; // datos de desecho
int col = 0; // variable de recorrido de col de matriz de mayor volumen
int fil;  // variable de recorrido de filas de matriz de mayor volumen
int col_s = 0; // variable que recorre columnas para matriz s
int fil_s = 0; // variable que recorre filas matriz s
int fil_s1 = 3; // variable que recorre matriz s cuando realiza knn con matriz d
int fil_d = 0; // variable que recorre filas en matriz d
int col_d = 0; // variable que recorre columnas en matriz d
float promedio; // variable de promedio
float suma = 0; //variable parcial para encontrar distancia mas corta
int etiqueta = 1; // variable para ciclo de conteo entre etiquetas
int i = 0; // variable de seleccion de etiquetas
int j = 0;
float dist = 0; // variable parcial para encontrar distancia mas corta
float dist_total; // variable global para almacenar distancia mas corta
float dist_mayor = 2000; // variable para encontrar la distancia menor
float label; // variable que almacena etiqueta de distancia mas corta
////////////////////////////////////////////////////////////////////////
int on = 0, a = 0, b = 0, total = 0;
float result;
////////////////////////////////////////////////////////////////////////
int se1;
int se2;
int se3;
int sa1;
int sa2;
int sa3;
///////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  // ciclo que permite encontrar los puntos medios por cada etiqueta
  //recorre cada posicion de filas por etiquetas y encuentra el promedio de cada
  // columna
  for (i = 0; i <= 3; i++) {  // para recorrer las columnas
    for ( j = 0; j <= 29; j++) {   // para recorrer las filas
      suma +=  matriz[j][i]; // se guarda en la variable
      promedio = suma / 30.0;   // la suma total se divide para el numero de datos
    }
    matriz_s[0][i] = promedio;
    matriz_s[0][4] = 1;
    suma = 0;      // se reinicia la suma
    promedio = 0;
    for ( j = 30; j <= 59; j++) {   // para recorrer las filas
      suma +=  matriz[j][i]; // se guarda en la variable
      promedio = suma / 30.0;   // la suma total se divide para el numero de datos
    }
    matriz_s[1][i] = promedio;
    matriz_s[1][4] = 2;
    suma = 0;      // se reinicia la suma
    promedio = 0;
    for ( j = 60; j <= 89; j++) {   // para recorrer las filas
      suma +=  matriz[j][i]; // se guarda en la variable
      promedio = suma / 30.0;   // la suma total se divide para el numero de datos
    }
    matriz_s[2][i] = promedio;
    matriz_s[2][4] = 3;
    suma = 0;      // se reinicia la suma
    promedio = 0;
  }
  /*
     Metodo para implementar el algoritmo CNN dentro de Arduino
     La matriz almacenada en el archivo .h se encontraron los puntos medios
     por cada etiqueta
     se realiza k-nn por cada punto de la matriz de mayor volumen teniendo como matriz
     de entrenamiento a la matriz que solo contiene los puntos medios llamada matriz s
     Cuando un dato ingresa desde la matriz de mayor volumen a knn y es clasificado adecuadamente se almacane en matriz d
     caso contrario en matriz s.
     con la matriz d con datos, se vuelve a realizar knn con matriz de entrenamiento la matriz s, si sigue
     clasificando adecuadamente se almacena en martiz d, caso contrario matriz s
     Se conserva matriz s, el resto se descarta
  */
  // metodo de knn con matriz de mayor volumen y knn con matriz s  de entrenamiento

  for (; fil < 90; fil++) { // ciclo que recorre por cada fila de matriz de mayor volumen
    for (; fil_s < 3; fil_s++) { // recorre por filas de la matriz s
      for (; col_s < 4; col_s++) { // recorre por filas de ambas matrices
        dist = dist + pow(matriz[fil][col_s] - matriz_s[fil_s][col_s], 2); // distancia entre dos puntos
      }
      dist_total = sqrt(dist); // distancia entre dos puntos
      if (dist_total < dist_mayor) { // comparacion para encontrar distancia menor
        dist_mayor = dist_total;
        label = matriz_s[fil_s][4]; //
      }// endif
      dist = 0; // por cada lectura de fila se encera distancia
      col_s = 0; //vuelve a cero para leer nuevamente columnas
    }//end for fil_S
    fil_s = 0;
    dist_mayor = 2000;
    // si el algoritmo knn clasifico correctamente, almacena en matriz d
    // caso contrario en matriz s
    if (label == matriz[fil][4]) {
      // almacena los datos en matriz d
      for (; col_d < 5; col_d++) {
        matriz_d[fil_d][col_d] = matriz[fil][col_d];
      }
      col_d = 0;
      fil_d++;
    }
    else {
      // almancena los datos en matriz s
      for (; col_s < 5; col_s++) {
        matriz_s[fil_s1][col_s] = matriz[fil][col_s];
      }
      col_s = 0;
      fil_s1++;
    }
  }
  //////////////////////////////////////////////////
  // una vez realizado el proceso en matriz de alto volumen
  // se realiza el mismo proceso con matriz d
  fil = 0;
  fil_s = 0;
  col_s = 0;
  for (; fil < fil_d; fil++) { // recorre los datos filas de matriz d
    for (; fil_s < 3; fil_s++) { // recorre los datos de filas de matriz s
      for (; col_s < 4; col_s++) { // recorre las columnas de ambas matrices
        dist = dist + pow(matriz_d[fil][col_s] - matriz_s[fil_s][col_s], 2); //distancia entre dos puntos
      }
      dist_total = sqrt(dist); // distancia entre dos puntos
      if (dist_total < dist_mayor) { // compara con distancia menor
        dist_mayor = dist_total;
        label = matriz_s[fil_s][4]; // almacena etiqueta de distancia menor
      }// endif
      dist = 0;
      col_s = 0;
    }//end for fil_S
    fil_s = 0;
    dist_mayor = 2000;
    // si clasifica correctamente el sistema no realiza ninguna accion
    if (label == matriz_d[fil][4]) {
    }
    // si clasifica de forma erronea, almacena en matriz s
    else {
      for (; col_s < 5; col_s++) {
        matriz_s[fil_s1][col_s] = matriz[fil][col_s];
      }
      col_s = 0;
      fil_s1++;
    }
  }
  // imprime los valores almacenados en matriz s
  fil_s = 0;
  for (; fil_s < fil_s1; fil_s++) {
    for (; col_s < 5; col_s++) {
      Serial.print(matriz_s[fil_s][col_s]);
      Serial.print(',');
    }
    col_s = 0;
    Serial.println(' ');
  }

  //////////////////////////////////////////////////////////////////////
  for (j = 0 ; j < fil_s ; j ++) {    // para recorrer las filas
    if (matriz_s [j] [ 4 ] == 1 ) {
      se1 ++;
    } else if (matriz_s [j] [ 4 ] == 2 ) {
      se2 ++;
    } else if (matriz_s [j] [ 4 ] == 3 ) {
      se3 ++;
    }
  }
  Serial.println (se1);
  Serial.println (se2);
  Serial.println (se3);
  ///////////////////Ordenar matriz///////////////
  float mayor0;
  float mayor1;
  float mayor2;
  float mayor3;
  float mayor4;
  int x = 0;
  for ( i = 0; i <= 9; i++) {   // leer las filas
    for ( x = 0; x <= 9; x++) {   // usamos para crear un for anidado y un bucle
      if (matriz_s[i][4] > matriz_s[x][4]) { // si numero actual es mayor a numero siguiente
        mayor0 = matriz_s[i][0];     // auxiliar es igual a numero actual
        mayor1 = matriz_s[i][1];
        mayor2 = matriz_s[i][2];
        mayor3 = matriz_s[i][3];
        mayor4 = matriz_s[i][4];
        matriz_s[i][0] = matriz_s[x][0];
        matriz_s[i][1] = matriz_s[x][1];
        matriz_s[i][2] = matriz_s[x][2];
        matriz_s[i][3] = matriz_s[x][3];
        matriz_s[i][4] = matriz_s[x][4];    // numero actual va a ser iguala numero siguiente
        matriz_s[x][0] = mayor0;   // numero siguiente va a ser iguala  auxiliar
        matriz_s[x][1] = mayor1;
        matriz_s[x][2] = mayor2;
        matriz_s[x][3] = mayor3;
        matriz_s[x][4] = mayor4;
      }
    }
  }
  ////////////////////////////////////////////////
  for (i = 0; i <= 3; i++) {  // para recorrer las columnas
    for ( j = 0; j <= 3 ; j++) {  // para recorrer las filas
      suma +=  matriz_s[j][i]; // se guarda en la variable
      promedio = suma / 4.0;   // la suma total se divide para el numero de datos
    }
    matriz_r[2][i] = promedio;
    matriz_r[2][4] = 3;
    suma = 0;      // se reinicia la suma
    promedio = 0;
    for ( j = 4; j <= 6; j++) {   // para recorrer las filas
      suma +=  matriz_s[j][i]; // se guarda en la variable
      promedio = suma / 3.0;   // la suma total se divide para el numero de datos
    }
    matriz_r[1][i] = promedio;
    matriz_r[1][4] = 2;
    suma = 0;      // se reinicia la suma
    promedio = 0;
    for ( j = 7; j <= 7; j++) {   // para recorrer las filas
      suma +=  matriz_s[j][i]; // se guarda en la variable
      promedio = suma / 1.0;   // la suma total se divide para el numero de datos
    }
    matriz_r[0][i] = promedio;
    matriz_r[0][4] = 1;
    suma = 0;      // se reinicia la suma
    promedio = 0;
  }
  /////////////////////
  for (int z = 0; z < 3; z++) {
    for (int x = 0; x < 5; x++) {
      Serial.print(matriz_r[z][x]);
      Serial.print(',');
    }
    Serial.println(' ');
  }
  ///////////////////////////////////////////////////////////
  for (; fil < 90; fil++) { // ciclo que recorre por cada fila de matriz de mayor volumen
    for (; fil_s < 3; fil_s++) { // recorre por filas de la matriz s
      for (; col_s < 4; col_s++) { // recorre por filas de ambas matrices
        dist = dist + pow(matriz[fil][col_s] - matriz_r[fil_s][col_s], 2); // distancia entre dos puntos
      }
      dist_total = sqrt(dist); // distancia entre dos puntos
      if (dist_total < dist_mayor) { // comparacion para encontrar distancia menor
        dist_mayor = dist_total;
        label = matriz_r[fil_s][4]; //
      }// endif
      dist = 0; // por cada lectura de fila se encera distancia
      col_s = 0; //vuelve a cero para leer nuevamente columnas
    }//end for fil_S
    fil_s = 0;
    dist_mayor = 2000;
    // si el algoritmo knn clasifico correctamente, almacena en matriz d
    // caso contrario en matriz s
    if (label == matriz[fil][4]) {
      // almacena los datos en matriz d
      for (; col_d < 5; col_d++) {
        matriz_dr[fil_d][col_d] = matriz[fil][col_d];
      }
      col_d = 0;
      fil_d++;
    }
    else {
      // almancena los datos en matriz s
      for (; col_s < 5; col_s++) {
        matriz_r[fil_s1][col_s] = matriz[fil][col_s];
      }
      col_s = 0;
      fil_s1++;
    }
  }
  //////////////////////////////////////////////////
  // una vez realizado el proceso en matriz de alto volumen
  // se realiza el mismo proceso con matriz d
  fil = 0;
  fil_s = 0;
  col_s = 0;
  for (; fil < fil_d; fil++) { // recorre los datos filas de matriz d
    for (; fil_s < 3; fil_s++) { // recorre los datos de filas de matriz s
      for (; col_s < 4; col_s++) { // recorre las columnas de ambas matrices
        dist = dist + pow(matriz_dr[fil][col_s] - matriz_r[fil_s][col_s], 2); //distancia entre dos puntos
      }
      dist_total = sqrt(dist); // distancia entre dos puntos
      if (dist_total < dist_mayor) { // compara con distancia menor
        dist_mayor = dist_total;
        label = matriz_r[fil_s][4]; // almacena etiqueta de distancia menor
      }// endif
      dist = 0;
      col_s = 0;
    }//end for fil_S
    fil_s = 0;
    dist_mayor = 2000;
    // si clasifica correctamente el sistema no realiza ninguna accion
    if (label == matriz_dr[fil][4]) {
    }
    // si clasifica de forma erronea, almacena en matriz s
    else {
      for (; col_s < 5; col_s++) {
        matriz_r[fil_s1][col_s] = matriz[fil][col_s];
      }
      col_s = 0;
      fil_s1++;
    }
  }
  fil_s = 0;
  for (; fil_s < fil_s1; fil_s++) {
    for (; col_s < 5; col_s++) {
      Serial.print(matriz_r[fil_s][col_s]);
      Serial.print(',');
    }
    col_s = 0;
    Serial.println(' ');
  }
  fil_s1 = -1;
  ////////////////////////////////

}

void loop() {
/*  //////COmpraracion matriz final ///////////
  if (on == 0) {
    for (int i = 0; i <= 29; i++) {
      result = knn(fil_s, 5, 3, 3, prueba[i]);
      if (result == prueba[i][4]) {
        a++;
      }
      else {
        b++;
      }
    }
    Serial.println("Esta es la Matriz S final");
    Serial.println(' ');
    Serial.println("Ya comprobados con la matriz prueba ");
    Serial.println("Aciertos: ");
    Serial.println(a);
    Serial.println("Erroneos: ");
    Serial.println(b);
    total = (a * 100) / 30;
    Serial.println("Eficiencia");
    Serial.println(total);
    on = 1;
  }*/
}
/*float knn (int fila, int col, int k, int label, float datos[]) {
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
      distk = distk + pow((matriz_r[f][c] - datos[c]), 2); // distancia entre dos puntos
    }
    dist_totalk = sqrt(distk); // raiz de la formula
    // Serial.println(dist_total);
    for (; k_cont < k; k_cont++) { // determinar las k distancias menores y ordenarlas
      if (dist_totalk < k_vecinos_dist[k_cont]) {
        k_vecinos_dist[k_cont] = dist_totalk; // asignar nuevo valor a vector de distancias menores
        eti_menor[k_cont] = matriz_r[f][col - 1]; // col =5 , 4
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
}*/
