#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("hello world\n");

    int table[][3]={
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    system("pause");
}
