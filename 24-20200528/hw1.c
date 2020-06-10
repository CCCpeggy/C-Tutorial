#include <stdio.h>

#define SIZE 10

typedef struct FRAC {
    int integral;
    int numberator;
    int denominator;
}FRAC;

int findGCD(int a, int b) 
{
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
    if (a == b) 
        return a;
    if (a > b) 
        return findGCD(a-b, b); 
    return findGCD(a, b-a); 
} 

void toMixed(FRAC* frac) {
    frac->integral += frac->numberator / frac->denominator;
    frac->numberator = frac->numberator % frac->denominator;
    int gcd = findGCD(frac->numberator, frac->denominator);
    frac->numberator /= gcd;
    frac->denominator /= gcd;
}

FRAC computeSum(FRAC* frac) {
    FRAC sum = {0, 0, 1};
    for (int i = 0; i < SIZE; i++) {
        sum.integral += frac[i].integral;
        sum.numberator *= frac[i].denominator;
        sum.numberator += sum.denominator * frac[i].numberator;
        sum.denominator *= frac[i].denominator;
        toMixed(&sum);
    }
    return sum;
}

FRAC computeAver(FRAC* frac) {
    FRAC aver = computeSum(frac);
    aver.numberator += aver.denominator * aver.integral;
    aver.integral = 0;
    aver.denominator *= SIZE;
    toMixed(&aver);
    return aver;
}

int main() {
    FRAC farr[SIZE];
    for (int i = 0; i < SIZE;i++) {
        scanf("%d%d%d", &farr[i].integral, &farr[i].numberator, &farr[i].denominator);
    }
    FRAC sum = computeSum(farr);
    FRAC aver = computeAver(farr);
    printf("sum: %d + %d / %d\n", sum.integral, sum.numberator, sum.denominator);
    printf("aver: %d + %d / %d\n", aver.integral, aver.numberator, aver.denominator);
}