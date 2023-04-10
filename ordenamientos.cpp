/*
Author: Jose Angel Garcia Gomez
Date: 11/2021
Description: Program that implements different sorting methods
*/

//Bibliotecas propias o precargadas
#include <iostream> //entradas y salidas de nuestro programa
#include <stdlib.h> //Generar números aleatorios
#include <time.h> //tiempo de la computadora

//Espacio de nombres
using namespace std;

//Dos lugares para almacenar datos Stack y el Heap

//Generar arreglos aleatorios
void generarArreglo(int arreglo [],int tam){
    //inicializar la semilla de generacion de numeros aleatorios
    srand((unsigned)time(0));
    //srand(7);
    for(int i=0;i<tam;i++)
        arreglo[i]=rand()%100; //Genera un número pseudoaleatori de o a 100
}

//Imprimir un arreglo
void imprimirArreglo(int arreglo [], int tam){
    for(int i=0;i<tam;i++){
        cout<< arreglo[i]<<" ";
    }
    cout<<endl;
}

void metodoIntercambio(int arreglo [], int tam){
    int i,j,auxiliar;
    //Va a realizar las pasadas, tiene control del indice fijo
    //f(n)=4n^2  --> g(n)=n^2  O(n^2)
    for(i=0;i<tam-1;i++){ //f(n)=n -1  O(g(n))  g(n)=n  
        //Indice de comparación
        for(j=i+1;j<tam;j++){ //n
            //Validar si el elemento fijo es menor que el del indice
            //de comparación
            //4 operaciones
            if(arreglo[j]<arreglo[i]){ //arreglo[i]>arreglo[j]
                auxiliar = arreglo[j];  //auxiliar = arreglo[i]
                arreglo[j] = arreglo[i];
                arreglo[i] = auxiliar;
            }
        }
    }
}

void metodoBurbuja(int arreglo [],int tam){
    int i,j,aux;
    bool flag = true; //max(O(1),O(n^2)) => O(n^2)
    //Control de pasadas
    for(i=0;i<tam&&flag;i++){ //O(n^2)
        flag = false; //O(1) => max(O(1),O(n)) => O(n)
        for(j=0;j<tam-1-i;j++){ //O(n)
            //Verificar si realizo intercambios
            //8=>O(1)
            if(arreglo[j+1]<arreglo[j]){
                aux = arreglo[j];  //auxiliar = arreglo[i]
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
                flag=true;
            }
        }
    }
}

void metodoSeleccion(int arreglo[], int tam){
  int i,j,aux, menor;
  for (i = 0; i<tam-1; i++){// Vale n^2 - > O(n^2)
    menor = i;
    for(j = menor+1; j < tam; j++){ // Vale n -> max  (1, n) -> O(n)
      //Bloque if vale 4 -> O(1)
      if(arreglo[j]<arreglo[menor]){
          menor = j;
      }
    }
    aux = arreglo[menor];
    arreglo[menor] = arreglo[i];
    arreglo[i] = aux;
  }
}

void metodoInsercion(int arreglo[], int tam){//-> O(n^2)
  int i,j,aux;
  for(i = 1; i<tam-1; i++){
    j = i;
    aux = arreglo[i];
    while(j > 0 && aux<arreglo[j-1]){//Recorrer elementos mayores a la derecha
    //El while al ser ciclo se puede contar como -> O(n)
      arreglo[j] = arreglo[j-1];
      j--;
    }
    arreglo[j] = aux;
  }
}

void merge(int arreglo[], int inicio, int mitad, int fin){
    int i,j,k;
  //Numero de elementos en la parte izquierda.
    int izq = mitad - inicio +1;

  //Numero de elementos en la parte derecha.
    int der = fin-mitad;


  //Declarar mis arreglo auxiliares de izquierda y derecha.
    int arregloIzq[izq];
    int arregloDer[der];

  //Copiar los datos del arreglo original en izquierda y derecha.

    for(i=0; i<izq; i++){
        arregloIzq[i] = arreglo[inicio+i];
    }
    for(j = 0; j < der; j++){
        arregloDer[j] = arreglo[mitad+1+j];
    }

  //Realizar el "merge".
    i = 0;
    j = 0;
    k = inicio;
    while(i <izq && j < der){
        if(arregloIzq[i] <= arregloDer[j]){
            arreglo[k] = arregloIzq[i];
            i++;
        }
        else{
            arreglo[k] = arregloDer[j];
            j++;
        }
        k++;
    }

  //Vaciar remanentes. 
    while(i<izq){
        arreglo[k] = arregloIzq[i];
        i++;
        k++;
    }
    while(j<der){
        arreglo[k] = arregloDer[j];
        j++;
        k++;
    }
}

void metodoMergeSort(int arreglo[], int inicio, int fin){
  if(inicio < fin){ //Caso recursivo
    //Obtener el indice medio
    int mitad = inicio + (fin-inicio) / 2;
    //Parte recursiva
    //Izquierda
    metodoMergeSort(arreglo, inicio, mitad);
    //Derecha
    metodoMergeSort(arreglo, mitad+1, fin);

    // Juntar los "arreglos resultantes"
    //Merge
    merge(arreglo, inicio, mitad, fin);

  }
  else{ //Caso base

  }
}

//Particion
int particion(int arreglo[], int inicio, int fin){
    int pivote = arreglo[inicio];
    int i = (inicio +1), aux;

    for (int j = i; j<= fin; j++){
      if(arreglo[j]<pivote){
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
        i++;
      }
    }
    arreglo[inicio] = arreglo[i-1];
    arreglo[i-1] = pivote;
    return i-1;
    /* Mi implementacion
    int i=inicio, j, aux, inter;
    //Establecer el valor del pivote
    
    //Mandar los elementos menores a la izquierda y los mayores a la derecha

    for(j = inicio +1; j < fin +1; j++){ //Este for al tener otro for dentro vale O(n^2)
      if (arreglo[i] >= arreglo[j]){//Este if vale 1 por lo que max(1, n) es -> O(n)
        for(aux = j; aux > i; aux--){ // Esta linea vale O(n)
          // El bloque for vale 8 por lo que es O(1)
          inter = arreglo[aux];
          arreglo[aux] = arreglo[aux-1];
          arreglo[aux-1] = inter;
        }
        i++;
      }
    }
      

    //Intercambiar el pivote con su posicion 
    //Regresar la posicion final del pivote
    return i;//No cuenta al ser un regreso sin asignacion
    */
}

void metodoQuickSort(int arreglo[], int inicio, int fin){

    //Caso recursivo
    if(inicio < fin){
        //Encontrar la posicion final (indice) del pivote dentro del arreglo.
        int pivote = particion(arreglo, inicio, fin); //Esta seccion vale n^2
        //Parte izquierda
        metodoQuickSort(arreglo, inicio, pivote-1);// Esto vale t(i, p-1) 
        //Parte derecha
        metodoQuickSort(arreglo, pivote+1, fin); //Esto vale t(p+1, f)
    }
}

int busquedaBinaria(int arreglo[], int valor, int tam){
  int inicio, mitad, fin, valorCentral;
  inicio = 0;
  fin = tam - 1;
  while(inicio <= fin){
    mitad = (inicio + fin)/2; 
    valorCentral = arreglo[mitad];
    if(valorCentral == valor){
      return mitad;
    }
    else if(valor < valorCentral){
      fin = mitad-1;
    }
    else{
      inicio = mitad+1;
    }
  }
  return -1;
}

int main(/*Parametros de entrada*/){
    int tam;
    cout<<"Ingrese el tamano del arreglo: ";
    cin>>tam;
    //Declaración de arreglo
    int arreglo[tam];
    //Generar arreglo aleatorio
    generarArreglo(arreglo,tam);
    //Imprimir arreglo
    imprimirArreglo(arreglo,tam);
    //Metodos de ordenamiento
    /*
    metodoIntercambio(arreglo,tam);

    metodoBurbuja(arreglo,tam);
    
    metodoSeleccion(arreglo, tam);
    
    metodoInsercion(arreglo, tam);
    
    //Metodos avanzados de ordenamiento

    metodoMergeSort(arreglo, 0, tam-1);
    
    metodoQuickSort(arreglo, 0, tam-1);
    */
    cout << "Buscando 80 con busqueda binaria: "<< busquedaBinaria(arreglo, 80, tam)<<endl;
}