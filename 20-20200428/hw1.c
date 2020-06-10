#include <stdio.h>

void checkLine(char *line, int *count){
    if (*count == 80) {
        printf("%s\n", line);
        *count = 0;
    }
}

int main() {
    char word[44];
    char line[81] = {0};
    int count = 0;
    while (scanf("%s", word) != EOF && word[0] != '>') {
        for (int i=1; word[i]; i++) {
            line[count++] = word[i];
            checkLine(line, &count);
        }
        line[count++] = word[0];
        checkLine(line, &count);
        line[count++] = 'a';
        checkLine(line, &count);
        line[count++] = 'y';
        checkLine(line, &count);
        line[count++] = ' ';
        checkLine(line, &count);
    }
    line[count] = 0;
    for (int i = 0; i <= (80 - count); i++) 
        printf(" ");
    printf("%s\n", line);
}