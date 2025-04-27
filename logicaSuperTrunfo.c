#include <stdio.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void comparar_cartas(Carta carta1, Carta carta2, int escolha1, int escolha2) {
    float valores1[2], valores2[2];
    char atributos[2][30];

    int escolhas[] = {escolha1, escolha2};

    for (int i = 0; i < 2; i++) {
        switch (escolhas[i]) {
            case 1:
                valores1[i] = carta1.populacao;
                valores2[i] = carta2.populacao;
                sprintf(atributos[i], "População");
                break;
            case 2:
                valores1[i] = carta1.area;
                valores2[i] = carta2.area;
                sprintf(atributos[i], "Área");
                break;
            case 3:
                valores1[i] = carta1.pib;
                valores2[i] = carta2.pib;
                sprintf(atributos[i], "PIB");
                break;
            case 4:
                valores1[i] = carta1.pontos_turisticos;
                valores2[i] = carta2.pontos_turisticos;
                sprintf(atributos[i], "Pontos Turísticos");
                break;
            case 5:
                valores1[i] = carta1.populacao / carta1.area;
                valores2[i] = carta2.populacao / carta2.area;
                sprintf(atributos[i], "Densidade Demográfica");
                break;
            default:
                printf("Opção inválida!\n");
                return;
        }
    }

    printf("\nComparação de cartas:\n");
    printf("Carta 1 - %s\n", carta1.nome);
    printf("Carta 2 - %s\n\n", carta2.nome);

    float soma1 = 0, soma2 = 0;

    for (int i = 0; i < 2; i++) {
        printf("Atributo: %s\n", atributos[i]);
        printf("Carta 1: %.2f\n", valores1[i]);
        printf("Carta 2: %.2f\n", valores2[i]);

        soma1 += (escolhas[i] == 5) ? valores1[i] * -1 : valores1[i]; // Invertendo regra para Densidade
        soma2 += (escolhas[i] == 5) ? valores2[i] * -1 : valores2[i];

        printf("Vencedor deste atributo: %s\n\n",
               (valores1[i] > valores2[i] && escolhas[i] != 5) ||
               (valores1[i] < valores2[i] && escolhas[i] == 5) ? carta1.nome : valores1[i] == valores2[i] ? "Empate!" : carta2.nome);
    }

    printf("Soma dos atributos:\n");
    printf("Carta 1 - %s: %.2f\n", carta1.nome, soma1);
    printf("Carta 2 - %s: %.2f\n", carta2.nome, soma2);
    printf("Vencedor da rodada: %s\n", (soma1 > soma2) ? carta1.nome : (soma1 == soma2) ? "Empate!" : carta2.nome);
}

int main() {
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200000000.0, 50};
    Carta carta2 = {"Argentina", 45000000, 2780400.0, 500000000.0, 30};

    int escolha1, escolha2;

    printf("Escolha dois atributos para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    printf("Digite sua primeira escolha: ");
    scanf("%d", &escolha1);

    do {
        printf("Digite sua segunda escolha (diferente da primeira): ");
        scanf("%d", &escolha2);
    } while (escolha1 == escolha2);

    comparar_cartas(carta1, carta2, escolha1, escolha2);

    return 0;
}