#include <stdio.h>
#include <stdlib.h> 

struct structNodo{
  double dato;
  int fila;
  int columna;
  struct structNodo *siguiente;
};

typedef struct structNodo nodo;


nodo *insertarNodoFinal(int fila,int columna,double valor, nodo *lista);
void imprimirLista(nodo *lista);
void liberarMemoria(nodo *lista);

nodo *crearLista(){
  return NULL;
}

nodo *lecturaArchivo(FILE *arch,int dimension,nodo *lista){
  for(int i=0;i<dimension;i++){
    double dato;
    for(int j=0; j<dimension;j++){
      fscanf(arch,"%lf",&dato);
      //printf("dato %ld\n",dato);
      if(dato!=0){
        lista=insertarNodoFinal(i,j,dato,lista);
      }
    }
  }
  return lista;
}

nodo *insertarNodoFinal(int fila,int columna,double valor,nodo *lista)
{
  nodo *nodoNuevo,*nodoAuxiliar;
  nodoNuevo=(nodo *)malloc(sizeof(nodo));
  if(nodoNuevo!=NULL)
    {
      nodoNuevo->dato=valor;
      nodoNuevo->fila=fila;
      nodoNuevo->columna=columna;
      nodoNuevo->siguiente=NULL;
      if(lista==NULL)
        lista=nodoNuevo;
      else{
        nodoAuxiliar=lista;
        while(nodoAuxiliar->siguiente!=NULL){
          nodoAuxiliar=nodoAuxiliar->siguiente;
        }
        nodoAuxiliar->siguiente=nodoNuevo;
      }
    }
  return lista;
}

void imprimirLista(nodo *lista){
  nodo *nodoAuxiliar;
  nodoAuxiliar=lista;
  printf("INICIO -> \n");
  while(nodoAuxiliar!=NULL){ //necesita recorrer todos los elementos
    printf("fila: %d\n",nodoAuxiliar->fila);
    printf("columna: %d\n",nodoAuxiliar->columna);
    printf("%lf\n ",nodoAuxiliar->dato);
    nodoAuxiliar=nodoAuxiliar->siguiente;

  }
  printf("NULL\n");

}

void liberarMemoria(nodo *lista){
  nodo *eliminar= lista;
  nodo *aux=lista;
  while(aux!=NULL){
    aux=eliminar->siguiente;
    free(eliminar);
    eliminar=aux;
  }
  printf("memoria liberada\n");
}

double get( nodo *lista, int row, int columna){
  nodo *aux = lista;
  while(aux != NULL){
    if(aux->fila == row && aux->columna == columna)
      return aux->dato;
    aux = aux->siguiente;
  }
  return 0;
}

nodo *calcularPotencia(nodo *lista1, nodo *lista2, int p, int d){
  if(p == 1)
    return lista1;
  int suma = 0;
  nodo *listaPotencia = NULL;
  for(int i = 0; i < d; i++){
    for(int j = 0; j < d; j++){
      suma = 0;
      for(int k = 0; k < d; k++){
        suma += get(lista1, i, k) * get(lista2, k, j);
      }
      if(suma != 0)
        listaPotencia = insertarNodoFinal(i, j, suma, listaPotencia);
    }
  }
  //liberarMemoria de lista1
  return calcularPotencia(listaPotencia, lista2, p - 1, d);
}

int main(){
  nodo *lista;
  nodo *listaPotencia;
  lista = crearLista();
  int dimension, potencia;
  FILE *archivoEntrada= fopen("potencia.in","r");
  fscanf(archivoEntrada,"%d",&dimension);
  fscanf(archivoEntrada,"%d",&potencia);
  lista = lecturaArchivo(archivoEntrada, dimension, lista);
  //lista2 = copypaste(lista);
  listaPotencia  = calcularPotencia(lista, lista, potencia, dimension);
  imprimirLista(listaPotencia);
  liberarMemoria(lista);
  return 0;
}
