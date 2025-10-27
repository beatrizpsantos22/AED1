#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char simbolo;
    struct No *prox;
} No;

void push(No **topo, char simbolo) {
    No *novo = (No *) malloc(sizeof(No));
    novo->simbolo = simbolo;
    novo->prox = *topo;
    *topo = novo;
}

void pop(No **topo) {
    if (*topo != NULL) {
        No *temp = *topo;
        *topo = (*topo)->prox;
        free(temp);
    }
}

int pilhaVazia(No *topo) {
    return topo == NULL;
}

void limparPilha(No **topo) {
    while (!pilhaVazia(*topo)) {
        pop(topo);
    }
}

int main(void) {
    char expr[1000];

    while (scanf("%s", expr) != EOF) {
        No *pilha = NULL;
        int balanceado = 1;

        for (int i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                push(&pilha, '(');
            } else if (expr[i] == ')') {
                if (!pilhaVazia(pilha)) {
                    pop(&pilha);
                } else {
                    balanceado = 0; 
                    break;
                }
            }
        }

        if (balanceado && pilhaVazia(pilha))
            printf("correct\n");
        else
            printf("incorrect\n");

        limparPilha(&pilha);
    }

    return 0;
}
