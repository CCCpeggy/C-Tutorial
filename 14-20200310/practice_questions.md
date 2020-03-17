<!-- slide -->
# 練習題
<!-- slide -->
## 學校作業

<!-- slide -->
### 學校作業 - 題目1

<!-- 
M A S T E R   M I N 

Game Description:  Master Mind is a game of logic for two players.  One player combines game pieces of various colors into a sequence, whereas the other tries to crack the color combination using the clues given by the first player.  Our version of the game consists of games pieces of five colors: red (R), green (G), blue (B), yellow (Y), and orange (O).  Player A designs a color sequence in any fashion, such as

B B Y O B   or   Y R B G O   or   O Y B Y R

It is the task of player B to correctly deduce the color sequence posed by player A.  For each attempt made by player B, player A must inform player B of the number of game pieces which are correct in both positions and colors and the number of game pieces which are correct only in colors.  These two pieces of information are encoded by means of black and white pins, respectively.  The following two examples will illustrate the rule:

        Example One        player A    B B Y O B
                        player B    O B B R G    Black pins: 1  White pins: 2

        Example Two        player A      Y R B G G
                        player B     G G O O O     Black pins: 0  White pins: 2

The game is terminated when player A's color sequence is matched by player B's response.

Program Requirements:  Your program should let the user choose between the roles of player A and player B, and then the computer takes on the role of the other.  All input is entered interactively through the keyboard, and the program should check the validity of the input.  If input is found invalid, the user should be given another chance to re-enter input.  Output is displayed on computer screen.  

We will store all the possible color combinations in a two-dimensional array, and the adjacency of the sequences is stored in another one-dimensional array.  As our version of the game has five colors, there are 3125 possible color sequences.  You shall declare a two-dimensional character array colors of size [3125, 5] to hold the color sequences and another one-dimensional integer array next of size [3125] to hold the indices.   To facilitate initializing array colors, you shall need one more one-dimensional character array avail of size [5].

        char colors [3125, 5], avail [5] = {'R', 'G', 'B', 'Y', 'O'};
         int next [3125], index = 0, head = 0;

         for (I = 0; I < 5; I++)
          for (J = 0; J < 5; J++)
           for (K = 0; K < 5; K++)
            for (M = 0; M < 5; M++)
             for (N = 0; N < 5; N++)
              {  colors [index, 0] = avail [I];  colors [index, 1] = avail [J];  
                 colors [index, 2] = avail [K];  colors [index, 3] = avail [M];
                 colors [index, 4] = avail [N];  next [index] = ++index;    }
        next [3124] = 0;

The last color sequence has index 0, signifying that it is the end of the linked list. 
 
The program proceeds in one of two modes:
The user as player A and the computer as player B:  The computer randomly chooses from colors a sequence as the solution to the riddle posed by the user, and the user as player A will respond by indicating the numbers of black and white pins.  Note that it is vitally important that the number of black pins be determined before the number of white pins and that a game piece in the solution is used exactly once for comparison.  Knowing the numbers of black and white pins, the computer then inspects the color list and updates the list by deleting the sequences which do not give the same numbers of black and white pins when compared with the attempted solution.  This involves updating the adjacency information held in array next and possibly the value of variable head.  The computer again randomly chooses a color sequence from the remaining list as the next solution, which is again checked for the numbers of black and white pins.  The process keeps repeating till the correct sequence is produced.

The user as player B and the computer as player A:  The computer randomly chooses a color sequence and prompts the user for a guess, which the computer will check for the numbers of black and white pins.  Again, determine the number of black pins before that of white pins.  The process terminates when the user arrives at the right color combination.    

-->

<!-- slide vertical = true-->

#### 學校作業 - 題目1 - 參考程式碼

``` C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

const char avail[5] = {'R', 'G', 'B', 'Y', 'O'};

int valid(char color[6]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (color[i] == avail[j]) break;
            if (j == 4) return 0;
        }
    }
    return !color[5];
}

int compute(char *ans, char *guess, int *black, int *white) {
    int checkedAns[5] = {0};
    int checkedGuess[5] = {0};
    *black = *white = 0;
    for(int i = 0; i < 5; i++) {
        if (guess[i] == ans[i]) {
            *black +=1;
            checkedAns[i] = checkedGuess[i] = 1;
        }
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5 && !checkedGuess[i]; j++) {
            if (guess[i] == ans[j] && !checkedAns[j]) {
                *white += 1;
                checkedGuess[i] = checkedAns[j] = 1;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    char colors[3125][5];
    int next[3125], index = 0, head = 0;

    for (int I = 0; I < 5; I++)
        for (int J = 0; J < 5; J++)
            for (int K = 0; K < 5; K++)
                for (int M = 0; M < 5; M++)
                    for (int N = 0; N < 5; N++)
                    {  
                        colors[index][0] = avail[I];  
                        colors[index][1] = avail[J];  
                        colors[index][2] = avail[K];  
                        colors[index][3] = avail[M];
                        colors[index][4] = avail[N];  
                        index++;
                    }
    char player;
    printf("player(A/B): ");
    while (scanf("%s", &player) != EOF) {
        head = 0;
        // 初始化next
        for (int i = 0; i < 3125; i++) {
            next[i] = i + 1;
        }
        next[3124] = 0;

        if (player == 'A') {
            char *guess, ans[6];
            int black = 0, white = 0, count = 3125;
            //使用者輸入ans
            do {
                printf("ans: ");
                scanf("%s", ans);
            } while(!valid(ans));
            do {
                //獲取電腦亂數猜的結果
                int rnd = rand() % count;
                //取得第rnd個number(因為當中的資料有可能被刪除，所以需要從頭開始找)
                int *num = &head;
                while (rnd--) num = next + *num;
                //將guess指到前面找到的位置
                guess = colors[*num];
                //計算ans跟guess的black跟white
                compute(ans, guess, &black, &white);
                //輸出black跟white數量
                printf("black: %d, white: %d\n", black, white);
                //因為答案與這次所猜的顏色所算出來的black跟white必相符
                //所以不相符的結果就可以刪除了

                //將現在所有還有可能性的顏色組合跑過一遍
                for(num = &head; next[*num] > head;) {
                    int b, w; //儲存black跟white
                    //計算目前的與guess的black跟white
                    compute(guess, colors[*num], &b, &w);
                    //如果其中一個black跟white跟原先的black跟white不符和就刪除
                    if (w != white || b != black) {
                        *num = next[*num];
                        count--;
                    }
                    else {
                        num = &next[next[*num]];
                    }
                }
            //直到找到black為5的解答才結束
            } while(black != 5);
        }
        else if (player == 'B') {
            char *ans, guess[6];
            ans = colors[rand() % 3125];
            // printf("ans: %c%c%c%c%c\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
            int black = 0, white = 0;
            do {
                printf("guess: ");
                scanf("%s", guess);
                if (valid(guess)){
                    compute(ans, guess, &black, &white);
                    printf("black: %d, white: %d\n", black, white);
                }
            } while(black != 5);
        }
        printf("player: ");
    }
}
```

<!-- slide -->
### 學校作業 - 題目2

<!--
用亂數產生器用出100個隨機的大寫英文字母 然後把裡面有回文的都印出來
-->

<!-- slide vertical = true-->

#### 學校作業 - 題目2 - 參考程式碼

``` C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void valid_o(char* topic, int index) {
    int length = 1;
    while (index - length >= 0 && length + index < MAX && topic[index - length] == topic[index + length]) {
        length++;
    }
    length--;
    if (length > 1) {
        for (int i = index - length; i <= index + length; i++) {
            printf("%c", topic[i]);
        }
        printf("\n");
    }
}

void valid_e(char* topic, int index) {
    int length = 0;
    while (index - length > 0 && length + index < MAX && topic[index - length - 1] == topic[index + length]) {
        length++;
    }
    length--;
    if (length >= 0) {
        for (int i = index - length - 1; i <= index + length; i++) {
            printf("%c", topic[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    char topic[MAX + 1] = {0};
    for (int i = 0; i < MAX; i++) {
        topic[i] = rand() % 26 + 'A';
    }
    printf("topic: %s\n", topic);
    for(int i = 0; i < MAX; i++) {
        valid_o(topic, i);
        valid_e(topic, i);
    }
}
```

<!-- slide -->
## 額外練習題

<!-- slide vertical = true-->
### 額外練習題 - 題目1

<!-- slide vertical = true-->
小明很喜歡玩走迷宮，其實根據他的經驗，他認為解迷宮最快的方式是「有路就走」，而不是「找到最短路徑」才走。

<!-- slide vertical = true-->
所以他走迷宮的時候，每一步只要能往上走就走，直到不能走在往左，不行再右，最後才下。當發現都沒有路走的時候，就會回到前一個還有沒走過的路口，依循前面的條件，往下一段路前進。持續以上的步驟，直到找到路徑。

<!-- slide vertical = true-->
題目會給你一個迷宮，請輸出小明走的路徑的反向順序

<!-- slide vertical = true-->
#### 額外練習題 - 題目1 - 範例輸入

``` text
1 1 0 0 0 0 0 0 0 0
0 1 1 0 0 1 0 0 0 0
1 1 0 0 0 1 0 0 0 0
0 1 0 1 0 1 0 0 0 0
0 1 0 1 0 1 0 0 0 0
0 1 1 1 1 1 1 0 1 0
0 0 0 0 1 0 0 0 1 0
0 0 0 1 1 1 1 1 1 0
0 0 0 0 1 0 0 0 1 0
0 0 0 0 0 0 0 0 1 1
```

<!-- slide vertical = true-->
#### 額外練習題 - 題目1 - 範例輸出

``` text
(9, 9)
(8, 9)
(8, 8)
(8, 7)
(7, 7)
(6, 7)
(5, 7)
(4, 7)
(4, 6)
(4, 5)
(3, 5)
(2, 5)
(1, 5)
(1, 4)
(1, 3)
(1, 2)
(1, 1)
(1, 0)
(0, 0)
```

<!-- slide vertical = true-->
#### 額外練習題 - 題目1 - 程式碼參考

``` C
#include <stdio.h>

int goMaze(int maze[10][10], int x, int y) {
    int newMaze[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            newMaze[i][j] = maze[i][j];
        }
    }
    newMaze[y][x] = 0;
    int found = 0;
    if (x == 9 && y == 9) found = 1;
    if (!found && y > 0 && newMaze[y - 1][x]) found = goMaze(newMaze, x, y - 1);
    if (!found && x > 0 && newMaze[y][x - 1]) found = goMaze(newMaze, x - 1, y);
    if (!found && x < 9 && newMaze[y][x + 1]) found = goMaze(newMaze, x + 1, y);
    if (!found && y < 9 && newMaze[y + 1][x]) found = goMaze(newMaze, x, y + 1);
    if (found) printf("(%d, %d)\n", x, y);
    return found;
}

int main() {
    int maze[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    goMaze(maze, 0, 0);
}
```