#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char pergunta[1000];

    scanf("%d", &N);
    getchar(); 

    while (N--) {
        fgets(pergunta, sizeof(pergunta), stdin); 
        printf("gzuz\n");
    }

    return 0;
}
