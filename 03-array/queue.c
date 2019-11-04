#include <stdio.h>

int main(){
    int queue[100];
    int number = 1, N, size = 0;
    scanf("%d", &N);
    while(N--){
        int C;
        scanf("%d", &C);
        if(C==1){
            queue[size++] = number++;
            printf("[INSERT ORDER]\n");
        }
        else if(C==2){
            int delNum;
            scanf("%d", &delNum);
            for(int i = 0; i < size; i++){
                if(queue[i] == delNum){
                    for(int j = i+1; j < size; j++){
                        queue[j - 1] = queue[j];
                    }
                    size--;
                    break;
                }
            }
            printf("[DELETE ORDER]\n");
        }
        else if(C==3){
            for(int i = 0; i < size; i++){
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }
}