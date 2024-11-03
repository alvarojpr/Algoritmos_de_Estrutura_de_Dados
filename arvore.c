#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else {
        raiz->direito = inserir(raiz->direito, valor);
    }
    return raiz;
}

// Função para percorrer a árvore em ordem (in-order)
void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        percorrerEmOrdem(raiz->direito);
    }
}

// Função principal para testar a árvore binária
int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 40);
    inserir(raiz, 20);
    inserir(raiz, 60);
    inserir(raiz, 10);
    inserir(raiz, 30);
    inserir(raiz, 50);
    inserir(raiz, 70);

    printf("Percurso em ordem da árvore: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    return 0;
}
