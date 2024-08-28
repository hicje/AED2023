#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox; // ponteiro para próximo
    struct no *ant;  // ponteiro para anterior
} Lista;

// Função para verificar se a lista está vazia
int vazia(Lista *L) {
    return (L == NULL);
}

// Função para remover um nó da lista duplamente encadeada circular
Lista* remover(Lista *L, int info) {
    if (vazia(L)) return L; // Se a lista estiver vazia, retorna a cabeça (NULL)

    Lista *atual = L;

    // Percorrer a lista para encontrar o nó a ser removido
    do {
        if (atual->info == info) {
            // Se o nó a ser removido é o único na lista
            if (atual->prox == atual) {
                free(atual);
                return NULL;
            }

            // Ajustar os ponteiros dos nós adjacentes
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;

            // Se o nó a ser removido é a cabeça da lista
            if (atual == L) {
                L = atual->prox;
            }

            free(atual);
            return L; // Retorna a nova cabeça da lista
        }

        atual = atual->prox;
    } while (atual != L); // Continua até completar o ciclo na lista circular

    return L; // Retorna a lista inalterada se o elemento não for encontrado
}

// Função para inserir um nó no início da lista
Lista* inserir(Lista *L, int info) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = info;
    if (vazia(L)) {
        novo->prox = novo->ant = novo;
        return novo;
    }
    novo->prox = L;
    novo->ant = L->ant;
    L->ant->prox = novo;
    L->ant = novo;
    return novo;
}

// Função para imprimir a lista (para fins de teste)
void imprimir_lista(Lista *L) {
    if (vazia(L)) return;
    Lista *inicio = L;
    do {
        printf("%d ", L->info);
        L = L->prox;
    } while (L != inicio);
    printf("\n");
}

int main() {
    Lista *L = NULL;

    // Inserindo elementos na lista
    L = inserir(L, 10);
    L = inserir(L, 20);
    L = inserir(L, 30);
    L = inserir(L, 40);

    printf("Lista original: ");
    imprimir_lista(L);

    // Removendo elementos
    L = remover(L, 20);
    printf("Lista após remover 20: ");
    imprimir_lista(L);

    L = remover(L, 40);
    printf("Lista após remover 40: ");
    imprimir_lista(L);

    L = remover(L, 10);
    printf("Lista após remover 10: ");
    imprimir_lista(L);

    L = remover(L, 30);
    printf("Lista após remover 30: ");
    imprimir_lista(L);

    return 0;
}
