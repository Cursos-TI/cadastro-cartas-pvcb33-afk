#include <stdio.h>
#include <string.h>

#define TOTAL_CARTAS 4

typedef struct {
    int codigo;
    char estado[30];
    char cidade[30];
    int pontos_turisticos;
    double pib;          // Produto Interno Bruto em bilhões de reais
    double area_km2;     // Área em quilômetros quadrados
} Carta;

// Função para exibir os dados de uma carta
void mostrarCarta(Carta c) {
    printf("\n--- Carta Super Trunfo ---\n");
    printf("Código: %d\n", c.codigo);
    printf("Estado: %s\n", c.estado);
    printf("Cidade: %s\n", c.cidade);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Área: %.2f km²\n", c.area_km2);
}

// Função para comparar as cartas com base no atributo escolhido
int compararCartas(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: // Pontos turísticos
            if (c1.pontos_turisticos == c2.pontos_turisticos) return 0;
            return (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 2;
        case 2: // PIB
            if (c1.pib == c2.pib) return 0;
            return (c1.pib > c2.pib) ? 1 : 2;
        case 3: // Área
            if (c1.area_km2 == c2.area_km2) return 0;
            return (c1.area_km2 > c2.area_km2) ? 1 : 2;
        default:
            return -1; // Atributo inválido
    }
}

int main() {
    // Cartas disponíveis no jogo
    Carta cartas[TOTAL_CARTAS] = {
        {1, "São Paulo", "São Paulo", 20, 2800.00, 1521.11},
        {2, "Rio de Janeiro", "Rio de Janeiro", 18, 460.00, 1200.00},
        {3, "Paraná", "Curitiba", 12, 105.00, 430.90},
        {4, "Bahia", "Salvador", 15, 78.00, 693.45}
    };

    int escolha1, escolha2, atributo;

    printf("===== Super Trunfo: Cidades do Brasil =====\n");

    // Seleção das cartas pelos jogadores
    printf("\nJogador 1, escolha uma carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &escolha1);
    printf("Jogador 2, escolha uma carta (1 a %d): ", TOTAL_CARTAS);
    scanf("%d", &escolha2);

    // Validação das escolhas
    if (escolha1 < 1 || escolha1 > TOTAL_CARTAS || escolha2 < 1 || escolha2 > TOTAL_CARTAS) {
        printf("\n[ERRO] Escolha de carta inválida. Tente novamente.\n");
        return 1;
    }

    // Seleção das cartas
    Carta carta1 = cartas[escolha1 - 1];
    Carta carta2 = cartas[escolha2 - 1];

    // Exibição das cartas
    printf("\nCarta do Jogador 1:");
    mostrarCarta(carta1);
    printf("\nCarta do Jogador 2:");
    mostrarCarta(carta2);

    // Escolha do atributo de comparação
    printf("\nEscolha o atributo para disputar:\n");
    printf("1 - Pontos Turísticos\n");
    printf("2 - PIB (em bilhões de R$)\n");
    printf("3 - Área (em km²)\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    // Comparação e resultado
    int vencedor = compararCartas(carta1, carta2, atributo);

    printf("\n===== Resultado da Rodada =====\n");
    if (vencedor == 1)
        printf("Jogador 1 venceu!\n");
    else if (vencedor == 2)
        printf("Jogador 2 venceu!\n");
    else if (vencedor == 0)
        printf("Empate nos atributos escolhidos.\n");
    else
        printf("Atributo inválido! Nenhum vencedor.\n");

    return 0;
}
