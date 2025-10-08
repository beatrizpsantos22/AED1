#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, posicao;
    int *p; 

    scanf("%d", &n);

    p = (int*) malloc(n * sizeof(int));
    if (p == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", (p + i)); 
    }

    int menor = *p;  // mesmo que p[0]
    posicao = 0;

    for (i = 1; i < n; i++) {
        if (*(p + i) < menor) {
            menor = *(p + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posição: %d\n", posicao);

    free(p);

    return 0;
}
