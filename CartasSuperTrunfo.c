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

  nivel mestre

    #include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4];
    char pais[50];
    char cidade[50];
    double populacao; // milhões
    double area;      // km²
    double pib;       // bilhões USD
    int pontosTuristicos;
    double densidadePopulacional; // hab/km² (calculada)
    double pibPerCapita;          // USD/hab (calculada)
    double superPoder;            // soma total das propriedades
} Carta;

void calcularPropriedades(Carta *c) {
    double popReal = c->populacao * 1000000.0; // converter para habitantes
    c->densidadePopulacional = (c->area > 0) ? (popReal / c->area) : 0;
    c->pibPerCapita = (popReal > 0) ? ((c->pib * 1e9) / popReal) : 0;

    // Super Poder = soma de todas as propriedades numéricas (população, área, pib, pontos turísticos, densidade e pib per capita)
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + c->densidadePopulacional + c->pibPerCapita;
}

void exibirCarta(Carta c) {
    printf("Código: %s\n", c.codigo);
    printf("País: %s\n", c.pais);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %.2lf milhões\n", c.populacao);
    printf("Área: %.2lf km²\n", c.area);
    printf("PIB: %.2lf bilhões USD\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2lf hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2lf USD/hab\n", c.pibPerCapita);
    printf("Super Poder: %.2lf\n", c.superPoder);
    printf("----------------------------------------\n");
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparando %s (%s) x %s (%s)\n\n", c1.cidade, c1.pais, c2.cidade, c2.pais);

    // População (maior vence)
    printf("População: %.2lf x %.2lf => ", c1.populacao, c2.populacao);
    if (c1.populacao > c2.populacao) printf("🏆 %s\n", c1.cidade);
    else if (c2.populacao > c1.populacao) printf("🏆 %s\n", c2.cidade);
    else printf("Empate\n");

    // Área (maior vence)
    printf("Área: %.2lf x %.2lf => ", c1.area, c2.area);
    if (c1.area > c2.area) printf("🏆 %s\n", c1.cidade);
    else if (c2.area > c1.area) printf("🏆 %s\n", c2.cidade);
    else printf("Empate\n");

    // PIB (maior vence)
    printf("PIB: %.2lf x %.2lf => ", c1.pib, c2.pib);
    if (c1.pib > c2.pib) printf("🏆 %s\n", c1.cidade);
    else if (c2.pib > c1.pib) printf("🏆 %s\n", c2.cidade);
    else printf("Empate\n");

    // Pontos Turísticos (maior vence)
    printf("Pontos Turísticos: %d x %d => ", c1.pontosTuristicos, c2.pontosTuristicos);
    if (c1.pontosTuristicos > c2.pontosTuristicos) printf("🏆 %s\n", c1.cidade);
    else if (c2.pontosTuristicos > c1.pontosTuristicos) printf("🏆 %s\n", c2.cidade);
    else printf("Empate\n");

    // Densidade Populacional (menor vence)
    printf("Densidade Populacional: %.2lf x %.2lf => ", c1.densidadePopulacional, c2.densidadePopulacional);
    if (c1.densidadePopulacional < c2.densidadePopulacional) printf("🏆 %s\n", c1.cidade);
    else if (c2.densidadePopulacional < c1.densidadePopulacional) printf("🏆 %s\n", c2.cidade);
    else printf("Empate\n");

    // PIB per capita (maior vence)
    printf("PIB per capita: %.2lf x %.2lf => ", c1.pibPerCapita, c2.pibPerCapita);
    if (c1.pibPerCapita > c2.pibPerCapita) printf("🏆 %s\n", c1.cidade);
    else if (c2.pibPerCapita > c1.pibPerCapita) printf("🏆 %s\n", c2.cidade);
    else printf("Empate\n");

    // Super Poder (maior vence)
    printf("Super Poder: %.2lf x %.2lf => ", c1.superPoder, c2.superPoder);
    if (c1.superPoder > c2.superPoder) printf("🏆 %s\n", c1.cidade);
    else if (c2.superPoder > c1.superPoder) printf("🏆 %s\n", c2.cidade);
    else printf("Empate\n");
}

int main() {
    Carta cartas[4];

    // Dados fixos para os 4 exemplos
    strcpy(cartas[0].codigo, "A01");
    strcpy(cartas[0].pais, "Brasil");
    strcpy(cartas[0].cidade, "São Paulo");
    cartas[0].populacao = 12.3;
    cartas[0].area = 1521.11;
    cartas[0].pib = 430;
    cartas[0].pontosTuristicos = 10;

    strcpy(cartas[1].codigo, "B01");
    strcpy(cartas[1].pais, "Japão");
    strcpy(cartas[1].cidade, "Tóquio");
    cartas[1].populacao = 13.9;
    cartas[1].area = 2194.07;
    cartas[1].pib = 2000;
    cartas[1].pontosTuristicos = 15;

    strcpy(cartas[2].codigo, "C01");
    strcpy(cartas[2].pais, "EUA");
    strcpy(cartas[2].cidade, "Nova York");
    cartas[2].populacao = 8.4;
    cartas[2].area = 783.8;
    cartas[2].pib = 2000;
    cartas[2].pontosTuristicos = 25;

    strcpy(cartas[3].codigo, "D01");
    strcpy(cartas[3].pais, "França");
    strcpy(cartas[3].cidade, "Paris");
    cartas[3].populacao = 2.1;
    cartas[3].area = 105.4;
    cartas[3].pib = 850;
    cartas[3].pontosTuristicos = 30;

    // Calcular propriedades derivadas e super poder para cada carta
    for (int i = 0; i < 4; i++) {
        calcularPropriedades(&cartas[i]);
    }

    printf("Cartas disponíveis:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d - %s (%s) - Código: %s\n", i+1, cartas[i].cidade, cartas[i].pais, cartas[i].codigo);
    }

    int c1, c2;
    printf("\nEscolha a primeira carta (1-4): ");
    scanf("%d", &c1);
    printf("Escolha a segunda carta (1-4): ");
    scanf("%d", &c2);

    if (c1 < 1 || c1 > 4 || c2 < 1 || c2 > 4 || c1 == c2) {
        printf("Escolha inválida!\n");
        return 1;
    }

    exibirCarta(cartas[c1-1]);
    exibirCarta(cartas[c2-1]);

    compararCartas(cartas[c1-1], cartas[c2-1]);

    return 0;
}
