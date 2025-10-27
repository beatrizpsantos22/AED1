#include <stdio.h>
#include <string.h>

#define MAX 1000  

int main(void) {
    char expr[MAX];
    
    while (scanf("%s", expr) != EOF) {
        int topo = 0;  // topo da pilha
        int i;
        int balanceado = 1;

        for (i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                // empilha
                if (topo < MAX) {
                    topo++;
                }
            } else if (expr[i] == ')') {
                // desempilha
                if (topo > 0) {
                    topo--;
                } else {
                    balanceado = 0;
                    break;
                }
            }
        }

        if (balanceado && topo == 0)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
