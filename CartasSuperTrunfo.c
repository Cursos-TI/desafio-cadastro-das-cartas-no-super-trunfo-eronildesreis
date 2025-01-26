#include <stdio.h>  // Biblioteca padrão para entrada e saída de dados

// Definição de constantes
#define NUM_ESTADOS 8          // Número de estados (A a H)
#define CARTAS_POR_ESTADO 4    // Número de cidades por estado

// Estrutura para representar uma carta de cidade
typedef struct {
    char codigo[4];           // Código da carta (ex.: A01, B02)
    char nomeCidade[50];      // Nome da cidade
    int populacao;            // População da cidade
    float area;               // Área da cidade em km²
    float pib;                // Produto Interno Bruto da cidade
    int pontosTuristicos;     // Número de pontos turísticos
} Carta;

int main() {
    // Declaração de variáveis
    Carta cartas[NUM_ESTADOS * CARTAS_POR_ESTADO];  // Array para armazenar todas as cartas
    int totalCartas = 0;                            // Contador para rastrear o número total de cartas cadastradas

    // Mensagem de boas-vindas
    printf("Bem-vindo ao sistema de cadastro de cartas do jogo Super Trunfo - Países!\n");
    printf("Você cadastrará %d estados, cada um com %d cidades.\n\n", NUM_ESTADOS, CARTAS_POR_ESTADO);

    // Loop externo para percorrer os estados (A-H)
    for (char estado = 'A'; estado < 'A' + NUM_ESTADOS; estado++) {
        printf("Cadastro de cartas para o estado %c:\n", estado);

        // Loop interno para cadastrar as cidades de cada estado
        for (int cidade = 1; cidade <= CARTAS_POR_ESTADO; cidade++) {
            // Gera o código da carta automaticamente (ex.: A01, B02)
            sprintf(cartas[totalCartas].codigo, "%c%02d", estado, cidade);

            // Exibe qual carta está sendo cadastrada
            printf("Carta %s:\n", cartas[totalCartas].codigo);

            // Solicita o nome da cidade
            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]", cartas[totalCartas].nomeCidade);  // Lê a entrada incluindo espaços

            // Solicita a população da cidade
            printf("Digite a população: ");
            scanf("%d", &cartas[totalCartas].populacao);

            // Solicita a área da cidade em km²
            printf("Digite a área (em km²): ");
            scanf("%f", &cartas[totalCartas].area);

            // Solicita o PIB da cidade
            printf("Digite o PIB: ");
            scanf("%f", &cartas[totalCartas].pib);

            // Solicita o número de pontos turísticos
            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &cartas[totalCartas].pontosTuristicos);

            // Mensagem de confirmação
            printf("Carta %s cadastrada com sucesso!\n\n", cartas[totalCartas].codigo);

            // Incrementa o contador de cartas
            totalCartas++;
        }
    }

    // Exibe todas as cartas cadastradas
    printf("\n--- Cartas cadastradas ---\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("\nCarta %s:\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
    }

    // Mensagem de finalização
    printf("\nObrigado por usar o sistema de cadastro de cartas!\n");

    return 0;  // Indica que o programa foi executado com sucesso
}
