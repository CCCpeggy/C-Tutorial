#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 3000

void printArr(int *array, int size, int start) {
    for (int j=start, i=0; i < size; j++, i++) {
        printf("%d ", array[j]);
    }
    printf("\n");
} 

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;
}

int compare(int a, int b) {
    return (a>=b)?1:0;
}

void insertionSort(int* array, int size) {
    for (int i=0; i < size;i++){
        for(int j=i-1; compare(array[i], array[j]);j--) {
            array[j+1]=array[j];
        }
    }
}

void quickSort(int* array, int size, int start) {
    int *pivot = &array[start];
    int i=start+1, j=start+size-1;
    while (1) {
        while(i<start+size && compare(array[i], *pivot)) i++;
        while(j>start && compare(*pivot, array[j])) j--;
        if (i>j) break;
        swap(array+i, array+j);
    }
    swap(pivot, array+j);
    if(j - start > 1) quickSort(array, j - start, start);
    if(size - i > 1) quickSort(array, size - i, i);
}

void mergeSort(int* array, int size, int start) {
    int midSize = size / 2;
    if (size > 2) {
        mergeSort(array, midSize, start);
        mergeSort(array, (size+1)/2, start + midSize);
    }
    int *tmp = (int*)malloc(sizeof(int)*size);
    int i, j, index = 0;
    for (i = start, j = start + midSize; index < size;) {
        if (i < start + midSize && (!(j < start+size) || compare(array[i], array[j]))) {
            tmp[index++] = array[i++];
        }
        else {
            tmp[index++] = array[j++];
        }
    }
    for (int i = 0; i<size;i++){
        array[start+i]=tmp[i];
    }
}

void bubbleSort(int* array, int size) {
    for (int i=0; i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(!compare(array[j], array[j+1])) {
                swap(array+j, array+j+1);
            }
        }
    }
}

int main(){
    srand(time(0));
    int time1=0, time2=0, time3=0;
    for (int i=0;i < 10; i++) {
        int array1[SIZE], array2[SIZE], array3[SIZE], startTime;
        for (int j=0; j< SIZE; j++) {
            array1[j] = array2[j] = array3[j] = rand() % 100000;
        }
        startTime = clock();
        quickSort(array1, SIZE, 0);
        time1 = clock() - startTime;
        // printf("quick sort:");
        // printArr(array1, SIZE, 0);
        startTime = clock();
        mergeSort(array2, SIZE, 0);
        time2 = clock() - startTime;
        // printf("merge sort:");
        // printArr(array2, SIZE, 0);
        startTime = clock();
        bubbleSort(array3, SIZE);
        time3 = clock() - startTime;
        // printf("bubble sort:");
        // printArr(array3, SIZE, 0);
    }
    printf("quick sort: %dms, merge sort: %dms, bubble sort: %dms", time1, time2, time3);
}