#include <stdio.h>
#include <stdlib.h>

void HanoiTower(char a, char b, char c, int n, int size){
    if(n>1) HanoiTower(a, c, b, n-1, size);
    printf("move size %s-%d from %c to %c\n",n%2?"green":"blue",(n+1)/2, a, c);
    
    if(n>1) HanoiTower(b, a, c, n-1, size);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        HanoiTower('1', '3', '2', n*2, n);
    }
}