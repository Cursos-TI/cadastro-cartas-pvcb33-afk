#include <stdio.h>

#define TOTAL_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CARTAS (TOTAL_ESTADOS * CIDADES_POR_ESTADO)

struct Carta {
    char codigo[4];             // Ex: A01, B03
    char nome_pais[50];         // Nome do país
    char nome_estado[50];       // Nome do estado
    char nome_cidade[50];       // Nome da cidade
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

int main() {
    struct Carta cartas[TOTAL_CARTAS];

    printf("=== Cadastro de Cartas - Super Trunfo Países (códigos automáticos) ===\n\n");

    int carta_index = 0;

    for (char estado = 'A'; estado <= 'H'; estado++) {
        for (int cidade = 1; cidade <= 4; cidade++) {
            // Gerar código automaticamente
            snprintf(cartas[carta_index].codigo, sizeof(cartas[carta_index].codigo), "%c%02d", estado, cidade);

            printf("Carta %d de %d (Código: %s)\n", carta_index + 1, TOTAL_CARTAS, cartas[carta_index].codigo);

            printf("Nome do país (ex: Brasil, Japão): ");
            scanf(" %[^\n]", cartas[carta_index].nome_pais);

            printf("Nome do estado (ex: São Paulo, Osaka): ");
            scanf(" %[^\n]", cartas[carta_index].nome_estado);

            printf("Nome da cidade (ex: Campinas, Kyoto): ");
            scanf(" %[^\n]", cartas[carta_index].nome_cidade);

            printf("População (ex: 1200000): ");
            scanf("%d", &cartas[carta_index].populacao);

            printf("Área (em km²) (ex: 1520.35): ");
            scanf("%f", &cartas[carta_index].area);

            printf("PIB (em bilhões) (ex: 78.4): ");
            scanf("%f", &cartas[carta_index].pib);

            printf("Número de pontos turísticos (ex: 12): ");
            scanf("%d", &cartas[carta_index].pontos_turisticos);

            printf("--------------------------\n");

            carta_index++;
        }
    }

    // Exibindo as cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n\n");

    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("Código: %s\n", cartas[i].codigo);
        printf("País: %s\n", cartas[i].nome_pais);
        printf("Estado: %s\n", cartas[i].nome_estado);
        printf("Cidade: %s\n", cartas[i].nome_cidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].pontos_turisticos);
        printf("--------------------------\n");
    }

    return 0;
}
