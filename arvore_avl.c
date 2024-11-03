#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore AVL
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
    int altura;
} No;

// Função para obter a altura de um nó
int altura(No* no) {
    return (no == NULL) ? -1 : no->altura;
}

// Função para calcular o fator de balanceamento
int fatorBalanceamento(No* no) {
    return (no == NULL) ? 0 : altura(no->esquerdo) - altura(no->direito);
}

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    novoNo->altura = 0;
    return novoNo;
}

// Função para rotacionar à direita
No* rotacionarDireita(No* y) {
    No* x = y->esquerdo;
    y->esquerdo = x->direito;
    x->direito = y;
    y->altura = 1 + (altura(y->esquerdo) > altura(y->direito) ? altura(y->esquerdo) : altura(y->direito));
    x->altura = 1 + (altura(x->esquerdo) > altura(x->direito) ? altura(x->esquerdo) : altura(x->direito));
    return x;
}

// Função para rotacionar à esquerda
No* rotacionarEsquerda(No* x) {
    No* y = x->direito;
    x->direito = y->esquerdo;
    y->esquerdo = x;
    x->altura = 1 + (altura(x->esquerdo) > altura(x->direito) ? altura(x->esquerdo) : altura(x->direito));
    y->altura = 1 + (altura(y->esquerdo) > altura(y->direito) ? altura(y->esquerdo) : altura(y->direito));
    return y;
}

// Função para inserir um valor na árvore AVL
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else {
        raiz->direito = inserir(raiz->direito, valor);
    }

    raiz->altura = 1 + (altura(raiz->esquerdo) > altura(raiz->direito) ? altura(raiz->esquerdo) : altura(raiz->direito));

    int fator = fatorBalanceamento(raiz);

    // Caso de rotação à direita
    if (fator > 1 && valor < raiz->esquerdo->dado) {
        return rotacionarDireita(raiz);
    }

    // Caso de rotação à esquerda
    if (fator < -1 && valor > raiz->direito->dado) {
        return rotacionarEsquerda(raiz);
    }

    // Caso de rotação dupla à esquerda
    if (fator > 1 && valor > raiz->esquerdo->dado) {
        raiz->esquerdo = rotacionarEsquerda(raiz->esquerdo);
        return rotacionarDireita(raiz);
    }

    // Caso de rotação dupla à direita
    if (fator < -1 && valor < raiz->direito->dado) {
        raiz->direito = rotacionarDireita(raiz->direito);
        return rotacionarEsquerda(raiz);
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

// Função principal para testar a árvore AVL
int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 35);

    printf("Percurso em ordem da árvore AVL: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    return 0;
}
