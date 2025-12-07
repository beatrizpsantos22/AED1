#include <stdio.h>
#include <limits.h> 

int main() {
    int i;
    int N;             
    int maior = INT_MIN;
    int maior_pos = 0;  


    for (i = 1; i <= 100; ++i) {
        // Leitura do valor atual
        scanf("%d", &N);


        if (N > maior) {
            maior = N;    
            maior_pos = i;  
        }
    }

    printf("%d\n", maior);

    printf("%d\n", maior_pos);

    return 0;
}
