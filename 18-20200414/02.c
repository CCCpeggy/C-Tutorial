#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    while (scanf("%d%d", &N, &K) != EOF) {
        int **C = (int**) malloc(sizeof(int*) * N);
        for (int i = 0; i < N; i++) {
            C[i] = (int*) calloc(i + 2, sizeof(int));
            for (int j = 0; j <= i+1; j++) {
                C[i][j] = 1;
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
        printf("%d\n", C[N - 1][K]);
    }
}