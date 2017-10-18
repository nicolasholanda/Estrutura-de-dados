#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int mostra(int *c, int colunas, int linhas, char mat){
    int i,j;
    printf("\n----------MATRIZ %c---------",mat);
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("\n%c[%d][%d]=%d",mat,i+1,j+1,*(c+(i*colunas)+j));
        }
    }
    printf("\n---------------------------");
}

int preenche(int *pt, int colunas, int linhas){
    int i,j;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            *(pt+(i*colunas)+j)=(rand()%5);
        }
    }
}

int main(){
    //define o tamanho da matriz
    int i,j,Aux=0,la,ca,lb,cb,x,controle;
    do{

        printf("\nDigite o numero de linhas de A: ");
        scanf("%d",&la);
        printf("\nDigite o numero de colunas de A: ");
        scanf("%d",&ca);
        printf("\nDigite o numero de linhas de B: ");
        scanf("%d",&lb);
        printf("\nDigite o numero de colunas de B: ");
        scanf("%d",&cb);
        //checa a condição para multiplicação
        if(ca==lb){
            system("clear");
            //cria as matrizes
            int A[la][ca];
            int B[lb][cb];
            srand(time(NULL));
            preenche(&A[0][0],ca,la);
            preenche(&B[0][0],cb,lb);
            //cria matriz C
            int C[la][cb];
            //multiplica A por B
            for(i=0; i<la; i++){
                 for(j=0; j<cb; j++){
                    C[i][j]=0;
                        for(x=0; x<ca; x++){
                            Aux+=A[i][x] * B[x][j];
                         }
                        C[i][j]=Aux;
                        Aux=0;
                 }
            }
            mostra(&A[0][0],ca,la,'A');
            mostra(&B[0][0],cb,lb,'B');
            mostra(&C[0][0],cb,la,'C');
            controle=1;
        }
        else{printf("\nNumero de colunas de A tem que ser igual ao numero de linhas de B"); controle=0;}
    }while(controle==0);
    //cria matriz C
}


