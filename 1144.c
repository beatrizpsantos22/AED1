#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int i2 = i * i;
        int i3 = i * i * i;

        printf("%d %d %d\n", i, i2, i3);
        printf("%d %d %d\n", i, i2 + 1, i3 + 1);
    }

    return 0;
}
