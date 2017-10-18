#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario Funcionario;
struct funcionario{
    char nome[35];
    char sexo[0];
    int prod;
};

void listar(Funcionario lista[], int qt){
    int controle=0,i;
    do{
        system("clear");
        printf("\n---------------------------------");
        for(i=0;i<qt;i++){
            printf("\n%s - %s - %d",lista[i].nome, lista[i].sexo, lista[i].prod);
            printf("\n---------------------------------");
        }
        printf("\nDigite 0 para sair: ");
        scanf("%d",&controle);
    }while(controle!=0);
}

int registrar(Funcionario lista[], int qt){
    system("clear");
    int controle=0;
    do{
        printf("\nNome do funcionario: ");
        scanf("%s",lista[qt].nome);
        fflush(stdin);

        printf("\nNumero de pecas fabricadas: ");
        scanf("%d",&lista[qt].prod);
        fflush(stdin);

        printf("\nSexo do funcionario (M/F): ");
        scanf("%s",lista[qt].sexo);
        fflush(stdin);

        qt=qt+1;
        controle=0;
    }while(controle!=0);
    return qt;
}

int main(){
    Funcionario lista[7];
    int op=0, qt=0;
    do{
//system("clear");
        printf("-------FABRICA 1.0-------");
        printf("\n1 - Registrar funcionario");
        printf("\n2 - Listar funcionarios");
        printf("\n3 - Gerar funcionarios aleatorios");
        printf("\n4 - Funcionario do mes");
        printf("\n0 - SAIR");
        printf("\nQUANTIDADE DE FUNCIONARIOS: %d",qt);
        printf("\nSua opcao: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                qt = registrar(lista,qt);
                break;
            case 2:
                if(qt==0){
                    printf("\nAinda nao ha funcionarios registrados\n");
                }
                else{
                    listar(lista,qt);
                }
                break;
        }
    }while(op!=0);
    system("clear");
    printf("Ate mais.");
}
