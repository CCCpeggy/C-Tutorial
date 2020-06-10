#include <stdio.h>

int main(){
    long long int array[10000];
    int num;
    while(scanf("%d", &num)!=EOF)
    {
        char ch;
        int size = 0;
        while(scanf("%lld%c", &array[size], &ch) && ch == ' '){
            size++;
        }
        size++;
        int i, j;
        long long int X, sum = 0;
        for(j=size-2, i=1, X = 1; j>=0;j--, X*=num,i++)
        {
            sum += array[j] * X * i;
        }
        printf("%lld\n", sum);
    }
    return 0;
}