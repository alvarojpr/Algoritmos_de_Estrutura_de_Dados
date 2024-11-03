#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Tamanho máximo da fila

// Definição da estrutura da fila
typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila *f) {
    f->frente = 0; // Índice da frente
    f->tras = -1;  // Índice do trás
}

// Função para verificar se a fila está cheia
int filaCheia(Fila *f) {
    return (f->tras + 1) % MAX == f->frente;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *f) {
    return f->frente == (f->tras + 1) % MAX;
}

// Função para enfileirar um elemento
void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->tras = (f->tras + 1) % MAX; // Atualiza o índice do trás
    f->itens[f->tras] = valor;      // Adiciona o valor
}

// Função para desenfileirar um elemento
int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Retorna -1 em caso de fila vazia
    }
    int valor = f->itens[f->frente]; // Guarda o valor da frente
    f->frente = (f->frente + 1) % MAX; // Atualiza o índice da frente
    return valor; // Retorna o valor desenfileirado
}

// Função principal para testar a fila
int main() {
    Fila f;
    inicializarFila(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    printf("Desenfileirando: %d\n", desenfileirar(&f));
    printf("Desenfileirando: %d\n", desenfileirar(&f));

    enfileirar(&f, 40);
    printf("Desenfileirando: %d\n", desenfileirar(&f));

    return 0;
}
