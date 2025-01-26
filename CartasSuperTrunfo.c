#include <stdio.h>
#include <string.h>

// Definição de constantes para o número de estados e cartas por estado
#define NUM_ESTADOS 8
#define CARTAS_POR_ESTADO 4

// Estrutura para representar uma carta de cidade
typedef struct {
    char estado;            // Letra do estado (A-H)
    char codigo[4];         // Código da carta (ex.: A01)
    char nomeCidade[50];    // Nome da cidade
    int populacao;          // População da cidade
    float area;             // Área da cidade em km²
    float pib;              // PIB da cidade
    int pontosTuristicos;   // Número de pontos turísticos
} Carta;

int main() {
    // Declaração de um array para armazenar todas as cartas
    Carta cartas[NUM_ESTADOS * CARTAS_POR_ESTADO];
    int totalCartas = 0; // Contador para o número total de cartas cadastradas

    // Laço principal para cadastrar as cartas
    for (char estado = 'A'; estado <= 'H'; estado++) { // Itera pelos estados A-H
        for (int i = 1; i <= CARTAS_POR_ESTADO; i++) { // Itera pelas 4 cartas de cada estado
            printf("\nCadastrando carta %c%02d:\n", estado, i);

            // Preenchendo os dados da carta
            cartas[totalCartas].estado = estado;
            sprintf(cartas[totalCartas].codigo, "%c%02d", estado, i); // Define o código da carta

            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]", cartas[totalCartas].nomeCidade); // Lê o nome da cidade (com espaços)

            printf("Digite a populacao: ");
            scanf("%d", &cartas[totalCartas].populacao); // Lê a população

            printf("Digite a area (em km²): ");
            scanf("%f", &cartas[totalCartas].area); // Lê a área

            printf("Digite o PIB: ");
            scanf("%f", &cartas[totalCartas].pib); // Lê o PIB

            printf("Digite o numero de pontos turisticos: ");
            scanf("%d", &cartas[totalCartas].pontosTuristicos); // Lê os pontos turísticos

            printf("\nCarta cadastrada com sucesso!\n");

            // Incrementa o contador de cartas cadastradas
            totalCartas++;
        }
    }

    // Exibindo as cartas cadastradas
    printf("\n--- Cartas cadastradas ---\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("\nCarta %s:\n", cartas[i].codigo);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("Populacao: %d habitantes\n", cartas[i].populacao);
        printf("Area: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f\n", cartas[i].pib);
        printf("Pontos Turisticos: %d\n", cartas[i].pontosTuristicos);
    }

    return 0;
}
