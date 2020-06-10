# 學校作業題目練習

## 排序

Create three integer arrays of size 3000, and fill these arrays with the same random numbers. The code may look something like this: srand(time(NULL)); for(int i=0; i<3000; i++) a[i] = b[i] = c[i] = rand()%10000; Sort arrays a, b, and c by quicksort, mergersort, and bubblesort, respectively. Before each sorting method begins, record the current time by the time function; after each sorting is terminated, again record the current time. The difference between these two times is how long it takes to execute a sorting method on an array. Repeat the above process 10 times and compute the total execution time for each of the three sorting methods. Output the results.

## 括號

Write a recursive program to determine whether a given series of parentheses pair up correctly. Parentheses pair up correctly if for each starting left parenthesis, there is exactly one terminating right parenthesis, much like what you are used to seeing in math calculations. For this problem, you can assume the user will input no more than 50 parentheses, and you are also allowed to use global variables. must decide if they pair up correctly by a recursive function.

## 變化盒內塔

You are given a pile of discs which alternate in color and are arranged from the largest disc at the bottom to the smallest at the top, as shown in Figure 1 below. You are required to recursively move the discs from the first peg to the second peg and use the third peg as an auxiliary peg. During the course of moving the discs, you cannot place a larger disc above a small disc and you cannot place blue disc above a green disc.

## 反矩陣 and 矩陣相乘

Write a program to compute the inverse of a square matrix. Once you have computed the inverse, multiply it by the original matrix to produce the identity matrix. Ask the user for the size of the matrix and then fill the matrix with random numbers. Output must consist of the original matrix and its inverse, and the product of these two matrices, which must be the identity matrix of the same size.

## 開根號

Compute the square root of 2 to 100 decimal places with the aid of arrays. You must use pointer when operating on the arrays.