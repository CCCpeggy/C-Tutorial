# 學校作業

## 題目1

<!-- Create three integer arrays of size 3000, and fill these arrays with the same random numbers. The code may look something like this: srand(time(NULL)); for(int i=0; i<3000; i++) a[i] = b[i] = c[i] = rand()%10000; Sort arrays a, b, and c by quicksort, mergersort, and bubblesort, respectively. Before each sorting method begins, record the current time by the time function; after each sorting is terminated, again record the current time. The difference between these two times is how long it takes to execute a sorting method on an array. Repeat the above process 10 times and compute the total execution time for each of the three sorting methods. Output the results.  -->

## 題目2

<!-- Write a recursive program to determine whether a given series of parentheses pair up correctly. Parentheses pair up correctly if for each starting left parenthesis, there is exactly one terminating right parenthesis, much like what you are used to seeing in math calculations. For this problem, you can assume the user will input no more than 50 parentheses, and you are also allowed to use global variables. must decide if they pair up correctly by a recursive function. -->

## 題目3

<!-- You are given a pile of discs which alternate in color and are arranged from the largest disc at the bottom to the smallest at the top, as shown in Figure 1 below. You are required to recursively move the discs from the first peg to the second peg and use the third peg as an auxiliary peg. During the course of moving the discs, you cannot place a larger disc above a small disc and you cannot place blue disc above a green disc.
Figure 1 -->

## 題目3 - 範例輸入

``` text
3
```

``` text
move size green-1 from 1 to 3
move size blue-1 from 1 to 2
move size green-1 from 3 to 2
move size green-2 from 1 to 3
move size green-1 from 2 to 1
move size blue-1 from 2 to 3
move size green-1 from 1 to 3
move size blue-2 from 1 to 2
move size green-1 from 3 to 2
move size blue-1 from 3 to 1
move size green-1 from 2 to 1
move size green-2 from 3 to 2
move size green-1 from 1 to 3
move size blue-1 from 1 to 2
move size green-1 from 3 to 2
move size green-3 from 1 to 3
move size green-1 from 2 to 1
move size blue-1 from 2 to 3
move size green-1 from 1 to 3
move size green-2 from 2 to 1
move size green-1 from 3 to 2
move size blue-1 from 3 to 1
move size green-1 from 2 to 1
move size blue-2 from 2 to 3
move size green-1 from 1 to 3
move size blue-1 from 1 to 2
move size green-1 from 3 to 2
move size green-2 from 1 to 3
move size green-1 from 2 to 1
move size blue-1 from 2 to 3
move size green-1 from 1 to 3
move size blue-3 from 1 to 2
move size green-1 from 3 to 2
move size blue-1 from 3 to 1
move size green-1 from 2 to 1
move size green-2 from 3 to 2
move size green-1 from 1 to 3
move size blue-1 from 1 to 2
move size green-1 from 3 to 2
move size blue-2 from 3 to 1
move size green-1 from 2 to 1
move size blue-1 from 2 to 3
move size green-1 from 1 to 3
move size green-2 from 2 to 1
move size green-1 from 3 to 2
move size blue-1 from 3 to 1
move size green-1 from 2 to 1
move size green-3 from 3 to 2
move size green-1 from 1 to 3
move size green-2 from 1 to 3
move size green-1 from 2 to 1
move size blue-1 from 2 to 3
move size green-1 from 1 to 3
move size blue-2 from 1 to 2
move size green-1 from 3 to 2
move size blue-1 from 3 to 1
move size green-1 from 2 to 1
move size green-2 from 3 to 2
move size green-1 from 1 to 3
move size blue-1 from 1 to 2
move size green-1 from 3 to 2
```

## 題目4

<!-- Tic-Tac-Toe is a game for two in which each player takes turn to place 'X' or 'O' into an empty square in a 3 by 3 game board. The first player starts the game and always places 'X' during the course of a game, whereas the second player always places 'O'. Given a game board represented by a 3 by 3 two-dimensional array with some X's, O's, and empty cells, you are to determine recursively if the given game position is reachable from the start of a game. If it is reachable, output "Yes"; otherwise, output "No". Note: Ignore winning states; treat them as if they were ordinary game configurations. -->

## 題目4 - 範例輸入1

``` text 
X O
XXO
 O 
```

``` text
Yes
```
## 題目4 - 範例輸入

``` text 
X O
  O
 O 
```

``` text
No
```