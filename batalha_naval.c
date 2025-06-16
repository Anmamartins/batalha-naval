// Jogo Batalha Naval - Desafio da disciplina Introdução à Programação (Estácio)
// Autora: Antonia de Maria Soares Martins

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5

// Função recursiva para contar tentativas
int jogar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tentativas) {
    if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
        printf("\nPosição inválida. Tente novamente.\n");
        return tentativas;
    }

    if (tabuleiro[linha][coluna] == 1) {
        printf("\nVocê acertou o navio!\n");
        return tentativas + 1;
    } else {
        printf("\nÁgua! Tente novamente.\n");
        return tentativas + 1;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int linha_navio, coluna_navio;
    int linha, coluna;
    int tentativas = 0;

    srand(time(NULL));

    // Posiciona o navio aleatoriamente
    linha_navio = rand() % TAMANHO;
    coluna_navio = rand() % TAMANHO;
    tabuleiro[linha_navio][coluna_navio] = 1;

    printf("=== JOGO BATALHA NAVAL ===\n");
    printf("Um navio está escondido em um tabuleiro 5x5.\n");

    while (1) {
        printf("\nDigite a linha (0 a 4): ");
        scanf("%d", &linha);
        printf("Digite a coluna (0 a 4): ");
        scanf("%d", &coluna);

        tentativas = jogar(tabuleiro, linha, coluna, tentativas);

        if (tabuleiro[linha][coluna] == 1) {
            break;
        }
    }

    printf("\nParabéns! Você venceu em %d tentativa(s).\n", tentativas);
    return 0;
}
