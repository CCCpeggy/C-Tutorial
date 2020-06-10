# 題目

## 學校作業

### Division of Polynomials

A polynomial of a single variable may be represented by two sequences, one ontaining the degrees in descending order of every term in the polynomial (zero-coefficient erms are not included) and the other containing the corresponding coefficients. For example, the polynomial $6x^3 + 5x^2 - 7$ is represented as $\{3, 2, 0\}$ and $\{6, 5, -7\}$.

Given two polynomials, print the resultant quotient and remainder polynomials after division of the two polynomials. The divisor is a monic polynomial, meaning the leading coefficient (the nonzero coefficient of the highest degree) is equal to $1$.

#### Input

The input begins with a single integer $T$ ($1 ≤ T ≤ 100$) on a line by itself indicating the number of test cases which follow below. There are four lines for each test case. The first line contains the degrees of the terms of the polynomial in descending order and the highest degree will not exceed 100. The second line contains each term’s coefficient ($-100 ≤ c ≤ 100$), and the last two lines form the divisor polynomial. All these numbers are integers.

#### Output

For each test case, print the paired sequences in separate lines (degrees first, then coefficients) that represent the resultant quotient polynomial. Then similarly print the paired sequences that represent the resultant remainder polynomial. Note that either the quotient or the remainder may be the 0 polynomial, represented as 0 and 0.

#### Sample Input

@import "01-1.in"

#### Sample Output

@import "01.c" c {cmd="cmd",args=["/C","gcc","-std=c11","-x","c","$input_file","&","a.exe","<","01-1.in","&","del","a.exe"] hide=true}

#### Code

@import "01.c" c {cmd="cmd",args=["/C","gcc","-std=c11","-x","c","$input_file","&","a.exe","<","01-1.in","&","del","a.exe"]}

(2) Do exercises 1 through 5 on pp.453-454 in the textbook.
