<!-- slide -->
# function pointer

<!-- slide vertical = true-->
儲存某一個函式起始memory address的變數

<!-- slide vertical = true-->
存在一個函式

``` C
int Square(int n)
{
    return n * n;
}
```

<!-- slide vertical = true-->
則可以宣告一個function pointer 指向他

``` C
int (*fptr)(int);
fptr = Square;
```

<!-- slide -->
## 表示方式

<!-- slide vertical = true-->
必須和函式的傳入、回傳的所有定義相同

<!-- slide vertical = true-->
``` C
int (*fptr)(int);
```

* 第一個是回傳的型態
* 第二個是function pointer的名稱，用```(* )```包住
* 最後用```( )```標示傳入的參數，多個參數用```,```隔開

<!-- slide -->
## 題目1

實作一個函式，傳入兩個要計算的整數，和一個function pointer，回傳function pointer的計算結果

<!-- slide vertical = true-->
### 題目1 - 輸出

``` text
False
True
True
```

<!-- slide vertical = true-->
### 題目1 - 框架

``` C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define logic(X) ((X)?1:0)

int andGate(int input1, int input2){
  return logic(input1 & input2);
}

int orGate(int input1, int input2){
  return logic(input1 | input2);
}

int xorGate(int input1, int input2){
  return logic(input1 ^ input2);
}

int main(){
  printf("%s\n", gate(1, 0, andGate) ? "True" : "False");
  printf("%s\n", gate(1, 0, orGate) ? "True" : "False");
  printf("%s\n", gate(1, 0, xorGate) ? "True" : "False");
}
```

<!-- slide vertical = true-->
### 題目1 - 程式碼

``` C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define logic(X) ((X)?1:0)

int andGate(int input1, int input2){
  return logic(input1 & input2);
}

int orGate(int input1, int input2){
  return logic(input1 | input2);
}

int xorGate(int input1, int input2){
  return logic(input1 ^ input2);
}

int gate(int input1, int input2, int (*thisGate)(int, int)){
  return thisGate(input1, input2);
}

int main(){
  printf("%s\n", gate(1, 0, andGate) ? "True" : "False");
  printf("%s\n", gate(1, 0, orGate) ? "True" : "False");
  printf("%s\n", gate(1, 0, xorGate) ? "True" : "False");
}
```
