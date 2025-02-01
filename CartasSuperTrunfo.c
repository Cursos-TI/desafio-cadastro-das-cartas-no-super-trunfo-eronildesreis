#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

// Função para exibir os dados da cidade
void exibir_dados(Cidade cidade, char estado, int cidade_num) {
    printf("Dados da Cidade %c%02d:\n", estado, cidade_num);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões de dólares\n", cidade.pib);
    printf("Pontos Turísticos: %d\n\n", cidade.pontos_turisticos);
}

int main() {
    Cidade cartas[NUM_ESTADOS][NUM_CIDADES];
    char estado;
    int cidade_num;
    
    // Cadastro das cartas
    for (estado = 'A'; estado <= 'H'; estado++) {
        for (cidade_num = 1; cidade_num <= NUM_CIDADES; cidade_num++) {
            printf("Cadastro da Cidade %c%02d:\n", estado, cidade_num);
            printf("Digite a População: ");
            scanf("%d", &cartas[estado - 'A'][cidade_num - 1].populacao);
            printf("Digite a Área (em km²): ");
            scanf("%f", &cartas[estado - 'A'][cidade_num - 1].area);
            printf("Digite o PIB (em bilhões de dólares): ");
            scanf("%f", &cartas[estado - 'A'][cidade_num - 1].pib);
            printf("Digite o número de Pontos Turísticos: ");
            scanf("%d", &cartas[estado - 'A'][cidade_num - 1].pontos_turisticos);
            printf("\n");
        }
    }

    // Exibição das cartas cadastradas
    for (estado = 'A'; estado <= 'H'; estado++) {
        for (cidade_num = 1; cidade_num <= NUM_CIDADES; cidade_num++) {
            exibir_dados(cartas[estado - 'A'][cidade_num - 1], estado, cidade_num);
        }
    }

    return 0;
}
