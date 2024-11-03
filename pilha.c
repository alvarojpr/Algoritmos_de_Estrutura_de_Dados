#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Tamanho máximo da pilha

// Definição da estrutura da pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1; // Pilha vazia
}

// Função para verificar se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Função para empilhar um elemento
void empilhar(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = valor; // Incrementa o topo e adiciona o valor
}

// Função para desempilhar um elemento
int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Retorna -1 em caso de pilha vazia
    }
    return p->itens[p->topo--]; // Retorna o valor e decrementa o topo
}

// Função para visualizar o elemento do topo da pilha
int topoPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Retorna -1 em caso de pilha vazia
    }
    return p->itens[p->topo]; // Retorna o valor do topo
}

// Função principal para testar a pilha
int main() {
    Pilha p;
    inicializarPilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    printf("Elemento no topo: %d\n", topoPilha(&p));
    
    printf("Desempilhando: %d\n", desempilhar(&p));
    printf("Elemento no topo após desempilhar: %d\n", topoPilha(&p));

    return 0;
}
