<!-- slide -->
# schoolHW

<!-- slide -->
## 第一題
<!-- Write a recursive function that converts a positive integer into its binary equivalent. The prototype of the function is as follows: void convert(int n), where n is the positive integer to be converted. -->

<!-- slide vertical = true-->
## 第一題 - 參考輸入

``` text
10
20
30
40
50
60
70
80
```

## 第一題 - 參考輸出

``` text
binary: 1010
binary: 10100
binary: 11110
binary: 101000
binary: 110010
binary: 111100
binary: 1000110
binary: 1010000
```

<!-- slide vertical = true-->
## 第一題 - 參考程式碼

``` C
#include <stdio.h>

void binary (int n) {
    if (n) {
        binary(n >> 1);
        printf("%d", n % 2);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("binary: ");
        binary(n);
        printf("\n");
    }
}
```

<!-- slide -->
## 第二題

<!-- Write a recursive program to evaluate a prefix expr ession that involves only position integers, addition, and multiplication. Input to the program will consist of two lines; the first line contains a single integer denoting the length of the array that will hold the prefix expression. The second line of i nput is the prefix expression itself, with a blank separating each operand and operators. Note: as the input contains both text and numeric information, the array in your program should be declared as type char. -->

<!-- slide vertical = true-->
## 第二題 - 參考輸入

``` text
3 + 2 3
3 * 2 3
7 * + 1 2 + 3 4
```

## 第二題 - 參考輸出

``` text
ans: 5
ans: 6
ans: 21
```

<!-- slide vertical = true-->
## 第二題 - 參考程式碼

``` C
#include <stdio.h>

int prefix(char* str, int* start, int size) {
    char symbol = str[(*start)++];
    char num1 = (str[*start] == '+' || str[*start] == '*') ? prefix(str, start, size) : str[(*start)++];
    char num2 = (str[*start] == '+' || str[*start] == '*') ? prefix(str, start, size) : str[(*start)++];

    if (symbol == '+') return num1 + num2;
    if (symbol == '*') return num1 * num2;
    return 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        char* str = (char*)malloc((n + 1)  * sizeof(char));
        for (int i = 0; i < n; i++) {
            scanf("%s", &str[i]);
            if (str[i] != '+' && str[i] != '*') {
                str[i] -= '0';
            }
        }
        int start = 0;
        printf("ans: %d\n", prefix(str, &start, n));
    }
}

```

<!-- slide -->
## 第三題

<!-- Game description: This program deals with a game, the Stone Game, which proceeds as follows: initially, there are three piles of stones, each pile with an arbitrary number of stones greater than two. Two players take turn to remove either one or two stones from a pile. Whoever removes the last stone wins the game.

Program description:
The program randomly generate s the number of stones for each pile, and for the sake of finishing the game in a reasonable amount of time, each pile shall not contain more than 1 2 stones. The computer will play against a human opponent and will let the user decide who is to move first. Once the game starts, the computer will try its best to win the game; that is, when there is a winning move, the computer must make this move. D uring the course of the game, the program should somehow display a graphic representation of the piles of stones. The computer will prompt the user for input when it is the user's move, and it will display a message, such as "I am thinking", when it is lo oking for a best move. At the end of the game, the program must announce the winner. There is no possibililty of a draw for this game.

Program design:
A state of the game is characterized by the numbers of stones in the piles. A state is said to be a forced win state if one of its sub states leads to a loss. In other words, a player is in a forced win state if there exists a move he can make such that no matter what his opponent does afterwards, his opponent is bound to lose. A state is a forced loss state if all its sub states are forced win states. The computer should always make a move that produces a forced loss state for the human player. When there is no winning move, then the computer will choose the move that removes the least number of stones from the piles. The program terminates when the last stone is removed and the winner is declared. The following is an example of the game:
2 1 1 forced win
 -> 0 1 1 forced loss -> 0 0 1 forced win -> 0 0 0 game over
 -> 0 1 1 forced loss -> 0 1 0 f orced win -> 0 0 0 game over
Employ recursion to compute the win/loss status of a game state. -->

<!-- slide vertical = true-->
## 第三題 - 參考程式碼

``` C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw(int stone[3]) {
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (stone[i] > max) max = stone[i];
    }
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < 3; j++){
            if (i > stone[j])
                printf("   ");
            else printf(" O ");
        }
        printf("\n");
    }
    printf("---------\n");
}

int main() {
    srand(time(0));
    int player = 0;
    int finished = 0;
    int stone[3];
    for (int i = 0; i < 3; i++) {
        stone[i] = rand() % 11 + 2;
    }
    while (!finished) {
        player = player ? 0 : 1;
        int chooseIdx, chooseCount;
        draw(stone);
        if (player) {
            do {
                printf("please choose index: ");
                scanf("%d", &chooseIdx);
                printf("please choose stone count: ");
                scanf("%d", &chooseCount);
            } while(
                chooseIdx >= 3 || 
                chooseIdx < 0 || 
                chooseCount > stone[chooseIdx] || 
                chooseCount > 2 || 
                chooseCount <= 0
            );
        }
        else {
            int count[5] = {0};
            for (int i = 0; i < 3; i++) {
                if (stone[i] <= 3) count[stone[i]]++;
                else count[4]++;
            }
            if (!count[4] && (count[2] + count[3]) == 1 && (count[2] || count[0] == 1)) {
                for (int i = 1; i < 3; i++) {
                    if (stone[i] > 1) {
                        chooseIdx = i;
                        chooseCount = (stone[i] == 2 && count[0] == 1) ? 1 : 2;
                        break;
                    }
                }
            }
            else {
                chooseIdx = 0;
                for (int i = 1; i < 3; i++) {
                    if (!stone[chooseIdx] || (stone[i] && stone[i] < stone[chooseIdx])) 
                        chooseIdx = i;
                }
                chooseCount = stone[chooseIdx];
            }
            printf("compute choose index: %d\n", chooseIdx);
            printf("compute choose stone count: %d\n", chooseCount);
        }
        stone[chooseIdx] -= chooseCount;
        if (!stone[0] && !stone[1] && !stone[2]) finished = 1;
    }
    printf("%s win\n", player ? "player" : "computer");
}
```
