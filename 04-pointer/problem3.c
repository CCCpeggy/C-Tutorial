#include <stdio.h> 
#include <stdlib.h>

void inputArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", arr + i);
    }
}

void outputArray(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int* copyArray(int * arr, int size){
    int *newArr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        *(newArr + i) = *(arr + i);
    }
    return newArr;
}

void sortArray(int * arr, int size){
    for(int i = 0; i < size - 1; i++){
        int *min = arr + i;
        for(int j = i + 1; j < size; j++){
            if(*(arr + j) < *min) min = arr + j;
        }
        int tmp = *min;
        *min = *(arr + i);
        *(arr + i) = tmp;
    }
}

int* searchValueInArray(int * arr, int arrSize, int value){
    for(int i = 0; i < arrSize; i++){
        if(*(arr + i) == value) return arr + i;
    }
    return NULL;
}

int main(){
    int sen[] = {65, 72, 0, 0, 'p', 121, -1, 116, 105, 114, 66, 104, 100, 97, 10000, 33, 94, 118, 94, 382};
    int size1 = 20;
    
    int * exist;
    exist = searchValueInArray(sen, size1, -1);
    if(exist) *exist += 33;
    int * notExist = searchValueInArray(sen, size1, 1023);
    if(notExist) *notExist = -21324;

    inputArray(sen + 2, 2); // 97 112

    sortArray(sen + 7, 4);

    int *sen2;
    int size2 = size1 - 2;
    sen2 = copyArray(sen + 1, size2);
    
    exist = searchValueInArray(sen2, size2, 10000);
    if(exist) *exist = 121;

    for(int i = 0; i < size2; i++){
        printf("%c", *(sen2 + i));
    }
    system("pause");
}
 //72 97 112 112 121 32 66 105 114 116 104 100 97 121 33 94 118 94