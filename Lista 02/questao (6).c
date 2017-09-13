#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct cadastro{
    char nome[50];
    char end[50];
    int tele;
    char situ;
};
int main(){
    setlocale(LC_ALL,"Portuguese");
    struct cadastro pessoa[5];
    int i,j,aux,opc;
    char z[50],w[50];
    i=0;
    printf("Programa para cadastro de 5 pessoas!\n");
    system("pause");
    system("cls");
    while(opc!=5){
        printf("-------------------Empresa Telefônica--------------------\n\n");
        printf("1.CADASTRAR\n");
        printf("2.PESQUISAR\n");
        printf("3.ALTERAR\n");
        printf("4.MOSTRAR TODOS\n");
        printf("5.SAIR\n");
        printf("opção: ");
        scanf("%d",&opc);
        fflush(stdin);

        switch(opc){
        case 1:
            if(i>4){
                printf("Máximo de cadastros: 5\n");
                system("pause");
                system("cls");
                break;
            }
            printf("Voce escolheu a opção CADASTRAR!\n");
            printf("Nome: ");
            gets(pessoa[i].nome);
            fflush(stdin);
            printf("Endereço: ");
            gets(pessoa[i].end);
            fflush(stdin);
            printf("Número de telefone(residencial): ");
            scanf("%d",&pessoa[i].tele);
            while((pessoa[i].tele>39999999) || (pessoa[i].tele<30000000)){
                printf("\n     Telefone no formato errado, por favor entre com formato certo: ");
                scanf("%d",&pessoa[i].tele);
            }
            fflush(stdin);
            printf("Situação:  (L)- livre / (X) - Ocupado / (*) - Apagado : ");
            scanf("%c",&pessoa[i].situ);
            fflush(stdin);

        i++;
        printf("\n\nCadastrado com sucesso!");
        system("pause");
        system("cls");

        break;
        case 2:
            aux=0;
                printf("Você escolheu a opção PESQUISAR!\n");
                printf("Nome a ser procurado: ");
                gets(z);
                for(j=0;j<i;j++){

                    if(strcmp(pessoa[j].nome,z)==0){
                        printf("Dados encontrados!\n\n");
                        printf("Endereço: %s\n",pessoa[j].end);
                        printf("Telefone: %d\n",pessoa[j].tele);
                        printf("Situação: %c\n",pessoa[j].situ);
                        aux=1;
                    }
                }
                if(aux==0)
                    printf("Pessoa não cadastrada!\n");

                system("pause");
                system("cls");

            break;
        case 3:
            aux=0;
            printf("Você escolheu a opção ALTERAR!");
            printf("Pessoa a ter seus dados modificados: ");
            gets(w);
             for(j=0;j<i;j++){
                    if(strcmp(pessoa[j].nome,w)==0){
                        printf("Novo nome: ");
                        gets(pessoa[j].nome);
                        fflush(stdin);
                        printf("Novo endereço: ");
                        gets(pessoa[j].end);
                        fflush(stdin);
                        printf("Novo Telefone: ");
                        scanf("%d",&pessoa[j].tele);
                        fflush(stdin);
                        printf("Nova Situação (L)- livre / (X) - Ocupado / (*) - Apagado : ");
                        scanf("%c",&pessoa[j].situ);
                        fflush(stdin);
                        aux=1;

                    }
                }
                if(aux==0)
                    printf("Pessoa não cadastrada!\n");



            system("pause");
            system("cls");
            break;
        case 4:
            printf("Voce escolheu a opcao MOSTRAR TODOS!\n\n");
            for(j=0;j<i;j++){

                printf("Nome: %s\n",pessoa[j].nome);
                printf("Endereço: %s\n",pessoa[j].end);
                printf("Telefone: %d\n",pessoa[j].tele);
                printf("Situação: %c\n",pessoa[j].situ);
                printf("\n\n");
            }
            system("pause");
            system("cls");
        case 5:
            break;
        default:
            printf("Numero inválido!\n");
            system("pause");
            system("cls");
            break;

        }
    }
return 0;
}



