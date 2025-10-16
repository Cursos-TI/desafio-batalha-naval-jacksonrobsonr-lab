#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAM_NAVIO 3

void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int numNavio, char orientacao) {
    int linha, coluna;
    int limiteLinha = LINHAS, limiteColuna = COLUNAS;

    // ajustar limites para não sair da matriz
    if (orientacao == 'H') limiteColuna = COLUNAS - (TAM_NAVIO - 1);
    else if (orientacao == 'V') limiteLinha = LINHAS - (TAM_NAVIO - 1);

    printf("\nInsira as coordenadas do Navio %d (%s):\n",
           numNavio,
           (orientacao == 'H' ? "Horizontal" : orientacao == 'V' ? "Vertical" : "Diagonal"));

    // escolher linha
    do {
        printf("Linha (1 a %d): ", limiteLinha);
        scanf("%d", &linha);
        if (linha < 1 || linha > limiteLinha)
            printf("Valor inválido, tente novamente.\n");
    } while (linha < 1 || linha > limiteLinha);

    // escolher coluna
    do {
        printf("Coluna (1 a %d): ", limiteColuna);
        scanf("%d", &coluna);
        if (coluna < 1 || coluna > limiteColuna)
            printf("Valor inválido, tente novamente.\n");
    } while (coluna < 1 || coluna > limiteColuna);

    // ajustar índice (base 0)
    linha--;
    coluna--;

    // preencher o tabuleiro de acordo com a orientação
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (orientacao == 'H') tabuleiro[linha][coluna + i] = numNavio;
        else if (orientacao == 'V') tabuleiro[linha + i][coluna] = numNavio;
        else if (orientacao == 'D') tabuleiro[linha + i][coluna + i] = numNavio;
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};

    printf("\n--- BATALHA NAVAL ---\n");
    imprimirTabuleiro(tabuleiro);

    posicionarNavio(tabuleiro, 1, 'H');
    posicionarNavio(tabuleiro, 2, 'V');
    posicionarNavio(tabuleiro, 3, 'D');
    posicionarNavio(tabuleiro, 4, 'D');

    printf("\n\n--- TABULEIRO FINAL ---\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
