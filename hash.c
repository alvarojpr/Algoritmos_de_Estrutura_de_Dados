#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Tamanho máximo da tabela hash
#define TAM_CHAVE 20 // Tamanho máximo da chave

// Estrutura para representar um item da tabela hash
typedef struct Item {
    char chave[TAM_CHAVE];
    int valor;
    struct Item* proximo;
} Item;

// Estrutura para representar a tabela hash
typedef struct TabelaHash {
    Item* tabela[MAX];
} TabelaHash;

// Função para inicializar a tabela hash
void inicializarTabela(TabelaHash* hash) {
    for (int i = 0; i < MAX; i++) {
        hash->tabela[i] = NULL;
    }
}

// Função para calcular o índice da tabela hash
int funcaoHash(char* chave) {
    int soma = 0;
    for (int i = 0; i < strlen(chave); i++) {
        soma += chave[i];
    }
    return soma % MAX;
}

// Função para inserir um item na tabela hash
void inserir(TabelaHash* hash, char* chave, int valor) {
    int indice = funcaoHash(chave);
    Item* novoItem = (Item*)malloc(sizeof(Item));
    strcpy(novoItem->chave, chave);
    novoItem->valor = valor;
    novoItem->proximo = hash->tabela[indice]; // Insere no início da lista encadeada
    hash->tabela[indice] = novoItem;
}

// Função para buscar um item na tabela hash
int buscar(TabelaHash* hash, char* chave) {
    int indice = funcaoHash(chave);
    Item* atual = hash->tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->valor; // Retorna o valor se a chave for encontrada
        }
        atual = atual->proximo;
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

// Função para imprimir a tabela hash
void imprimirTabela(TabelaHash* hash) {
    for (int i = 0; i < MAX; i++) {
        Item* atual = hash->tabela[i];
        if (atual != NULL) {
            printf("Indice %d: ", i);
            while (atual != NULL) {
                printf("(%s: %d) -> ", atual->chave, atual->valor);
                atual = atual->proximo;
            }
            printf("NULL\n");
        }
    }
}

// Função principal para testar a tabela hash
int main() {
    TabelaHash hash;
    inicializarTabela(&hash);

    inserir(&hash, "chave1", 10);
    inserir(&hash, "chave2", 20);
    inserir(&hash, "chave3", 30);
    inserir(&hash, "chave1", 40); // Atualiza valor para chave1

    imprimirTabela(&hash);

    printf("Valor associado à chave 'chave2': %d\n", buscar(&hash, "chave2"));
    printf("Valor associado à chave 'chave1': %d\n", buscar(&hash, "chave1"));
    printf("Valor associado à chave 'chave4': %d\n", buscar(&hash, "chave4")); // Não existe

    return 0;
}
