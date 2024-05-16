#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         if(n->sudo[i][j] == 0){
            continue;

         }
         // Verificar la fila
         for(int k = 0; k < 9; k++){
            if(k != j && n->sudo[i][k] == n->sudo[i][j]){
               return 0; // No es válido
            }
         }
         // Verificar la columna
         for(int k = 0; k < 9; k++){
            if(k != i && n->sudo[k][j] == n->sudo[i][j]){
               return 0; // No es válido
            }
         }
         // Verificar el cuadrante 3x3
         int inicioFila = (i/3) * 3;
         int inicioCol = (j/3) * 3;
         for(int fila = inicioFila; fila < inicioFila + 3; fila++){
            for(int col = inicioCol; col < inicioCol + 3; col++){
               if((fila != i || col != j) && n->sudo[fila][col] == n->sudo[i][j]){
                  return 0; // No es válido
               }
            }
         }
      }

   }
    return 1;
}


List* get_adj_nodes(Node* n){
   List* list=createList();
   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){ // recorrer matriz
         if(n->sudo[i][j] == 0){ // celda vacia
            for(int k = 1; k <= 9; k++){
               Node* adj = copy(n); // copiar nodo
               adj->sudo[i][j] = k; // asignar valor
               if(is_valid(adj)){ // comprobar
                  pushBack(list, adj); // añadir a lista
               }
            }
            return list;
         }
      }
   }
   return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/