#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[20];
    for (int i = 0; i < 20; i++) {
        //scanf("%d", arr + i);
        *(arr + i) = i;
    }
    int target;
    scanf("%d", &target);
    int* minIdx[3] = {0, 0, 0}, min = target;
    for (int i = 0; min && i < 20; i++) {
        for (int j = i + 1; min && j < 20; j++) {
            for (int k = j + 1; min && k < 20; k++) {
                int sum = *(arr + i) + *(arr + j) + *(arr + k);
                int diff = sum - target;
                diff = diff >= 0 ? diff : -diff;
                if (min > diff) {
                    minIdx[0] = arr + i;
                    minIdx[1] = arr + j;
                    minIdx[2] = arr + k;
                    min = diff;
                }
            }
        }
    }
    printf("%d %d %d\n", *minIdx[0], *minIdx[1], *minIdx[2]);
}