#include <stdio.h>

void swap(int * n1, int * n2){
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("before: %d %d\n", num1, num2);
    swap(&num1, &num2);
    printf("after: %d %d\n", num1, num2);
}