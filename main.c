#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "lib_menu.h"


typedef struct
{
    char nome[51];
    int pontos;

} placar;

placar rank[10]=
{
    {"Pedro",123},
    {"Andre",465},
    {"Leonardo",673},
    {"Kaue",573}
};


int jogadores=4;


int main()
{
    system("color A");
    setlocale(LC_ALL, "Portuguese");


    int opc,posicao=0;

    do
    {
        printf("\t\t\n A cobra vai fumar\t");
        printf("\n\nDigite entre 1 a 5 para selecionar as opções\n");
        printf("\n\n1-Iniciar\n\n2-Jogador\n\n3-Ranking\n\n4-Créditos\n\n5-Sair\n\n");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            limpa_tela();
            inicio();
            trava();
            limpa_tela();
            break;
        case 2:
            limpa_tela();
            jogador();
            trava();
            limpa_tela();
            break;
        case 3:
            limpa_tela();
            ranking();
            trava();
            limpa_tela();
            break;
        case 4:
            limpa_tela();
            time_dev();
            trava();
            limpa_tela();
            break;



        }
    }
    while(opc != 5);



    return 0;
}



inicio()
{

    printf("\t\t\nEm construção\n\n\n");

    char nome[20];
    int pontos,encontrado=-1;

    printf("NOVO JOGADOR\n");
    printf("\nDigite o nome do jogador\n");
    scanf("%s",&nome);
    getchar();
    system("cls");

    printf("Agora qual foi sua pontuação: ");
    scanf("%d",&pontos);
    getchar();


    for(int i=0; i<jogadores; i++)
    {

        if (strcmp(nome,rank[i].nome) == 0)
        {
            encontrado=i;
            break;
        }
    }

    if(encontrado==-1)
    {
        encontrado=jogadores;
        strcpy(rank[encontrado].nome,nome);
        jogadores++;
    }
    rank[encontrado].pontos=pontos;
}




jogador (void)
{
    printf ("\n Busque sua pontuação aqui!!\n\n");
    printf ("Digite seu nome para ver sua pontuação:\n");
    fflush(stdin);
    char nomeDeProcura[32];
    gets(nomeDeProcura);
    for(int i=0; i < jogadores; i++)
    {
        if (strcmp(rank[i].nome,nomeDeProcura)== 0)

        {
            printf("A pontuação de %s é: %d\n\n",nomeDeProcura,rank
                   [i].pontos);
            break;
        }
    }

}

ranking (void)
{
    int trocar;
    placar copia;

    do
    {
        trocar=0;
        for (int i=0; i<jogadores-1; i++)
        {
            if(rank[i].pontos<rank[i+1].pontos)
            {
                trocar=1;
                copia=rank[i];
                rank[i]=rank[i+1];
                rank[i+1]=copia;
            }
        }
    }
    while(trocar==1);



    printf("  POSIÇÃO|\t  PONTUAÇÃO|   NOME\n");

    for (int i=0; i<jogadores; i++)
    {
        printf("\t%d|\t\t%d|\t%s\n",i+1,rank[i].pontos,rank[i].nome);
    }
    return;
}


time_dev()
{
    printf("Jogo desenvolvido por:\nPedro,\nKaue,\nAndre,\nLeo.\n\n");

}

limpa_tela()
{
    system("cls");
}

trava()
{

    system("pause");
}
