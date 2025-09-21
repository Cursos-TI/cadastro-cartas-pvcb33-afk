    nivel novato

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

    nível aventureiro
    
#include <stdio.h>
#include <string.h>

#define CIDADES 4
#define TAM_NOME 50

typedef struct {
    char pais[TAM_NOME];
    char nome[TAM_NOME];
    float populacao; // em milhões
    float area; // km²
    double pib; // bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    double pibPerCapita;
} Cidade;

void calcularPropriedades(Cidade *c) {
    // População total em habitantes
    float popReal = c->populacao * 1000000;

    if (c->area > 0)
        c->densidadePopulacional = popReal / c->area;
    else
        c->densidadePopulacional = 0;

    if (popReal > 0)
        c->pibPerCapita = (c->pib * 1e9) / popReal;
    else
        c->pibPerCapita = 0;
}

void exibirCidade(Cidade c, int id) {
    printf("\n[%d] %s - %s\n", id, c.pais, c.nome);
    printf("👥 População: %.2f milhões\n", c.populacao);
    printf("🌍 Área: %.2f km²\n", c.area);
    printf("💰 PIB: %.2lf bilhões USD\n", c.pib);
    printf("🏛️ Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("📊 Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("💸 PIB per capita: %.2lf USD/hab\n", c.pibPerCapita);
}

void comparar(Cidade a, Cidade b) {
    printf("\n🆚 Comparando %s (%s) x %s (%s)\n\n", a.nome, a.pais, b.nome, b.pais);

    // População
    printf("👥 População: %.2f x %.2f => ", a.populacao, b.populacao);
    if (a.populacao > b.populacao) printf("🏆 %s\n", a.nome);
    else if (b.populacao > a.populacao) printf("🏆 %s\n", b.nome);
    else printf("🤝 Empate\n");

    // Área
    printf("🌍 Área: %.2f x %.2f => ", a.area, b.area);
    if (a.area > b.area) printf("🏆 %s\n", a.nome);
    else if (b.area > a.area) printf("🏆 %s\n", b.nome);
    else printf("🤝 Empate\n");

    // PIB
    printf("💰 PIB: %.2lf x %.2lf => ", a.pib, b.pib);
    if (a.pib > b.pib) printf("🏆 %s\n", a.nome);
    else if (b.pib > a.pib) printf("🏆 %s\n", b.nome);
    else printf("🤝 Empate\n");

    // Pontos turísticos
    printf("🏛️ Pontos turísticos: %d x %d => ", a.pontosTuristicos, b.pontosTuristicos);
    if (a.pontosTuristicos > b.pontosTuristicos) printf("🏆 %s\n", a.nome);
    else if (b.pontosTuristicos > a.pontosTuristicos) printf("🏆 %s\n", b.nome);
    else printf("🤝 Empate\n");

    // Densidade
    printf("📊 Densidade Populacional: %.2f x %.2f => ", a.densidadePopulacional, b.densidadePopulacional);
    if (a.densidadePopulacional > b.densidadePopulacional) printf("🏆 %s\n", a.nome);
    else if (b.densidadePopulacional > a.densidadePopulacional) printf("🏆 %s\n", b.nome);
    else printf("🤝 Empate\n");

    // PIB per capita
    printf("💸 PIB per capita: %.2lf x %.2lf => ", a.pibPerCapita, b.pibPerCapita);
    if (a.pibPerCapita > b.pibPerCapita) printf("🏆 %s\n", a.nome);
    else if (b.pibPerCapita > a.pibPerCapita) printf("🏆 %s\n", b.nome);
    else printf("🤝 Empate\n");
}

int main() {
    // Lista com os 4 países/cidades e dados fixos
    Cidade cidades[CIDADES] = {
        {"Brasil", "São Paulo", 12.3, 1521.11, 430, 10},
        {"Japão", "Tóquio", 13.9, 2194.07, 2000, 15},
        {"EUA", "Nova York", 8.4, 783.8, 2000, 25},
        {"França", "Paris", 2.1, 105.4, 850, 30}
    };

    // Calcular propriedades
    for (int i = 0; i < CIDADES; i++) {
        calcularPropriedades(&cidades[i]);
    }

    // Exibir todas as cidades
    printf("📋 Cartas disponíveis:\n");
    for (int i = 0; i < CIDADES; i++) {
        exibirCidade(cidades[i], i + 1);
    }

    // Escolha das cartas
    int escolha1, escolha2;
    printf("\n🔍 Escolha duas cartas para comparar (1 a 4)\n");
    printf("Primeira carta: ");
    scanf("%d", &escolha1);
    printf("Segunda carta: ");
    scanf("%d", &escolha2);

    // Validação
    if (escolha1 < 1 || escolha1 > CIDADES || escolha2 < 1 || escolha2 > CIDADES || escolha1 == escolha2) {
        printf("❌ Escolha inválida!\n");
        return 1;
    }

    comparar(cidades[escolha1 - 1], cidades[escolha2 - 1]);

    return 0;
}
