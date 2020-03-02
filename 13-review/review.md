<!-- slide -->
# 上學期的整理

<!-- slide -->
## pointer

<!-- slide vertical = true-->
``` C++
int a = 10;
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
+------+------+------+------+------+
|  XX  |  XX  |  XX  |  XX  |  XX  |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
+=-----+=-----+------+=-----+=-----+
|  XX  |  XX  |  10  |  XX  |  XX  |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->
``` C
printf("0X%x", &a);
```

<!-- slide vertical = true-->
``` C
printf("%d", a);
```

<!-- slide vertical = true-->
### call by value vs call by address

* 傳值 vs 傳址

<!-- slide vertical = true-->
### call by value

<!-- slide vertical = true-->
``` C
void assign(int value) {
    value = 20;
}
int main() {
    int a = 10;
    assign(a);
}
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                 a
+=-----+=-----+------+=-----+=-----+
|      |      |      |      |      |
|  XX  |  XX  |  10  |  XX  |  XX  |
|      |      |      |      |      |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                 a    value
+=-----+=-----+------+------+=-----+
|      |      |      | cYEL |      |
|  XX  |  XX  |  10  |  10  |  XX  |
|      |      |      |      |      |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                 a    value
+=-----+=-----+------+------+=-----+
|      |      |      | cYEL |      |
|  XX  |  XX  |  10  |  20  |  XX  |
|      |      |      |      |      |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->
### call by address

<!-- slide vertical = true-->
``` C
void assign(int *addr) {
    *addr = 20;
}
int main() {
    int a = 10;
    assign(&a);
}
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                 a
+=-----+=-----+------+=-----+=-----+
|      |      |      |      |      |
|  XX  |  XX  |  10  |  XX  |  XX  |
|      |      |      |      |      |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                 a     addr
+=-----+=-----+------+------+=-----+
|      |      |      | cYEL |      |
|  XX  |  XX  |  10  | 0X09 |  XX  |
|      |      |      |      |      |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                 a     addr
+=-----+=-----+------+------+=-----+
|      |      | cYEL |      |      |
|  XX  |  XX  |  20  | 0x09 |  XX  |
|      |      |      |      |      |
+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11
```

<!-- slide vertical = true-->
> 請舉幾個pointer的用途

<!-- slide vertical = true-->
### 回到經典練習題 - 兩數交換

```C
#include <stdio.h>
int swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp
}
void main() {
    int a = 3;
    int b = 4;
    swap(a, b);
    printf("a = %d, b = %d\n", a, b);
}
```

<!-- slide vertical = true-->
* 請問這段程式執行後會有什麼結果
* 如何修改才能達到兩數值交換

<!-- slide -->
## pointer2 and array

<!-- slide vertical = true-->
``` C++
int a[3] = {10, 20, 30};
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                arr
                 |
                 v
+=-----+=-----+------+------+------+------+=-----+
|      |      |      |      |      |      |      |
|  XX  |  XX  |  10  |  20  |  30  |  XX  |  XX  |
|      |      |      |      |      |      |      |
+------+------+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11   0X15   0X19
```

<!-- slide vertical = true-->
``` C++
int *ptr = arr;
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                arr
                 |
                 v                   ptr
+=-----+=-----+------+------+------+------+=-----+
|      |      |      |      |      |      |      |
|  XX  |  XX  |  10  |  20  |  30  | 0x09 |  XX  |
|      |      |      |      |      |      |      |
+------+------+------+------+------+------+------+
  0X01   0X05   0X09   0X0D   0X11   0X15   0X19
```


<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                arr
                 |
                 v                   ptr
+=-----+=-----+------+------+------+------+=-----+
|      |      |      |      |      |      |      |
|  XX  |  XX  |  10  |  20  |  30  | 0x09 |  XX  |
|      |      |      |      |      |      |      |
+------+------+------+------+------+-----++------+
  0X01   0X05   0X09^  0X0D   0X11   0X15|  0X19
                    |                    |
                    +--------------------+
```

<!-- slide vertical = true-->
如果

``` C++
ptr++;
```

妳覺得圖會怎麼變動

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                arr
                 |
                 v                   ptr
+=-----+=-----+------+------+------+------+=-----+
|      |      |      |      |      |      |      |
|  XX  |  XX  |  10  |  20  |  30  | 0x09 |  XX  |
|      |      |      |      |      |      |      |
+------+------+------+------+------+-----++------+
  0X01   0X05   0X09^  0X0D   0X11   0X15|  0X19
                    |                    |
                    +--------------------+
```

<!-- slide vertical = true-->
``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
                arr
                 |
                 v                   ptr
+=-----+=-----+------+------+------+------+=-----+
|      |      |      |      |      |      |      |
|  XX  |  XX  |  10  |  20  |  30  | 0x0D |  XX  |
|      |      |      |      |      |      |      |
+------+------+------+------+------+-----++------+
  0X01   0X05   0X09   0X0D^   0X11   0X15|  0X19
                           |              |
                           +--------------+
```

<!-- slide vertical = true-->
### 陣列輸出練習

請嘗試寫出兩個function
使用不同的辦法
但都不使用陣列表達方式
輸出陣列中的值

<!-- slide vertical = true-->
```C++
#include <stdio.h>
void printArray(int *arr, int size) {

}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    printArray(arr, 6);
}
```

<!-- slide -->
## recursize

在函式中呼叫自己

<!-- slide -->
### 應用

大問題切成小問題做

<!-- slide vertical = true-->
### 請撰寫盒內塔

![盒內塔](../../../image/2020-03-01-23-28-59.png)

<!-- slide vertical = true-->
#### 盒內塔 - 範例輸入

``` text
3
```

#### 盒內塔 - 範例輸出

``` text
Move disk 1 From tower 2 to tower 1
Move disk 2 From tower 2 to tower 3
Move disk 1 From tower 1 to tower 3
Move disk 3 From tower 2 to tower 1
Move disk 1 From tower 3 to tower 2
Move disk 2 From tower 3 to tower 1
Move disk 1 From tower 2 to tower 1
```

<!-- slide -->
## structure and union

<!-- slide vertical = true-->
### structure

自訂不同資料型態綁一起

<!-- slide vertical = true-->
``` C
struct St {
  int class;
  int number;
  char name[8];
  int rank;
};
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
 class  number     name      rank
+------+------+------------+------+------+------+------+
|      |      |            |      |      |      |      |
|  15  |  37  | Anna\0     |  10  |  XX  |  XX  |  XX  |
|      |      |            |      |      |      |      |
+------+------+------------+------+------+------+------+
  0X01   0X05      0X09      0X11   0X15   0X19   0X1D
```

<!-- slide vertical = true-->
### union

自訂不同資料型態綁一起，但存於同一段記憶體中

<!-- slide vertical = true-->
``` C
struct id {
  int intId;
  char charId;
  long long longId;
  double doubleId;
};
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
     intId
     charId
     longId
    doubleId
+-----------------+------+------+------+------+------+
|                 |      |      |      |      |      |
|       20        |  XX  |  XX  |  XX  |  XX  |  XX  |
|                 |      |      |      |      |      |
+-----------------+------+------+------+-----++------+
       0X01         0X0D   0X11   0X15   0X19
```

<!-- slide -->
## linked list

每個node紀錄下一個node的地址
即可將所有的node串接在一起

<!-- slide vertical = true-->
### linked list練習

請幫忙維護一個數字的串列
會給予以下的指令`insert`, `delete`, `print`來進行操作
串列的數字必須維持從小到大

<!-- slide vertical = true-->
### linked list - 範例輸入

```text
insert 3
insert 7
insert 5
print
delete 3
delete 7
insert 10
print
```

### linked list - 範例輸出

```text
3 5 7
5 10
```

<!-- slide -->
## 總練習

### 題目1

輸入一串字串，其中包含`{ }`, `( )`, `[ ]`，判斷字串中前面列出的這三種符號是否平衡

<!-- slide vertical = true-->
#### 題目1 - 範例輸入

``` text
{([])}
()
()[]
[(])
```

#### 題目1 - 範例輸出

``` text
balanced
balanced
balanced
not balanced
```

### 題目2

<!-- slide vertical = true-->
#### 題目2 - 範例輸入

``` text
```

#### 題目2 - 範例輸出

``` text
```
