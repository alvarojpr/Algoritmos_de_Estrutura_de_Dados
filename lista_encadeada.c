#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para adicionar um nó no início da lista
void adicionarInicio(No** cabeca, int valor) {
    No* novoNo = criarNo(valor);
    novoNo->proximo = *cabeca; // O próximo do novo nó é a cabeça atual
    *cabeca = novoNo;          // Atualiza a cabeça da lista
}

// Função para imprimir a lista
void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função principal para testar a lista encadeada
int main() {
    No* lista = NULL; // Inicializa a lista vazia

    adicionarInicio(&lista, 10);
    adicionarInicio(&lista, 20);
    adicionarInicio(&lista, 30);

    printf("Lista encadeada: ");
    imprimirLista(lista);

    return 0;
}
