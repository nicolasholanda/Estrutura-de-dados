#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int i,A[50],B[50],C[100],n,j,z,achou;
    setlocale(LC_ALL,"Portuguese");

    printf("Entre com o tamanho do vetor A e B (No máximo 50): ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Entre com a posição %d do vetor A: ",i);
        scanf("%d",&A[i]);
    }
    printf("---------------------------------------------------------------\n");
    for(i=1;i<=n;i++){
        printf("Entre com a posição %d do vetor B: ",i);
        scanf("%d",&B[i]);
    }
    printf("----------------------------------------------------------------\n");

    j=1;
    for(i=1;i<=n+n;i+=2){
        C[i]=A[j];
        j++;
    }
    j=1;
    for(i=2;i<=n+n;i+=2){
        C[i]=B[j];
        j++;
    }


    printf("Vetor C: ");
    for(i=1;i<=n+n;i++){
        printf(" %d ",C[i]);
    }

    printf("\n----------------------------------------------------------------\n");
     do{
        printf("\n\n Numero a ser pesquisado no vetor C: ");
        scanf("%d",&z);
        achou = 0;

        for(i=1;i<=n+n;i++){
            if(C[i]==z){
                achou = 1;
                printf("\n\nVocê achou o numero %d na posição %d",C[i],i);

            }
            }
        if(achou==0){
            printf("\nNumero não encontrado , por favor entrar com outro!");
        }

    }while(achou==0);

    return 0;
}
