#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int *pos = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; ++i) {
        scanf("%d", &pos[i]); 
    }

    qsort(pos, k, sizeof(int), cmp_int);

    int days = 0;
   
    if (k > 0) {
        if (pos[0] - 1 > days) days = pos[0] - 1;
  
        for (int i = 0; i < k - 1; ++i) {
            int gap = pos[i+1] - pos[i];
            int need = gap / 2; // floor((b-a)/2)
            if (need > days) days = need;
        }
     
        if (n - pos[k-1] > days) days = n - pos[k-1];
    } else {
        days = n; // ou outro tratamento, dependendo do enunciado; normalmente k>=1
    }

    printf("%d\n", days);

    free(pos);
    return 0;
}
