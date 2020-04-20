#include <stdio.h>
#define PRICEE(x) (((x)+1)*(x)/2)

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int N;
        long long M;
        scanf("%d %lld", &N, &M);
        int *machine = (int*)malloc(sizeof(int) * N);
        for (int i=0;i<N;i++){
            scanf("%d", machine[i]);
        }

    }
}