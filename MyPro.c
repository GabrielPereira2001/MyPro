#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 50

// Estrutura para armazenar informações do cliente
typedef struct {
    char nome[50];
    int idade;
    char cpf[15];
    float renda;
} Cliente;

// Estrutura para armazenar informações do carro
typedef struct {
    char modelo[50];
    float preco;
} Carro;

// Função para cadastrar informações do cliente
void cadastrarCliente(Cliente *clientes, int *numClientes) {
    Cliente novoCliente;
    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente.nome);
    printf("Digite a idade do cliente: ");
    scanf("%d", &novoCliente.idade);
    printf("Digite o CPF do cliente: ");
    scanf("%s", novoCliente.cpf);
    printf("Digite a renda do cliente: ");
    scanf("%f", &novoCliente.renda);
    clientes[*numClientes] = novoCliente;
    *numClientes += 1;
    printf("Cliente cadastrado com sucesso!\n");
}

// Função para recomendar um carro com base na renda do cliente
void recomendarCarro(Cliente *clientes, int numClientes, Carro *carros, int numCarros) {
    char cpf[15];
    printf("Digite o CPF do cliente para recomendar um carro: ");
    scanf("%s", cpf);
    Cliente *cliente = NULL;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            cliente = &clientes[i];
            break;
        }
    }
    if (cliente == NULL) {
        printf("CPF não encontrado!\n");
        return;
    }
    float precoMaximo = cliente->renda * 0.3; // Cliente pode gastar no máximo 30% da renda com carro
    Carro *carroRecomendado = NULL;
    for (int i = 0; i < numCarros; i++) {
        if (carros[i].preco <= precoMaximo) {
            if (carroRecomendado == NULL || carros[i].preco > carroRecomendado->preco) {
                carroRecomendado = &carros[i];
            }
        }
    }
    if (carroRecomendado == NULL) {
        printf("Não há carros disponíveis dentro do orçamento do cliente!\n");
    } else {
        printf("Carro recomendado para %s: %s (preço: %.2f)\n", cliente->nome, carroRecomendado->modelo, carroRecomendado->preco);
    }
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int numClientes = 0;
    Carro carros[] = {
        {"Carro 1", 30000.0},
        {"Carro 2", 50000.0},
        {"Carro 3", 70000.0},
        {"Carro 4", 90000.0},
        {"Carro 5", 110000.0},
        {"Carro 6", 130000.0},
        {"Carro 7", 150000.0},
        {"Carro 8", 170000.0},
