#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int caso = 1; caso <= T; caso++) {
        int n, m;
        scanf("%d", &n);
        int A[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        scanf("%d", &m);
        int B[m];
        for (int i = 0; i < m; i++)
            scanf("%d", &B[i]);

        int resposta = n + m; 

        for (int mascaraA = 0; mascaraA < (1 << n); mascaraA++) {

            int removidosA = 0;

            for (int i = 0; i < n; i++)
                if (!(mascaraA & (1 << i)))
                    removidosA++;

            int removidosB = 0;

            for (int j = 0; j < m; j++) {
                int manterB = 1;

                for (int i = 0; i < n; i++) {
                    if (mascaraA & (1 << i)) {
                        if (B[j] % A[i] == 0) {
                            manterB = 0;
                            break;
                        }
                    }
                }

                if (!manterB)
                    removidosB++;
            }


            int total = removidosA + removidosB;
            if (total < resposta)
                resposta = total;
        }

        printf("Case %d: %d\n", caso, resposta);
    }

    return 0;
}
