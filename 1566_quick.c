#include <stdio.h>

void quickSort(int v[], int ini, int fim) {
    if (ini < fim) {
        int pivo = v[(ini + fim) / 2];
        int i = ini, j = fim, temp;

        while (i <= j) {
            while (v[i] < pivo) i++;
            while (v[j] > pivo) j--;
            if (i <= j) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
                j--;
            }
        }

        quickSort(v, ini, j);
        quickSort(v, i, fim);
    }
}

int main(void) {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        int v[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        quickSort(v, 0, n - 1);

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
