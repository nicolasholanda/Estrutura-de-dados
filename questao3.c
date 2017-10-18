#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct aluno Aluno;
struct aluno{
    char nome[35];
    float nota[3];
};

void listar(Aluno lista[], int *qt){
    system("clear");
    int controle=0,i,j;
    printf("---------------Lista de Alunos----------------");
    printf("\nNOME ------------- AP1 --- AP2 --- FINAL\n");
    do{
        for(i=0;i<*qt;i++){
            printf("\n%s ",lista[i].nome);
            printf(" %.1f --- %.1f --- %.1f",lista[i].nota[0],lista[i].nota[1],lista[i].nota[2]);
        }
        printf("\nDigite 0 para sair: ");
        scanf("%d",&controle);
    }while(controle!=0);
    system("clear");
}

float sorteia_nota(){
    float nota;
    srand(time(NULL));
    nota=rand()%10;
    return nota;
}

char sorteia_nome(Aluno *lista, int pos){
    srand(time(NULL));
    int i=rand()%13;
    int j=rand()%6;
    char nomes[14][15]={"Nicolas", "Mateus", "Rafael", "Lucas", "Chagas", "Guilherme", "Rodrigo", "Lucia",
    "Katarine", "Joana", "Joao", "Paula", "Jessica", "Andressa"};
    char sobrenomes[7][15]={" Holanda", " Menezes", " Silva", " Costa", " Pereira", " Rodrigues", " Oliveira"};
    char *nom=strcat(nomes[i],sobrenomes[j]);
    strcpy(lista[pos].nome, nom);
}

int gerar(Aluno lista[], int *qt){
    int j;
    system("clear");
    if(*qt<34){
        sorteia_nome(lista,*qt);
        for(j=0;j<3;j++){
            lista[*qt].nota[j]=sorteia_nota();
        }
        *qt=*qt+1;
    }
    else{
        printf("\nLista cheia!\n\n");
    }
}

int main(){
    Aluno lista[35];
    int i,*qt=malloc(sizeof(int));
    *qt=0;
    int controle=0;
    do{
        printf("**ESTRUTURA DE DADOS**");
        printf("\n1-GERAR ALUNOS ALEATORIOS");
        printf("\n2-LISTAR ALUNOS E NOTAS");
        printf("\n0-SAIR");
        printf("\nQUANTIDADE DE ALUNOS: %d",*qt);
        printf("\nSua opcao: ");
        scanf("%d",&controle);
        switch(controle){
            case 1:
                gerar(lista, qt);
                break;
            case 2:
                listar(lista, qt);
                break;
            case 0:
                controle=0;
                break;
            default:
                system("clear");
                printf("\n\nOpcao invalida!\n\n");
                break;
        }
    }while(controle!=0);
    printf("Ate logo!");
}
