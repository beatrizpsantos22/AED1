#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100003  

typedef struct No {
    char nome[60];
    struct No *prox;
} No;

No *tabela[TAM];

unsigned long hash(char *s) {
    unsigned long h = 0;
    int i = 0;
    while (s[i]) {
        h = (h * 131 + s[i]) % TAM;
        i++;
    }
    return h;
}

int buscar(char *s) {
    unsigned long h = hash(s);
    No *atual = tabela[h];
    while (atual != NULL) {
        if (strcmp(atual->nome, s) == 0) return 1; 
        atual = atual->prox;
    }
    return 0;
}

void inserir(char *s) {
    unsigned long h = hash(s);
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->nome, s);
    novo->prox = tabela[h];
    tabela[h] = novo;
}

int main() {
    char amuleto[60];
    int total_unicos = 0;

    for (int i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }

    while (scanf("%s", amuleto) != EOF) {
        if (!buscar(amuleto)) {
            inserir(amuleto);
            total_unicos++;
        }
    }

    printf("%d\n", total_unicos);

    return 0;
}
