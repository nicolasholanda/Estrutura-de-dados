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
int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct cadastro pessoa[5];
    int i;
    printf("-------------------Empresa Telefônica--------------------\n\n");

        for(i=0;i<3;i++){
            printf("----Usuário %d----\n\n",i+1);
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

        printf("\n\nCadastrado com sucesso!");
        system("pause");
        system("cls");
        }
        printf("-----------------Usuários-----------------\n\n");

        for(i=0;i<3;i++){
            printf("Pessoa %d:\n",i+1);
            printf("Nome: %s\n",pessoa[i].nome);
            printf("Endereço: %s\n",pessoa[i].end);
            printf("Telefone: %d\n",pessoa[i].tele);
            printf("Situação: %c\n",pessoa[i].situ);
            printf("-----------------------------\n");

        }




    return 0;
}
