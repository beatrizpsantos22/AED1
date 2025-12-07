#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, B;

    while (1) {
        scanf("%d %d", &N, &B);

        if (N == 0 && B == 0)
            break;

        int v[B];
        for (int i = 0; i < B; i++) {
            scanf("%d", &v[i]);
        }

        int dif[N + 1];
        for (int i = 0; i <= N; i++)
            dif[i] = 0;

        for (int i = 0; i < B; i++) {
            for (int j = i; j < B; j++) {
                int d = abs(v[i] - v[j]);
                if (d <= N)
                    dif[d] = 1;
            }
        }

        int ok = 1;
        for (int i = 0; i <= N; i++) {
            if (!dif[i]) {
                ok = 0;
                break;
            }
        }

        if (ok)
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}
