#include <stdio.h>
void outputArr(int arr[], int size){
    int *ptr = arr;
    for(int i = 0; i < size; i++){
        printf("%d ", *arr++);
    }
    printf("\n");
}

int main(){
    int arr[] = {0, 33, 55, 66, 22, 44, 74};
    outputArr(arr, 7);
}