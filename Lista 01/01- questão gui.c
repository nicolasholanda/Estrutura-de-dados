#include <stdio.h>
#include <stdlib.h>
int main(){

    int vetor[5];
    int i,j,aux,x,y,total;
    float media;


    printf("01 - Escreva cinco numeros: \n");

    for(i=0;i<5;i++){
        scanf("%d",&vetor[i]);
    }

        for (i=0;i<5;i++){
            for(j=i+1;j<5;j++){
                if(vetor[i]<vetor[j]){
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }

        }
    }
    printf("\nNumeros acima de 256 seram ignorados nos itens abaixo!!");
    printf("\n\n a) ordenado decrescente: \n");
    for (i=0;i<5;i++){
            if(vetor[i]<256){
                printf(" %i ",vetor[i]);
            }
    }

    /*----------------------------------------------- */
    x= 0;
    y= 0;
    for(i=0;i<5;i++){
        if(vetor[i]<256){
            if(vetor[i]%2==0){
                x = x+1;
            }
            else{
                y = y+1;
            }

        }
    }
    printf("\n\n b) Numeros Pares: ");
    printf(" %i",x);
    printf("\n\n b) Numeros Impares: ");
    printf(" %i",y);

    /* ------------------------------------------------- */
    x=0;
    total=0;
    for (i=0;i<5;i++){
            if (vetor[i]<256){
                if((vetor[i]%2 != 0) && (vetor[i]>50)){
                    x++;
                    total = total + vetor[i];
                }
            }
    }
    media=(total/x);
    printf("\n\n c) Media: %f",media);




    return 0;
}
