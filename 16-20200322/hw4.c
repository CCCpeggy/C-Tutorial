#include <stdio.h>

int playGame(char board[3][3], char player) {
    char newBoard[3][3]={0};
    int count = 0;
    for (int i = 0; i< 3; i++) {
        for (int j = 0; j < 3; j++) {
            newBoard[i][j] = board[i][j];
            if (board[i][j]=='X'||board[i][j]=='O') count++;
        }
    }
    if(!count) return 1;
    int able = 0;
    for (int i = 0; !able && i< 3; i++) {
        for (int j = 0; !able && j < 3; j++) {
            if (newBoard[i][j] == player) {
                newBoard[i][j] = ' ';
                able = playGame(newBoard, player=='X'?'O':'X');
                newBoard[i][j] = board[i][j];
            }
        }
    }
    return able;
}

int main() {
    char board[3][3] = {0};
    for (int i = 0; i< 3; i++) {
        char tmp[4];
        gets(tmp);
        for (int j = 0; j < 3; j++) {
            if (tmp[j]=='X'||tmp[j]=='O'||tmp[j]==' ') board[i][j] = tmp[j];
            else break;
        }
    }
    if (playGame(board, 'X') || playGame(board, 'O'))
        printf("Yes\n");
    else
        printf("No\n");
}