#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Tamanho máximo do heap

// Estrutura do max-heap
typedef struct {
    int tamanho;
    int elementos[MAX];
} MaxHeap;

// Função para criar um heap vazio
void inicializarHeap(MaxHeap* heap) {
    heap->tamanho = 0;
}

// Função para fazer a troca entre dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para manter a propriedade do max-heap
void heapify(MaxHeap* heap, int indice) {
    int maior = indice;
    int esquerda = 2 * indice + 1; // Índice do filho esquerdo
    int direita = 2 * indice + 2;  // Índice do filho direito

    if (esquerda < heap->tamanho && heap->elementos[esquerda] > heap->elementos[maior]) {
        maior = esquerda;
    }
    if (direita < heap->tamanho && heap->elementos[direita] > heap->elementos[maior]) {
        maior = direita;
    }
    if (maior != indice) {
        trocar(&heap->elementos[indice], &heap->elementos[maior]);
        heapify(heap, maior);
    }
}

// Função para inserir um elemento no max-heap
void inserir(MaxHeap* heap, int valor) {
    if (heap->tamanho >= MAX) {
        printf("Erro: Heap cheio!\n");
        return;
    }
    heap->elementos[heap->tamanho] = valor;
    int indice = heap->tamanho;
    heap->tamanho++;

    // Reorganiza o heap para manter a propriedade do max-heap
    while (indice > 0 && heap->elementos[indice] > heap->elementos[(indice - 1) / 2]) {
        trocar(&heap->elementos[indice], &heap->elementos[(indice - 1) / 2]);
        indice = (indice - 1) / 2;
    }
}

// Função para remover e retornar o maior elemento do max-heap
int removerMax(MaxHeap* heap) {
    if (heap->tamanho == 0) {
        printf("Erro: Heap vazio!\n");
        return -1; // Retorna -1 em caso de heap vazio
    }
    int max = heap->elementos[0];
    heap->elementos[0] = heap->elementos[heap->tamanho - 1];
    heap->tamanho--;
    heapify(heap, 0);
    return max;
}

// Função para imprimir o heap
void imprimirHeap(MaxHeap* heap) {
    for (int i = 0; i < heap->tamanho; i++) {
        printf("%d ", heap->elementos[i]);
    }
    printf("\n");
}

// Função principal para testar o max-heap
int main() {
    MaxHeap heap;
    inicializarHeap(&heap);

    inserir(&heap, 10);
    inserir(&heap, 30);
    inserir(&heap, 20);
    inserir(&heap, 5);
    inserir(&heap, 40);

    printf("Heap após inserções: ");
    imprimirHeap(&heap);

    printf("Removendo o maior elemento: %d\n", removerMax(&heap));
    printf("Heap após remoção: ");
    imprimirHeap(&heap);

    return 0;
}
