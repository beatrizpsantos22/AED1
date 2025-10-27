#include <stdio.h>

void merge(int v[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

void mergeSort(int v[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
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

        mergeSort(v, 0, n - 1);

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
