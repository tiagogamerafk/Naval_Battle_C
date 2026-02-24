#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    bool continuar = true;
    int pontos1 = 0, pontos2 = 0, linha = 0, coluna = 0;
    int carta[10][10] = {
        {2,2,0,0,2,2,0,0,0,0},
        {0,0,0,0,0,5,5,5,5,5},
        {0,0,4,4,4,4,0,0,0,0},
        {0,0,0,0,0,0,0,3,3,3},
        {0,0,0,0,0,0,0,0,0,0},
        {0,2,2,0,0,0,0,0,0,0},
        {0,0,0,0,0,4,4,4,4,0},
        {0,0,2,2,0,0,0,0,0,0},
        {0,0,0,0,0,3,3,3,0,0},
        {0,3,3,3,0,0,0,0,0,0}
    };
    int carta2[10][10] = {
        {2,2,0,0,2,2,0,0,0,0},
        {0,0,0,0,0,5,5,5,5,5},
        {0,0,4,4,4,4,0,0,0,0},
        {0,0,0,0,0,0,0,3,3,3},
        {0,0,0,0,0,0,0,0,0,0},
        {0,2,2,0,0,0,0,0,0,0},
        {0,0,0,0,0,4,4,4,4,0},
        {0,0,2,2,0,0,0,0,0,0},
        {0,0,0,0,0,3,3,3,0,0},
        {0,3,3,3,0,0,0,0,0,0}
    };

    printf("Prepare-se que vamos jogar batalha naval!\nSempre que algo afundar suba os pontos de quem acertou o ataque pelo mesmo numero de quadrados que ele ocupava\n");
    printf("Existem Submarinos (2 quadrados), Contra-Torpedeiros (3), Navios-tanque (4) e Porta-Aviões (5)\n");
    printf("Para parar o jogo a qualquer momento, digite -1 como linha ou coluna.\nPressione qualquer tecla para continuar\n");
    getch();
    system("cls");

    do {
        printf("Jogador 1, Introduza o numero da linha que deseja atacar (-1 para sair)\n");
        scanf("%d", &linha);
        if (linha == -1) break;
        printf("Jogador 1, Introduza o numero da coluna que deseja atacar (-1 para sair)\n");
        scanf("%d", &coluna);
        if (coluna == -1) break;

        if ((coluna >= 0) && (coluna <= 9) && (linha >= 0) && (linha <= 9)) {
            if (carta[linha][coluna] == 2) {
                if ((coluna > 0 ? carta[linha][coluna-1] == 0 : 1) &&
                    (linha > 0 ? carta[linha-1][coluna] == 0 : 1) &&
                    (coluna < 9 ? carta[linha][coluna+1] == 0 : 1) &&
                    (linha < 9 ? carta[linha+1][coluna] == 0 : 1)) {
                    printf("Você afundou o meu submarino! Mais 2 ponto para si");
                    pontos1 += 2;
                } else {
                    printf("Você acertou.");
                }
            } else if (carta[linha][coluna] == 3) {
                printf("Você acertou."); pontos1 += 3;
            } else if (carta[linha][coluna] == 4) {
                printf("Você acertou."); pontos1 += 4;
            } else if (carta[linha][coluna] == 5) {
                printf("Você acertou."); pontos1 += 5;
            } else {
                printf("Você não acertou.");
            }
            carta[linha][coluna] = 0;
        } else {
            printf("Introduza uma coordenada válida!\n");
        }

        printf("\nPressione qualquer tecla para continuar\n");
        getch();
        system("cls");

        printf("Jogador 2, Introduza o numero da linha que deseja atacar (-1 para sair)\n");
        scanf("%d", &linha);
        if (linha == -1) break;
        printf("Jogador 2, Introduza o numero da coluna que deseja atacar (-1 para sair)\n");
        scanf("%d", &coluna);
        if (coluna == -1) break;

        if ((coluna >= 0) && (coluna <= 9) && (linha >= 0) && (linha <= 9)) {
            if (carta2[linha][coluna] == 2) {
                if ((coluna > 0 ? carta2[linha][coluna-1] == 0 : 1) &&
                    (linha > 0 ? carta2[linha-1][coluna] == 0 : 1) &&
                    (coluna < 9 ? carta2[linha][coluna+1] == 0 : 1) &&
                    (linha < 9 ? carta2[linha+1][coluna] == 0 : 1)) {
                    printf("Você afundou o meu submarino! Mais 2 ponto para si");
                    pontos2 += 2;
                } else {
                    printf("Você acertou.");
                }
            } else if (carta2[linha][coluna] == 3) {
                printf("Você acertou."); pontos2 += 3;
            } else if (carta2[linha][coluna] == 4) {
                printf("Você acertou."); pontos2 += 4;
            } else if (carta2[linha][coluna] == 5) {
                printf("Você acertou."); pontos2 += 5;
            } else {
                printf("Você não acertou.");
            }
            carta2[linha][coluna] = 0;
        } else {
            printf("Introduza uma coordenada válida!\n");
        }

        printf("\nPressione qualquer tecla para continuar\n");
        getch();
        system("cls");

    } while (continuar);

    printf("\nFim do jogo!\n");
    printf("Pontuação final:\nJogador 1: %d pontos\nJogador 2: %d pontos\n", pontos1, pontos2);

    return 0;
}


