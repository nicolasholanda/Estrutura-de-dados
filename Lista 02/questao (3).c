#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct boletim{
    char nome[50];
    int nota[3];
};
int main()
{
    setlocale(LC_ALL,"Portuguese");
    struct boletim dados[35];
    int i,j,n;
    printf("Quantos Alunos deseja cadastrar?(M�ximo 35): ");
    scanf("%d",&n);
    fflush(stdin);
    system("pause");
    system("cls");

    printf("--------------------Boletim IFCE------------------\n");
    fflush(stdin);
    for(i=0;i<n;i++){
        printf("Nome do Aluno %d: ",i+1);
        gets(dados[i].nome);
        fflush(stdin);
        for(j=0;j<3;j++){
            printf("Nota %d:",(j+1));
            scanf("%d",&dados[i].nota[j]);

            while((dados[i].nota[j]>10) || (dados[i].nota[j]<0)){
                printf("Valores para Notas : 0 a 10");
                printf(" ,Por favor  entrar com nota(%d) v�lida: ",j+1);
                scanf("%d",&dados[i].nota[j]);
            }
        }
        fflush(stdin);
        system("cls");
    }

    return 0;
}
