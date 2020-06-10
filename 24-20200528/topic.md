# School HW

## Fractions

You are given ten fractions on ten separate lines, each of which is composed of three integers that denote the integral part , the numerator, and the denominator of a fraction. Your task is to find the sum and the average of the fractions and present the results on two lines, one for the sum and the other for the average, in the same form as input. Note the results must be reduced to lowest terms. You shall need to define a struct type FRAC with three members for representing a fraction, fraction,. You shall also need to declare an array to store these fractions. In addition, define two functions for computing the sum and the average, and both functions shall return an answer of type FRAC.

@import "input1.txt"

@import "hw1.c" c {cmd="cmd",args=["/C","gcc","-std=c11","-x","c","$input_file","&","a.exe","<","input1.txt","&","del","a.exe"]}

## Student Records

Write a program to sort grades. Your program should read the contents of an input file of the following format:

``` text
N
ID NAME score one_score two_score three_score four_score
.
.
.
```

in which the first line contains an integer N indicating that there are N records, one record on a single line for each of the next N lines, and there are three types of information in each record, namely, student ID, student NAME, and four test scores, all separated by blanks. A student ID is composed of an English letter in lower case followed by 9 digits, and student NAME is a string that follows the "Last_Name, First_Name"
You can assume the names will not be more than 20 characters long. The four test scores are integers. Your program should first sort the input by ID, then by Last Name, by test score one, by test score two by test score three and finally by test score four, all into non decreasing order. Print all the records after each sort.
For this program, you are required to define a structure whose first field is another structure that contains an ID and a name and a second field is an array that stores the four test scores of a s tudent. You should also declare an array of size N th at holds all N records of the students.

### Sample input

@import "input2.txt"

@import "hw2.c" c {cmd="cmd",args=["/C","gcc","-std=c11","-x","c","$input_file","&","a.exe","<","input2.txt","&","del","a.exe"]}