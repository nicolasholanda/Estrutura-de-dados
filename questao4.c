#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct registro Registro;
struct registro{
    char nome[8];
    char situacao[2];
    char endereco[30];
    char telefone[10];
};

void exibir(Registro agenda[], int i){
    printf("%s      %s        %s    %s\n",agenda[i].nome, agenda[i].situacao, agenda[i].telefone, agenda[i].endereco);
}

int procurar(Registro agenda[], int *qt){
    int i, aux=0;
    char temp[30];
    system("clear");
    printf("**PROCURAR UM REGISTRO**");
    printf("\nDigite o nome: ");
    scanf("%s", temp);
    for(i=0;i<*qt;i++){
        if(strcmp(temp, agenda[i].nome)==0){
            printf("\nRegistro encontrado!!\n");
            return i;
            aux=1;
        }
    }
    if(aux==0){
        printf("\nRegistro nao encontrado!!\n\n");
        return 0;
    }
}

void alterar(Registro agenda[], int *qt){
    int aux=0, i=procurar(agenda, qt);
    if(i!=0){
        do{
            printf("\nO que deseja alterar no contato selecionado?\n");
            printf("1-NOME");
            printf("\n2-NUMERO");
            printf("\n3-ENDERECO");
            printf("\n4-SITUACAO");
            printf("\n0-SAIR");
            printf("\nSua opcao: ");
            scanf("%d",&aux);
            switch(aux){
                case 1:
                    system("clear");
                    char nom[20];
                    printf("Nome atual: %s", agenda[i].nome);
                    printf("\nNovo nome: ");
                    scanf("%s",nom);
                    system("clear");
                    strcpy(agenda[i].nome, nom);
                    printf("\nNome alterado!");
                    break;
                case 2:
                    system("clear");
                    char numer[9];
                    printf("Numero atual: %s", agenda[i].telefone);
                    printf("\nNovo numero: ");
                    scanf("%s",numer);
                    system("clear");
                    strcpy(agenda[i].telefone, numer);
                    printf("\nNumero alterado");
                    break;
                case 3:
                    system("clear");
                    char ende[30];
                    printf("Endereco atual: %s",agenda[i].endereco);
                    printf("\nNovo endereco: ");
                    scanf("%s",ende);
                    system("clear");
                    strcpy(agenda[i].endereco, ende);
                    printf("\nEndereco alterado");
                    break;
                case 4:
                    system("clear");
                    char sit[2];
                    printf("Situacao atual: %s",agenda[i].situacao);
                    printf("\nNova situacao: ");
                    scanf("%s",sit);
                    system("clear");
                    strcpy(agenda[i].situacao, sit);
                    printf("\nSituacao alterada");
                    break;
            }
        }while(aux!=0);
        system("clear");
    }
}

void listar(Registro agenda[], int *qt){
    int i, aux=0;
    system("clear");
    do{
        printf("LISTA DE REGISTROS");
        printf("\nNOME --- SITUACAO --- TELEFONE --- ENDERECO ------------\n");
        for(i=0;i<*qt;i++){
            exibir(agenda,i);
        }
        printf("\n\nPRESSIONE 0 PARA SAIR: ");
        scanf("%d",&aux);
    }while(aux!=0);
    system("clear");
}

void gerar(Registro agenda[], int *qt){
    srand(time(NULL));
    int i=rand()%11 , j=rand()%5 , k=rand()%3 , l=rand()%5 ;
    char nomes[11][10]={"Nicolas", "Abimael", "Alisson", "Andreza", "Beatriz", "Rodrigo", "Matheus", "Rafaely", "Thiaggo", "Melissa", "Henrike"};
    char enderecos[5][35]={"Av 13 de maio", "Av Aguanambi", "Av Washington Soares", "Av Eduardo Girao", "Av Valdevino"};
    char situacoes[3][2]={"L", "*", "X"};
    char telefones[5][10]={"984745581", "985658744", "985857898", "987525522", "986061851"};
    strcpy(agenda[*qt].nome, nomes[i]);
    strcpy(agenda[*qt].endereco, enderecos[j]);
    strcpy(agenda[*qt].telefone, telefones[l]);
    strcpy(agenda[*qt].situacao, situacoes[k]);
    *qt=*qt+1;
    system("clear");
    printf("Registro aleatorio criado!\n\n");
}

int main(){
    Registro agenda[5];
    int i,*qt=malloc(sizeof(int));
    *qt=0;
    int controle=0;
    do{
        printf("************AGENDA************");
        printf("\n1-GERAR 1 REGISTRO ALEATORIO");
        printf("\n2-PROCURAR REGISTROS");
        printf("\n3-ALTERAR UM REGISTRO");
        printf("\n4-EXIBIR TODOS OS REGISTROS");
        printf("\n0-SAIR");
        printf("\nQUANTIDADE DE REGISTROS: %d",*qt);
        printf("\nSua opcao: ");
        scanf("%d",&controle);
        switch(controle){
            case 1:
                if(*qt<5){
                    gerar(agenda, qt);
                }
                else{
                    system("clear");
                    printf("\nAgenda cheia!\n\n");
                }
                break;
            case 2:
                i=procurar(agenda, qt);
                if(i!=0){
                    exibir(agenda, i);
                }
                break;
            case 3:
                alterar(agenda,qt);
                break;
            case 4:
                listar(agenda,qt);
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
