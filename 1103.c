#include <stdio.h>

int main() {
    int H1, M1, H2, M2;

    while (1) {
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);

        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)
            break;

        int inicio = H1 * 60 + M1;
        int fim = H2 * 60 + M2;

        if (fim <= inicio)
            fim += 24 * 60;  // passou para o dia seguinte

        printf("%d\n", fim - inicio);
    }

    return 0;
}
