#include <stdio.h>

void heapify(int v[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && v[esq] > v[maior])
        maior = esq;
    if (dir < n && v[dir] > v[maior])
        maior = dir;

    if (maior != i) {
        int tmp = v[i];
        v[i] = v[maior];
        v[maior] = tmp;
        heapify(v, n, maior);
    }
}

void heapSort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        heapify(v, i, 0);
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

        heapSort(v, n);

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
