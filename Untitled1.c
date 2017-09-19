#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define MAX 30
#define MIN 2

void preencher(int *n, int *qt){
    system("clear");
    int i,op, controle=1;
    do{
        printf("QUANTOS ELEMENTOS TEM SEU VETOR? MIN:2 MAX:30 ");
        scanf("%d",qt);
        if(*qt<MIN || *qt>MAX){
            printf("A quantidade deve ser um número inteiro, maior que 1 e menor que 30!\n\n");
            controle=0;
        }
        else{controle=1;}
    }while(controle!=1);

    do{
        system("clear");
        printf("---------PREENCHER SEU VETOR---------");
        printf("\n1-Preencher manualmente");
        printf("\n2-Preencher aleatoriamente");
        printf("\n-------------------------------------");
        printf("\nSua opção: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                for(i=0;i<*qt;i++){
                    printf("\nDigite um valor inteiro para o elemento %d: ",i);
                    scanf("%d",&n[i]);
                }
                op=0;
                system("clear");
            break;
            case 2:
                srand(time(NULL));
                for(i=0;i<*qt;i++){
                    n[i]=rand()%20;
                }
                op=0;
                system("clear");
            break;
        }
    }while(op!=0);
}

void troca_posicao(int a, int b, int *n){
   int aux;
   aux = n[a];
   n[a] = n[b];
   n[b] = aux;
}


void exibir(int *n, int *qt){
    int i;
    system("clear");
    printf("Vetor: ");
    for(i=0;i<*qt;i++){
        printf("%d ",n[i]);
    }
    printf("\n\n");
}

void quick_sort(int *n, int inicio, int fim){
    int i, j, x, y;
    i = inicio;
    j = fim;
    int meio = (int)(inicio+fim)/2;
    x = n[meio];
    while(i<=j){
        while(n[i]<x && i<fim){
            i++;
        }
        while(n[j]>x && j>inicio){
            j--;
        }
        if(i<=j){
            y = n[i];
            n[i] = n[j];
            n[j] = y;
            i++;
            j--;
        }
    }

    if(j>inicio){
        quick_sort(n,inicio,j);
    }
    if(i<fim){
        quick_sort(n,i,fim);
    }
}

void selection_sort(int *n, int *qt){
   int i,j,minimo;
   for (i=0;i<(*qt-1);i++)
   {
      minimo= i;
      for (j=i+1;j<*qt;j++)
      {
         if(n[j]<n[minimo])
         {
           minimo=j;
         }
       }

       if (i!=minimo)
       {
          troca_posicao(i, minimo, n);
       }
   }
}

void insertion_sort(int *n, int *qt){
   int i,j,aux;
   for(j=1;j<*qt;j++)
   {
      aux=n[j];
      i=j-1;
      while(i>=0 && n[i]>aux)
      {
        n[i+1] = n[i];
        i--;
      }
      n[i+1]=aux;
   }
}


void bubble_sort(int *n, int *qt){
    int k, j, aux;
    for (k=1;k<*qt;k++){
        for (j=0;j<*qt-1;j++){
            if (n[j]>n[k]){
                troca_posicao(j,k, n);
            }
        }
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int op,i,*qt=malloc(sizeof(int)),*n;
    preencher(n, qt);
    do{
        printf("----SELECIONE UM DOS MÉTODOS DE ORDENAÇÃO----");
        printf("\n1 - BUBBLE SORT");
        printf("\n2 - INSERTION SORT");
        printf("\n3 - SELECTION SORT");
        printf("\n4 - QUICK SORT");
        printf("\n5 - EXIBIR VETOR COMO ESTÁ");
        printf("\n6 - FAZER OUTRO VETOR");
        printf("\n0 - SAIR");
        printf("\n--------------------------------------------");
        printf("\nSua opção: ");
        scanf("%d", &op);
        switch(op){
            //opção 1
            case 1:
                system("clear");
                bubble_sort(n,qt);
                exibir(n,qt);
                printf("**Este é seu vetor ordenado pelo Bubble Sort**\n\n\n");
            break;
            //opção 2
            case 2:
                system("clear");
                insertion_sort(n,qt);
                exibir(n,qt);
                printf("**Este é seu vetor ordenado pelo Insertion Sort**\n\n\n");
            break;
            //opção 3
            case 3:
                system("clear");
                selection_sort(n,qt);
                exibir(n,qt);
                printf("**Este é seu vetor ordenado pelo Selection Sort**\n\n\n");
            break;
            //opção 4
            case 4:
                system("clear");
                quick_sort(n,0,*qt-1);
                exibir(n,qt);
                printf("**Este é seu vetor ordenado pelo Quick Sort**\n\n\n");
            break;
            //opção 5
            case 5:
                system("clear");
                exibir(n,qt);
                printf("**Seu vetor está assim!**\n\n");
            break;
            //opção 6
            case 6:
                preencher(n,qt);
            break;
            //opção 0
            case 0:
                printf("\nObrigado por usar o programa!\n");
            break;
            //opção inválida
            default:
                printf("\nOpção inválida inválido\n");
        }
    }while(op!=0);
}
