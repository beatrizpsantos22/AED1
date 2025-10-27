#include <stdio.h>

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min])
                min = j;
        }
        if (min != i) {
            int tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
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

        selectionSort(v, n);

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
