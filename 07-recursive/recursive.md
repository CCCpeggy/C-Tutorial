<!-- slide -->
# 遞迴

<!-- slide -->
## 目的

簡化程式，大問題切成小問題解決

<!-- slide -->
## 思考

* 解決當下的問題
* 停止的時機

$a_n = a_{n-1} + 1$
$a_1 = 1$

<!-- slide -->
## 舉例 - 費氏數列

$f_n = f_{n-1} + f_{n-2}$

``` C
int f(int n){
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 2);
}
```

<!-- slide -->
``` C
f(4);
```

``` dot
digraph f{
    a [label="f(4)", fillcolor=yellow, style=filled];
}
```

<!-- slide -->
``` C
//n = 4
return f(n - 1) + f(n - 2); // f(3) + f(2);
```

``` dot
digraph f{
    a [label="f(4)", fillcolor=yellow, style=filled];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    a->{b1 b2};
}
```

<!-- slide -->
``` C
//n = 3
return f(n - 1) + f(n - 2); // f(2) + f(1);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)", fillcolor=yellow, style=filled];
    b2 [label="f(2)"];
    c1 [label="f(2)"];
    c2 [label="f(1)"];
    a->{b1 b2};
    b1->{c1 c2};
}
```

<!-- slide -->
``` C
//n = 2
return f(n - 1) + f(n - 2); // f(1) + f(0);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)", fillcolor=yellow, style=filled];
    c2 [label="f(1)"];
    d1 [label="f(1)"];
    d2 [label="f(0)"];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 1
return 1;
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)"];
    c2 [label="f(1)"];
    d1 [label="1", fillcolor=yellow, style=filled];
    d2 [label="f(0)"];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
return f(n - 1) + f(n - 2); // 1 + f(0);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)", fillcolor=yellow, style=filled];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="f(0)"];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 1
return 1;
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)"];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="1", fillcolor=yellow, style=filled];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
return f(n - 1) + f(n - 2); // 1 + 1;
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="2", fillcolor=yellow, style=filled];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 3
return f(n - 1) + f(n - 2); // 2 + f(1);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)", fillcolor=yellow, style=filled];
    b2 [label="f(2)"];
    c1 [label="2"];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 1
int f(int n){
    return 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", fillcolor=yellow, style=filled];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 3
int f(int n){
    return f(n - 1) + f(n - 2); // 2 + 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", fillcolor=yellow, style=filled];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 4
int f(int n){
    return f(n - 1) + f(n - 2); // 3 + f(2);
}
```

``` dot
digraph f{
    a [label="f(4)", fillcolor=yellow, style=filled];
    b1 [label="3", style=dashed];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return f(n - 1) + f(n - 2); // f(1) + f(0);
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)", fillcolor=yellow, style=filled];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", fillcolor=yellow, style=filled];
    c4 [label="f(0)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return f(n - 1) + f(n - 2); // 1 + f(0);
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)", fillcolor=yellow, style=filled];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="f(0)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 0
int f(int n){
    return 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="1", fillcolor=yellow, style=filled];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return f(n - 1) + f(n - 2); // 1 + 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="2", fillcolor=yellow, style=filled];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 4
int f(int n){
    return f(n - 1) + f(n - 2); // 3 + 2;
}
```

``` dot
digraph f{
    a  [label="5", fillcolor=yellow, style=filled];
    b1 [label="3", style=dashed];
    b2 [label="2", style=dashed];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
## 遞迴的缺點

<!-- slide -->
### 跑跑看以下程式

``` C
int f(int n){
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 2);
}
int main(){
    printf("f(42) = %d", f(42));
}
```

<!-- slide -->
### f(4)的圖

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)"];
    c2 [label="f(1)"];
    c3 [label="f(1)"];
    c4 [label="f(0)"];
    d1 [label="f(1)"];
    d2 [label="f(0)"];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```
<!-- slide -->
### f(5)的圖

``` dot
digraph f{
    a [label="f(5)"];
    b1 [label="f(4)"];
    b2 [label="f(3)"];
    c1 [label="f(3)"];
    c2 [label="f(2)"];
    c3 [label="f(2)"];
    c4 [label="f(1)"];
    d1 [label="f(2)"];
    d2 [label="f(1)"];
    d3 [label="f(1)"];
    d4 [label="f(0)"];
    d5 [label="f(1)"];
    d6 [label="f(0)"];
    e1 [label="f(1)"];
    e2 [label="f(0)"];
    a ->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
    c2->{d3 d4};
    c3->{d5 d6};
    d1->{e1 e2};
}
```

<!-- slide -->
### 缺點

* 效率差
* 佔記憶體

<!-- slide -->
## 題目1

<!-- slide -->
$f(n) = \displaystyle\sum_{i=1}^n (5i + 3)$

$f(n) = \displaystyle\sum_{i=1}^n 5i + 3 = (\displaystyle\sum_{i=1}^{n - 1} (5i + 3)) + 5n + 3$

請寫一個function，傳入n後，回傳結果

<!-- slide -->
### 題目1 - 輸入

無

### 題目1 - 輸出

``` text
> f(5) = 90
> f(10) = 305
```

<!-- slide -->
### 題目1 - 框架

``` C
#include<stdio.h>

int f(int n){
}

int main(){
  printf("f(5) = %d\n", f(5));
  printf("f(10) = %d\n", f(10));
}
```

<!-- slide -->
### 題目1 - 圖解

``` dot
digraph f{
    "f(5)";
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    a4 [label = "5 * 4 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
    "f(4)" -> {"f(3)", a4};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    a4 [label = "5 * 4 + 3", shape = box];
    a3 [label = "5 * 3 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
    "f(4)" -> {"f(3)", a4};
    "f(3)" -> {"f(2)", a3};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    a4 [label = "5 * 4 + 3", shape = box];
    a3 [label = "5 * 3 + 3", shape = box];
    a2 [label = "5 * 2 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
    "f(4)" -> {"f(3)", a4};
    "f(3)" -> {"f(2)", a3};
    "f(2)" -> {"f(1)", a2};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    a4 [label = "5 * 4 + 3", shape = box];
    a3 [label = "5 * 3 + 3", shape = box];
    a2 [label = "5 * 2 + 3", shape = box];
    a1 [label = "5 * 1 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
    "f(4)" -> {"f(3)", a4};
    "f(3)" -> {"f(2)", a3};
    "f(2)" -> {"f(1)", a2};
    "f(1)" -> {a1};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    a4 [label = "5 * 4 + 3", shape = box];
    a3 [label = "5 * 3 + 3", shape = box];
    a2 [label = "5 * 2 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
    "f(4)" -> {"f(3)", a4};
    "f(3)" -> {"f(2)", a3};
    "f(2)" -> {"8", a2};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    a4 [label = "5 * 4 + 3", shape = box];
    a3 [label = "5 * 3 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
    "f(4)" -> {"f(3)", a4};
    "f(3)" -> {"21", a3};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    a4 [label = "5 * 4 + 3", shape = box];
    "f(5)" -> {"f(4)", a5};
    "f(4)" -> {"39", a4};
}
```

<!-- slide -->
``` dot
digraph f{
    a5 [label = "5 * 5 + 3", shape = box];
    "f(5)" -> {"62", a5};
}
```

<!-- slide -->
``` dot
digraph f{
    "90"
}
```

<!-- slide -->
### 題目1 - 程式碼

``` C
#include<stdio.h>

int f(int n){
  int value = 5 * n + 3;
  if(n > 1) value += f(n - 1);
  return value;
}

int main(){
  printf("f(5) = %d\n", f(5));
  printf("f(10) = %d\n", f(10));
}
```

<!-- slide -->
## 題目2

<!-- slide -->
$a_1 = 1$
$a_2 = 2$
$a_n = a_{n-1} * a_{n-2} + 1$
$9 \ge n \ge 1$

請寫一個function，傳入$n$後，回傳$a_n$的值

<!-- slide -->
### 題目2 - 輸入

無

### 題目2 - 輸出

``` text
a(1) = 1
a(2) = 2
a(3) = 3
a(4) = 7
a(5) = 22
```

<!-- slide -->
### 題目2 - 框架

``` C
#include<stdio.h>

int a(int n){
}

int main(){
  for(int i = 1; i <= 5; i++){
    printf("a(%d) = %d\n", i, a(i));
  }
}
```

<!-- slide -->
### 題目2 - 程式碼

``` C
#include<stdio.h>

int a(int n){
  if(n <= 2) return n;
  return a(n - 1) * a(n - 2) + 1;
}

int main(){
  for(int i = 1; i <= 5; i++){
    printf("a(%d) = %d\n", i, a(i));
  }
}
```

<!-- slide -->
## 題目3

找出陣列中最大的矩形

<!-- slide -->
### 題目3 - 輸入

無

### 題目3 - 輸出

``` test
> 12
```

<!-- slide -->
### 題目3 - 思考

1. right、left、up、down的range合不合理
   1. left < right
   2. up < down
2. right left up down圍出來的是否為矩形
3. 切小塊的矩陣找
   1. 上下左右的找

<!-- slide -->
### 題目3 - 框架

``` C
#include<stdio.h>

int findMaxRectangle(int matrix[][5], int left, int right, int up, int down){
}

int main(){
  int matrix[][5]={
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0}
  };
  int maxRectangle = findMaxRectangle(matrix, 0, 4, 0, 4);
  printf("%d\n", maxRectangle);
}
```

<!-- slide -->
### 題目3 - 圖解整體概念

初始

```ditaa {cmd=true args=["-E"]}
        left                   right
         |                       |
         v                       v
      +-----+-----+-----+-----+-----+
up  ->|  0  |  0  |  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      |  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      |  0  |  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      |  0  |  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->|  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
             left              right
               |                 |
               v                 v
      +-----+-----+-----+-----+-----+
up  ->:  0  |  0  |  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                   left        right
                     |           |
                     v           v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  |  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           +---+ |
                               | |
                               v v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  :  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  :  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                          |       |
                          | +-----+
                          | |
                          v v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  :
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  :
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  :
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  :
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  :
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  :
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  :
      +-----+-----+-----+-----+-----+
up-+  :  0  :  1  :  0  :  1  :  0  |
   |  +-----+-----+-----+-----+-----+
   +->:  0  :  1  :  1  |  1  |  0  |
down->+-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  :
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                            left  right
                              |     |
                              v     v
         +-----+-----+-----+-----+-----+
         :  0  :  0  :  0  :  0  :  0  |
         +-----+-----+-----+-----+-----+
         :  0  :  1  :  1  :  1  :  0  |
         +-----+-----+-----+-----+-----+
         :  0  :  1  :  0  :  1  :  0  :
up  ---> +-----+-----+-----+-----+-----+
     +-> :  0  :  1  :  0  |  1  |  0  |
     |   +-----+-----+-----+-----+-----+
down-+   :  0  :  1  :  1  :  1  :  0  |
         +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  :
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```
<!-- slide -->
以下重疊判斷部分省略

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slid

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```e -->
<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
up  ->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slid

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  :  0  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```-->
<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  :  1  :  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slid

```ditaa {cmd=true args=["-E"]}
                         left  right
                           |     |
                           v     v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  :  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  :  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  :  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```e -->

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
                   left        right
                     |           |
                     v           v
      +-----+-----+-----+-----+-----+
up  ->:  0  :  0  |  0  |  0  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  0  |  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  :  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->
省略中間一段

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
             left        right
               |           |
               v           v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  :
      +-----+-----+-----+-----+-----+
up  ->:  0  |  1  |  1  |  1  |  0  :
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  |  1  |  0  :
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  |  1  |  0  :
      +-----+-----+-----+-----+-----+
down->:  0  |  1  |  1  |  1  |  0  :
      +-----+-----+-----+-----+-----+
```

<!-- slide -->
### 題目3 - 圖解判斷是否維矩形

```ditaa {cmd=true args=["-E"]}
             left              right
               |                 |
               v                 v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  :
      +-----+-----+-----+-----+-----+
up  ->:  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  :  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  :  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->
``` C
for(int i = right; rectangle && i <= left; i++) {
    if(!matrix[up][i]) rectangle = false;
    if(!matrix[down][i]) rectangle = false;
}
```

```ditaa {cmd=true args=["-E"]}
             left              right
               |                 |
               v                 v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  :
      +-----+-----+-----+-----+-----+
up  ->:  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  0  :  1  :  0  |
      +-----+-----+-----+-----+-----+
      :  0  :  1  |  0  :  1  :  0  |
      +-----+-----+-----+-----+-----+
down->:  0  |  1  |  1  |  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->
``` C
for(int i = up; rectangle && i <= down; i++) {
    if(!matrix[i][left]) rectangle = false;
    if(!matrix[i][right]) rectangle = false;
}
```

```ditaa {cmd=true args=["-E"]}
             left              right
               |                 |
               v                 v
      +-----+-----+-----+-----+-----+
      :  0  :  0  :  0  :  0  :  0  :
      +-----+-----+-----+-----+-----+
up  ->:  0  |  1  |  1  :  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  :  1  |  0  |
      +-----+-----+-----+-----+-----+
      :  0  |  1  |  0  :  1  |  0  |
      +-----+-----+-----+-----+-----+
down->:  0  |  1  |  1  :  1  |  0  |
      +-----+-----+-----+-----+-----+
```

<!-- slide -->
### 題目3 - 程式碼

``` C
#include<stdio.h>

int findMaxRectangle(int matrix[][5], int left, int right, int up, int down){
  if (left >= right) return 0;
  if (up >= down) return 0;

  bool rectangle = true;
  for(int i = right; rectangle && i <= left; i++) {
    if(!matrix[up][i]) rectangle = false;
    if(!matrix[down][i]) rectangle = false;
  }
  for(int i = up; rectangle && i <= down; i++) {
    if(!matrix[i][left]) rectangle = false;
    if(!matrix[i][right]) rectangle = false;
  }

  if(rectangle) return (right - left + 1) * (down - up + 1);

  int result;
  result = findMaxRectangle(matrix, left + 1, right, up, down);
  if (result) return result;
  result = findMaxRectangle(matrix, left, right - 1, up, down);
  if (result) return result;
  result = findMaxRectangle(matrix, left, right, up + 1, down);
  if (result) return result;
  result = findMaxRectangle(matrix, left, right, up, down - 1);
  if (result) return result;
  return 0;
}

int main(){
  int matrix[][5]={
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0}
  };
  int maxRectangle = findMaxRectangle(matrix, 0, 4, 0, 4);
  printf("%d\n", maxRectangle);
}
```

<!-- slide -->
## 題目4

請利用框架撰寫一個function，給入一串數字陣列，輸出所有排列組合（只要列出所有組合即可，不用照順序﹚

<!-- slide -->
### 題目4 - 輸入

``` text
```

### 題目4 - 輸出

``` text
1 2 3 
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

<!-- slide -->
### 題目4 - 框架

``` C
#include<stdio.h>

void f(int * arr, int size, int i){
}

int main(){
  int arr[] = {1, 2, 3};
  f(arr, 3, 0);
}
```

<!-- slide -->
## 題目4 - 圖解

<!-- slide -->

``` dot
digraph f{
     node[shape=record];
     n1 [label="{{_1|_2|_3}}"];
     n2 [label="{{1|_2|_3}}"];
     n3 [label="{{2|_1|_3}}"];
     n4 [label="{{3|_2|_1}}"];
     n5 [label="{{1|2|_3}}"];
     n6 [label="{{1|3|_2}}"];
     n7 [label="{{2|1|_3}}"];
     n8 [label="{{2|3|_1}}"];
     n9 [label="{{3|1|_2}}"];
     n10 [label="{{3|2|_1}}"];
     n1 -> {n2, n3, n4};
     n2 -> {n5, n6};
     n3 -> {n7, n8};
     n4 -> {n9, n10};
}
```


<!-- slide -->
### 題目4 - 程式碼

``` C
#include<stdio.h>
#include<stdlib.h>

void f(int * arr, int size, int i){
  if(i+1==size){
    for(int j = 0; j < size; j++) printf("%d ", arr[j]);
    printf("\n");
    return ;
  }
  int *copyArr = (int*) malloc(size * sizeof(size));
  for(int j = 0; j < size; j++) copyArr[j] = arr[j];
  int num = arr[i];
  for(int j = i; j < size; j++){
    int tmp = arr[j];
    arr[i] = tmp;
    arr[j] = num;
    f(arr, size, i + 1);
    arr[i] = num;
    arr[j] = tmp;
  }
}

int main(){
  int arr[] = {1, 2, 3};
  f(arr, 3, 0);
}
```
