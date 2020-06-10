#include <stdio.h>

typedef struct Poly {
    int num[100];
    int maxCoe;
}Poly;

Poly compute(Poly *poly1, Poly *poly2) {
    int newCoe = poly1->maxCoe - poly2->maxCoe;
    Poly ans={{0}, newCoe >= 0? newCoe: 0};
    for(int i = newCoe; i >= 0; i--) {
        ans.num[i] = poly1->num[poly1->maxCoe] / poly2->num[poly2->maxCoe];
        for (int j = 0; j <= poly2->maxCoe; j++) {
            poly1->num[poly1->maxCoe - j] -= poly2->num[poly2->maxCoe - j] * ans.num[i];
        }
        poly1->maxCoe--;
    }
    return ans;
}

void printPoly(Poly *poly) {
    printf("%d", poly->maxCoe);
    for (int i = poly->maxCoe - 1; i >= 0; i--) {
        if (poly->num[i])
            printf(" %d", i);
    }
    printf("\n");
    printf("%d", poly->num[poly->maxCoe]);
    for (int i = poly->maxCoe - 1; i >= 0; i--) {
        if (poly->num[i])
            printf(" %d", poly->num[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char tmp;
        Poly poly[2] = {{{0}, 0}, {{0}, 0}};
        int coe[100];
        for (int i = 0; i < 2; i++){
            int size = 0;
            while(scanf("%d%c", &coe[size], &tmp) && tmp == ' ') {
                size++;
            }
            size++;
            poly[i].maxCoe = coe[0];
            for (int j = 0; j < size; j++) {
                scanf("%d", &poly[i].num[coe[j]]);
            }
        }
        Poly ans = compute(&poly[0], &poly[1]);
        printPoly(&ans);
        printPoly(&poly[0]);
    }
}