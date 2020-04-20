# 20200414

## 第一題

Write a program to compute the inverse of a square matrix. Once you have computed the inverse, multiply it by the original matrix to produce the identity matrix. Ask the user for the size of the matrix and then fill the matrix with random numbers. Output must consist of the original matrix and its inverse, and the product of these two matrices, which must be the identity matrix of the same size.

## 第二題

The following formula calculates the number of possible combinations, K, of N objects. For example, for 49 numbers, there are C(49, 6), or 13983816, different combinations of six numbers. Write a non-recursive program in which you ask the user for the values of N and K and then compute the result.
$C(N, K) = \begin{cases}
1\ \ \text{ if }N = K\text{ or }K = 0\\
C(N − 1, K) + C(N − 1, K − 1)\ \ \text{ if }N > K > 0\end{cases}$

## 第三題

You are required to write a program that determines which three numbers out of 20 numbers given by the user whose sum is closest to a goal which is also given by the user. If the solution is not unique, output just one of them. Again, use only pointers on the array that stores the 20 numbers.

## 第四題

Compute the square root of 2 to 100 decimal places with the aid of arrays. You must use pointer when operating on the arrays.