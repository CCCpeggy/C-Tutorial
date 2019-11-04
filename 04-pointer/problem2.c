#include <stdio.h>
#define MIN -2147483638
#define MAX 2147483647

void find(int * max, int * min, int arr[], int arrSize){
    *max = MIN;
    *min = MAX;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
}

int main(){
    int myArr[] = {3, 15, 9, 0, 44, 55, 31};
    int max, min;
    find(&max, &min, myArr, 7);
    printf("max: %d, min: %d\n", max, min);
}