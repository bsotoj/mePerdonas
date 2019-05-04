#include <stdio.h>
#include <stdlib.h> 
struct structNodo{
  double dato;
  int fila;
  int columna;
  struct structNodo *siguiente;
};

typedef struct structNodo nodo;


nodo *crearLista(nodo *lista);
nodo *insertarNodoFinal(int fila,int columna,double valor, nodo *lista);
void imprimirLista(nodo *lista);
void liberarMemoria(nodo *lista);

nodo *crearLista(nodo *lista){
  return lista=NULL;

}

nodo *lecturaArchivo(FILE *arch,int dimension,nodo *lista){
  for(int i=0;i<dimension;i++){
  	double dato;
     for(int j=0; j<dimension;j++){
     	fscanf(arch,"%ld",&dato);
     	//printf("dato %ld\n",dato);
     	if(dato!=0){
     	  lista=insertarNodoFinal(i,j,dato,lista);
     	}
     }
  }

return lista;
}


nodo *insertarNodoFinal(int fila,int columna,long valor,nodo *lista)
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
  printf("INICIO -> ");
  while(nodoAuxiliar!=NULL){ //necesita recorrer todos los elementos
    //printf("fila: %d\n",nodoAuxiliar->fila);
    //printf("columna: %d\n",nodoAuxiliar->columna);
    //printf("%ld\n ",nodoAuxiliar->dato);

    nodoAuxiliar=nodoAuxiliar->siguiente;

  }
  printf("NULL\n");

}
void liberarMemoria(nodo *lista){
 nodo *eliminar= lista;
 nodo *aux=lista:
 while(aux!=NULL){
 aux=eliminar->siguiente;
 free(eliminar);
 eliminar=aux;
 }
printf("memoria liberada\n");
}





int main(){
nodo *lista;
lista=crearLista(lista); 
int dimension,potencia;
FILE *archivoEntrada= fopen("potencia.in","r");
fscanf(archivoEntrada,"%d",&dimension);
printf("dimension:%d\n",dimension);
fscanf(archivoEntrada,"%d",&potencia);
printf("potencia:%d\n",potencia);
lista=lecturaArchivo(archivoEntrada,dimension,lista);
//imprimirLista(lista);
liberarMemoria(lista);



return 0;
}





