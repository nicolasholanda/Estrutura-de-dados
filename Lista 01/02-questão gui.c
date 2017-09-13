#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main()
{
    int vetX[50],vetY[50],vetW[50];
    int i,num,num2,num3,z,maiorX,menorX,procurado;

    setlocale(LC_ALL,"Portuguese");

    printf("Quantas posições?(Limite igual a 50): ");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        printf("Posição %d do vetor X: ",i);
        scanf("%d",&vetX[i]);
    }

    /*--------------------------------------------------*/
    num2=0;
    num3=0;
    maiorX=vetX[0];
    menorX=vetX[0];

    for(i=0;i<num;i++){
        if(vetX[i]>maiorX){
            maiorX = vetX[i];
        }
        if(vetX[i]<menorX){
            menorX= vetX[i];
        }
        if((vetX[i]>10) && (vetX[i]<40)){
            vetY[num2]=vetX[i];
            num2 = num2 + 1;
        }
        if(!(i%2)){
            vetW[num3]= vetX[i];
            num3 = num3 + 1;
        }
    }
/*----------------------------------------------------*/
printf("\n 02 - Vetor X: ");
for (i=0;i<num;i++){
    printf(" %d ",vetX[i]);
}
printf("\n\n a) Vetor Y: ");
for(i=0;i<num2;i++){
    printf(" %d ",vetY[i]);
}
printf("\n\n b) Vetor W: ");
for(i=0;i<num3;i++){
    printf(" %d ",vetW[i]);
}
/*----------------------------------------------------*/


    do{
        printf("\n\n Numero a ser pesquisado no vetor x: ");
        scanf("%d",&z);
        procurado = 0;

        for(i=0;i<num;i++){
            if(vetX[i]==z){
                procurado = 1;
                printf("\n\n c) Você achou o numero %d na posição %d",vetX[i],i);

            }

            }
        if(procurado==0){
            printf("\n\nNumero não encontrado no vetor!Por favor digitar outro.");
        }

    }while(procurado==0);

/*-----------------------------------------------------------*/
printf("\n\n d) Maior numero de X: %d",maiorX);
printf("\n\n d) Menor numero de X: %d\n\n",menorX);



    return 0;
}
