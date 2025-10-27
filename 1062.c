#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        while (1) {
            int ordem[MAX];
            int i;

            scanf("%d", &ordem[0]);
            if (ordem[0] == 0) {
                printf("\n"); 
                break;
            }

            // lê o resto da sequência
            for (i = 1; i < n; i++)
                scanf("%d", &ordem[i]);

            // simulação com pilha
            int pilha[MAX];
            int topo = -1;    
            int atual = 1;    
            int pos = 0;      

            while (atual <= n || topo >= 0) {
                if (topo >= 0 && pilha[topo] == ordem[pos]) {
                    topo--;
                    pos++;
                } else if (atual <= n) {
                    pilha[++topo] = atual++;
                } else {
                    break;
                }
            }

            if (pos == n)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
