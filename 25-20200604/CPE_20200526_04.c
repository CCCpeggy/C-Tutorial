#include <stdio.h>

int main(){
    int times;
    while(scanf("%d", &times)!=EOF){
        int key, door;
        long long int ans = 0;
        while(times--)
        {
            scanf("%d%d", &key, &door);
            ans = ((long long int)(door - 1) + (door - key))* key /2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}