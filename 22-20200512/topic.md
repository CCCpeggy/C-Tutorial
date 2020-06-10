# 20200512

## 第一題

You are given a map of a treasure site represented by an N by M two dimensional array. On the map, you see that the treasures are scattered about in some of the cells of the array. The entrance to the treasure site is at [0][0] on the map, and the exit is at [N 1][M 1]. You want to plan a route so that you can gather treasures with the most value in total. There is a catch: you can only move either right or down on the map.
Write a recursive program to help you find the most profitable way through the t reasure site. Use only
pointers in your program. 

Input: N M on the first line. Then on each of the subsequent N lines, there are M integers indicating the
values of the treasures. 

Output: the most value of the treasures you can gather and the route through the treasure site. The route consists of the coordinates of the cells in the two dimensional array and must begin at [0][0] and terminate at [N-1][M-1].

## 第二題

You have just inherited a piece of land from a dead relative represented by an N by M two dimensional array, and you want to build the bigg est square house possible on the land. Unfortunately, there are trees on the land and it is specif ically stipulated in your relative ’s will that the trees are not to be chopped down and removed. Write a recursive program to help determine how big a square house you can build. Use only pointers in your program.

Input: N M on the first line. Then on each of the subsequent N lines, there are M 0’s and 1’s, 0’s indicating no trees and 1’s indicating trees.

Output: the area of the largest square piece of land c lear of trees.

## 第三題

We begin by defining three operations on a string S:

* (a) Insert : inserting a character into S
* (b) Remove: removing a character from S
* (c) Replace : replacing a character in S by another character

Now you are given two strings strA and strB and you want to transform strA into strB. Write a recursive program that employs the operations defined above to help you determine the lea st number of operations on strA to make it look exactly like strB Use only pointers in your program.

Input: There is just one single line of input that contains string s strA and strB separated by white space. You can assume that strA is not p receded by any white space and the le ngths of strA and strB will not exceed 20.

Output: an integer indicating the minimum number of operations n eeded to transform strA.