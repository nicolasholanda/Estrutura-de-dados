#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define FALSE 0
#define TRUE !FALSE

int verprimo(int numero){
    int cont,i;
    cont=0;
    if ((numero<=0) || (numero==1)){
        return FALSE;
    }

    for(i=1;i<=numero;i++){
        if(numero%i==0){
            cont = cont + 1;
        }
    }
    if(cont==2){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/*--------------------------------------------------------*/

int main(){
    int n,primo,aux,i;
    setlocale(LC_ALL,"Portuguese");

    do{
        primo = FALSE;
        printf("Entre com um n�mero primo:");
        scanf("%d",&n);

        if(verprimo(n)){
            printf("\nO n�mero %d � primo!\n\n",n);
            primo = TRUE;
        }
        else{
            printf("\nO n�mero %d n�o � primo!\n\n",n);
        }


    }while(primo==FALSE);

/*----------------------------------------------------------*/

    printf("\nPrimos Anteriores: ");

    aux=0;

    for(i=n-1;i>0;i--){
        if(verprimo(i)){
            printf(" %d ",i);
            aux=aux+1;
        }
        if(aux==2){
            break;
        }
    }
/*----------------------------------------------------------*/

    printf("\nPrimos Sucessores: ");
    aux=0;

    for(i=n+1;TRUE;i++){
        if(verprimo(i)){
            printf(" %d ",i);
            aux = aux +1;
        }
        if(aux==2){
            break;
        }
    }
    return 0;
}


