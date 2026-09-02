#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int missao;
int fase =1;

//nome do heroi ======================
char hero[50];
//atributos ==========================
float dano = 10;
float defesa = 10;
float esquiva = 5;
float danomagico = 0;

//dano com equipamentos ==============
int atqdeespada = 0;
int slotdegemasEspada = 0;


int atqdecajado = 0;
int slotdegemasCajado = 0;

int atqdelivroMagico = 0;
int slotdegemasLivromagico = 0;

//equipamentos =======================
char espada[50] = "nenhuma";
char escudo[50] = "nenhuma";
char capacete[50] = "nenhuma";
char armadura[50] = "nenhuma";
char calca[50] = "nenhuma";
char livroMagico[50] = "nenhuma";
char gemas[50] = "nenhuma";

//npcs=================================

char adversarioC[50];
char adversarioB[50];
char adversarioA[50];
char adversarioS[50];
char Boss[50];

//movimentos
int atacar;


void mmorpg(){
    while (1)
    {
        printf("\n\n==============================");
        printf("\n     OFFSPRING O COMEÇO");
        printf("\n==============================");
        printf("\n1 - Partir Para A Jornada");
        printf("\n2 - Abrir Inventario");
        printf("\n3 - Ir para o mercado");
        printf("\n4 - Ver Missao");
        printf("\n5 - Como jogar");
        printf("\n0 - Encerrar");
        printf("\n\nOpcao: ");
        scanf("%d", &missao);

        if (missao == 0) {
                break;
            }
        switch (missao)
        {
        case 1:
            missoes1();
        break;
            
        default:
        break;
            }
    }
    return 0;
}

void missoes1()
{
    printf("qual é seu nome?");
    scanf("%s", hero);
    printf("\nVoce esta andando pela floresta e encontra uma espada de madeira");
            printf("\n\n====>Espada de Madeira<====");
            printf("\n ====>Rank-C<====");
            printf("\n 1 De attack damage");
            printf("\nNão a slot de gema");

            strcpy(espada, "Espada de Madeira");
            atqdeespada = 1;
            slotdegemasEspada = 0;
            atqdeespada = dano + atqdeespada;

    printf("\nMais a frente voçe encontra um slime. Finalmente um inimigo para voce testa sua nova espada");

    float vidaslime = 15.0;
    
    while (vidaslime > 0)
    {
        printf("\n-----A Batalha vai Começar-----");
        printf("\n-----Vida do Slime %.2f-----",&vidaslime);
        printf("\n-----Deseja Atacar o Slime-----");
        printf("\n1 - Sim (Resolver Desafio para atacar)");
        printf("\n2 - Fugir");
        printf("\nOpcao: ");
            
        scanf("%d", &atacar);

        switch (atacar)
        {
        case 1:
            int num1 = (rand() % 10) + 1;
            int num2 = (rand() % 10) + 1;
            int respostadojogador;
        break;
        
        default:
        break;
        }

    }
    


    

}