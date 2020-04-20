#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main() {
    int size;
    while (scanf("%d", &size) != EOF) {
        srand(time(0));
        double **matrix2 = (double**)malloc(sizeof(double*) * size);
        double **iMatrix = (double**)malloc(sizeof(double*) * size);
        bool noInverse = false;
        printf("origin: \n");
        for (int i = 0; i < size; i++){
            matrix2[i] = (double*)malloc(sizeof(double) * size);
            iMatrix[i] = (double*)malloc(sizeof(double) * size);
            for (int j = 0; j < size; j++) {
                matrix2[i][j] = rand() % 10 - 5;
                iMatrix[i][j] = i == j ? 1 : 0;
            }
        }
        double matrix[3][3] = {
            {0, -5, -4},
            {4, 2, -3},
            {2, -4, -1},
        };
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", matrix[i][j]);
            }
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", iMatrix[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < size; i++){
            for (int k = 0; !matrix[i][i] && k < size; k++) {
                if (matrix[k][i]) {
                    for (int j = 0; j < size; j++) {
                        matrix[i][j] += matrix[k][j];
                        iMatrix[i][j] += iMatrix[k][j];
                    }
                }
            }
            if (!matrix[i][i]) {
                noInverse = true;
            }
        }
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", matrix[i][j]);
            }
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", iMatrix[i][j]);
            }
            printf("\n");
        }
        if (noInverse) {
            printf("no inverse matrix\n");
            continue;
        }
        for (int i = 0; i < size; i++){
            for (int k = 0; k < size; k++) {
                if (i == k) continue;
                double tmp = matrix[k][i] / matrix[i][i];
                for (int j = 0; j < size; j++) {
                    matrix[k][j] -= matrix[i][j] * tmp;
                    iMatrix[k][j] -= iMatrix[i][j] * tmp;
                }
            }
            for (int k = 0; k < size; k++) {
                for (int j = 0; j < size; j++) {
                    printf("%.2lf ", matrix[k][j]);
                }
                for (int j = 0; j < size; j++) {
                    printf("%.2lf ", iMatrix[k][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", matrix[i][j]);
            }
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", iMatrix[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < size; i++){
            double tmp = matrix[i][i];
            for (int j = 0; j < size; j++) {
                matrix[i][j] /= tmp;
                iMatrix[i][j] /= tmp;
            }
        }
        printf("Inverse: \n");
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", matrix[i][j]);
            }
            for (int j = 0; j < size; j++) {
                printf("%.2lf ", iMatrix[i][j]);
            }
            printf("\n");
        }
    }
}