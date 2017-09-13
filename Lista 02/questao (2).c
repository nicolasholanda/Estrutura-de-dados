#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct funcionario{
    char nome[50];
    char sexo;
    int producao;
};


int main(){
    setlocale(LC_ALL,"Portuguese");
    struct funcionario pessoa[5];
    int i,maiorProducao,j;
    int producaoFeminina,producaoMasculina;
    char aux[50];



    printf("-------- Bem vindo ao Banco de Dados -------\n\n");

    for(i=0;i<3;i++){
        printf("Nome do funcionario %d:  ",(i+1));
        gets(pessoa[i].nome);
        fflush(stdin);
        printf("\nSexo(M ou F): ");
        scanf("%c",&pessoa[i].sexo);
        fflush(stdin);
        printf("\nQuantidade de Produção: ");
        scanf("%d",&pessoa[i].producao);
        while(pessoa[i].producao<0){
            printf("\nNinguem pode produzir quantidades negativas, Por favor digitar outro valor: ");
            scanf("%d",&pessoa[i].producao);
        }
        fflush(stdin);
        system("cls");
        }

//----------------------------------------------------------------------------------
         for (i = 0; i <= 3; i++) {
            for (j = i + 1; j < 3; j++) {
                while(pessoa[j].producao == pessoa[i].producao){
                    printf("\nNão pode ocorrer empates!\n");
                    printf("%s (%d produções) não pode ter a quantidade de produções iguais a %s (%d produções),\n por favor digitar um novo valor  diferente de %d para %s : ",pessoa[i].nome,pessoa[i].producao,pessoa[j].nome,pessoa[j].producao,pessoa[j].producao,pessoa[j].nome);
                    scanf("%d",&pessoa[j].producao);
            }
        }
    }
//----------------------------------------------------------------------------------
    printf("-----------Funcionarios--------------\n\n");
    for(i=0;i<3;i++){
        printf("%d: \n",i+1);
        printf("Nome: %s\n",pessoa[i].nome);
        printf("Sexo: %c\n",pessoa[i].sexo);
        printf("Produção: %d\n\n",pessoa[i].producao);
    }
    printf("------------------------------------------\n\n");

    maiorProducao = pessoa[0].producao;
    producaoFeminina = 0;
    producaoMasculina = 0;

    for(i=0;i<3;i++){
        if(pessoa[i].sexo=='f'){
            producaoFeminina = producaoFeminina + pessoa[i].producao;
        }
        else{
            producaoMasculina = producaoMasculina + pessoa[i].producao;
        }

        if(pessoa[i].producao>=maiorProducao){
            maiorProducao = pessoa[i].producao;
            strcpy(aux,pessoa[i].nome);
        }
    }

    printf("Produção Feminina: %d",producaoFeminina);
    printf("\nProdução Masculina: %d\n",producaoMasculina);
    printf("O funcionario que teve a maior produção foi %s, com %d produções!\n\n",aux,maiorProducao);
    printf("Volte sempre!\n");





    return 0;

}
