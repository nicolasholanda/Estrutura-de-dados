#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int i, j, lA, cA, lB, cB, x;
lA=5;
cA=4;
lB=4;
cB=3;
float matrizA[lA][cA],matrizB[lB][cB],matrizC[lA][cB],Aux=0;
     for(i=0; i<5; i++){
         for(j=0; j<4; j++){
             printf("Informe os Componentes da Matriz A [%d,%d]: ",i+1,j+1);
             scanf("%f", &matrizA[i][j]);
         }
         printf("\n");
     }
    system("cls");
     for(i=0; i<4; i++){
         for(j=0; j<3; j++){
             printf("Informe os componentes da Matriz B [%d,%d]: ",i+1,j+1);
             scanf("%f", &matrizB[i][j]);
         }
         printf("\n");
     }
printf("Matriz A \n\n");
     for(i=0; i<5; i++){
         for(j=0; j<4; j++){
             printf("%6.f", matrizA[i][j]);
/* "%6.f" significa para eliminar 6 casas decimais dos componentes dados */
         }
         printf("\n\n");
     }
printf("Matriz B \n\n");
     for(i=0; i<4; i++){
         for(j=0; j<3; j++){
             printf("%6.f", matrizB[i][j]);
         }
         printf("\n\n");
     }
     for(i=0; i<5; i++){
         for(j=0; j<3; j++){
             matrizC[i][j]=0;
                 for(x=0; x<4; x++){
                     Aux+= matrizA[i][x] * matrizB[x][j];
/* x significa que a quantidade de colunas da Matriz A é mesma  que as linhas
da Matriz B */
                 }
                 matrizC[i][j]=Aux;
                 Aux=0;
/* Aux significa guardar valor para não ser perdido durante o algoritmo */
         }
     }
printf("\n\n");
printf("Matriz Gerada da Multiplicacao A*B \n\n");
     for(i=0; i<5; i++){
         for(j=0; j<3; j++){
             printf("%6.f", matrizC[i][j]);
         }
         printf("\n\n");
     }
printf("\n\n");
system("PAUSE");
return 0;
}
