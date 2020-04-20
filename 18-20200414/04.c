#include <stdio.h>
#include <stdlib.h>

int pow2(int* arr, int p) {
    int *sum = (int*)calloc((p + p + 1), sizeof(int));
    for (int i=p; i>=0; i--) {
        for (int j=p; j>=0; j--) {
            sum[i + j] += arr[i]*arr[j];
        }
    }
    for (int i=p+p; i>0; i--) {
        if (sum[i]>=10) sum[i-1] += sum[i]/10;
    }
    return sum[0];
}

int main() {
    int num, pre;
    while (scanf("%d%d", &num, &pre) != EOF) {
        int *arr = (int*)malloc(sizeof(int) * (pre+1));
        for(int i = 0; i <= pre; i++) {
            int* place = arr + i;
            *place = 0;
            while (1) {
               if (pow2(arr, i) >= num) break;
                (*place)++;
            }
            (*place)--;
            printf("%d", *place);
            if(i == 0) printf(".");
        }
        printf("\n");
    }
}