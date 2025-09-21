#include <stdio.h>

#define PAISES 4
#define CIDADES 4

typedef struct {
    char nome[50];
    int populacao;
    float area;
    double pib;
    int pontosTuristicos;
} Cidade;

typedef struct {
    char nome[50];
    Cidade cidades[CIDADES];
} Pais;

int main() {
    Pais paises[PAISES] = {
        {
            "Brasil",
            {
                {"São Paulo", 12300000, 1521.11, 430.00, 10},
                {"Rio de Janeiro", 6748000, 1182.30, 210.00, 12},
                {"Brasília", 3055149, 5802.00, 65.00, 7},
                {"Salvador", 2886698, 693.45, 45.00, 6}
            }
        },
        {
            "Japão",
            {
                {"Tóquio", 13960000, 2194.07, 2000.00, 15},
                {"Osaka", 2715000, 223.00, 670.00, 10},
                {"Kyoto", 1464000, 827.83, 150.00, 18},
                {"Hiroshima", 1193000, 905.00, 120.00, 8}
            }
        },
        {
            "Estados Unidos",
            {
                {"Nova York", 8419600, 783.80, 2000.00, 25},
                {"Los Angeles", 3980000, 1302.00, 1100.00, 20},
                {"Chicago", 2716000, 589.00, 689.00, 12},
                {"Miami", 442241, 143.00, 345.00, 14}
            }
        },
        {
            "França",
            {
                {"Paris", 2161000, 105.40, 850.00, 30},
                {"Marselha", 870000, 240.62, 60.00, 9},
                {"Lyon", 522000, 47.87, 75.00, 6},
                {"Nice", 340000, 71.92, 45.00, 7}
            }
        }
    };

    // Exibição dos dados
    printf("📋 Cartas cadastradas (Nível Novato - Super Trunfo - Países)\n");

    for (int i = 0; i < PAISES; i++) {
        printf("\n🌐 País: %s\n", paises[i].nome);
        for (int j = 0; j < CIDADES; j++) {
            Cidade c = paises[i].cidades[j];
            printf("\n🏙️  Cidade: %s\n", c.nome);
            printf("👥 População: %d habitantes\n", c.populacao);
            printf("🌍 Área: %.2f km²\n", c.area);
            printf("💰 PIB: %.2lf bilhões de dólares\n", c.pib);
            printf("🏛️ Pontos turísticos: %d\n", c.pontosTuristicos);
        }
    }

    return 0;
}

