#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipoNo {
    int numero;
    struct tipoNo *proximo;
} tipoNo;

typedef struct tipoPilha {
    tipoNo *topo;
} tipoPilha;

void push(tipoPilha *pilha, int numero);
void moveTopo(tipoPilha *pilha);
void stack(tipoPilha *pilha);
void erase(tipoPilha *pilha);
void jogar(tipoPilha *pilha, int *descartes, short *qtsDescartes);

int main() {
    unsigned short carta;
    tipoPilha pilha;
    short i;

    while (true) {
        scanf("%hu", &carta);
        if (carta == 0) break;

        stack(&pilha);
        int descartes[50];
        short qtsDescartes = 0;

        // empilha de n até 1 (topo = 1)
        for (i = carta; i > 0; i--)
            push(&pilha, i);

        jogar(&pilha, descartes, &qtsDescartes);

        printf("Discarded cards:");
        for (i = 0; i < qtsDescartes; i++) {
            printf(" %d", descartes[i]);
            if (i != qtsDescartes - 1) printf(",");
        }
        printf("\nRemaining card: %d\n", pilha.topo->numero);

        erase(&pilha);
    }

    return 0;
}

void stack(tipoPilha *pilha) {
    pilha->topo = NULL;
}

void push(tipoPilha *pilha, int carta) {
    tipoNo *auxiliar = (tipoNo *) malloc(sizeof(tipoNo));
    auxiliar->numero = carta;
    auxiliar->proximo = pilha->topo;
    pilha->topo = auxiliar;
}

// Move o topo atual para base da pilha
void moveTopo(tipoPilha *pilha) {
    if (!pilha->topo || !pilha->topo->proximo) return;

    tipoNo *auxiliar = pilha->topo;
    pilha->topo = auxiliar->proximo;

    tipoNo *base = pilha->topo;
    while (base->proximo) base = base->proximo;

    auxiliar->proximo = NULL;
    base->proximo = auxiliar;
}

void jogar(tipoPilha *pilha, int *descartes, short *qtsDescartes) {
    while (pilha->topo && pilha->topo->proximo) {
        // descarta topo
        tipoNo *aux = pilha->topo;
        descartes[(*qtsDescartes)++] = aux->numero;
        pilha->topo = aux->proximo;
        free(aux);

        // move próximo para base
        moveTopo(pilha);
    }
}

void erase(tipoPilha *pilha) {
    tipoNo *aux;
    while (pilha->topo) {
        aux = pilha->topo;
        pilha->topo = aux->proximo;
        free(aux);
    }
}
