<!-- slide -->
# structure

<!-- slide -->
## 例子

<!-- slide -->
如何記錄這顆蘋果？

![](../../../image/2019-11-21-13-18-44.png)

<!-- slide -->

* 顏色
* 大小
* 重量
* 價格
* 等等...

<!-- slide -->

``` C
struct Apple{
    char *color;
    int size;
    int weight;
    int price;
};
```

<!-- slide -->
如果今天有一顆新蘋果，
其中它的顏色是red，大小：10，重量：20，價格：50

``` C
struct Apple apple1{"red", 10, 20, 50};
```

<!-- slide -->
### 例子 - 程式碼1

``` C
printf("apple1 color: %s\n", apple1.color);
printf("apple1 size: %d\n", apple1.size);
printf("apple1 weight: %d\n", apple1.weight);
printf("apple1 price: %d\n", apple1.price);
```

### 例子 - 輸出

``` output
> apple1 color: red
> apple1 size: 10
> apple1 weight: 20
> apple1 price: 50
```

<!-- slide -->
如果這顆蘋果一直賣不出去，賣家只好降價改賣30元

<!-- slide -->
### 例子 - 程式碼2

``` C
apple1.price = 30;
printf("apple1 color: %s\n", apple1.color);
printf("apple1 size: %d\n", apple1.size);
printf("apple1 weight: %d\n", apple1.weight);
printf("apple1 price: %d\n", apple1.price);
```

### 例子 - 輸出2

``` output
> apple1 color: red
> apple1 size: 10
> apple1 weight: 20
> apple1 price: 30
```

<!-- slide -->
## 題目1

賣場進了一些水果，店家會先輸入進貨數量，再依color, size, weight, price輸入蘋果的資訊。當客人來購買蘋果時，可以透過輸入編號，查詢對應蘋果的資訊。
![](../../../image/2019-11-25-13-31-05.png)

<!-- slide -->
### 題目1 - 輸入

``` text
3
red 18 50 50
yellow 18 40 40
green 16 30 30
1
0
2
4
```

### 題目1 - 輸出

``` text
color: yellow, size: 18, weight: 40, price: 40
color: red, size: 18, weight: 50, price: 50
color: green, size: 16, weight: 30, price: 30
Out of range
```

<!-- slide -->
### 題目1 - 框架

``` C
#include <stdio.h>
#include <stdlib.h>

struct Apple{
    char color[10];
    int size;
    int weight;
    int price;
};

int main(){
}
```

<!-- slide -->
### 題目1 - 圖解

#### 資料儲存格式

```ditaa {cmd=true args=["-E"]}
 apples
+------+
|      +----+
+------+    |
            v color      size  weight  price
          +------------+------+------+------+
apples[0] | red\0      |  18  |  50  |  50  |
          +------------+------+------+------+
apples[1] | yellow\0   |  18  |  40  |  40  |
          +------------+------+------+------+
apples[2] | green\0    |  16  |  30  |  30  |
          +------------+------+------+------+
```

<!-- slide -->
#### 資料儲存方式

```ditaa {cmd=true args=["-E"]}
 apples
+------+
|      |
+------+
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
 apples
+------+
|      +----+
+------+    |
            v color      size  weight  price
          +------------+------+------+------+
apples[0] |            |      |      |      |
          +------------+------+------+------+
apples[1] |            |      |      |      |
          +------------+------+------+------+
apples[2] |            |      |      |      |
          +------------+------+------+------+
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
 apples
+------+
|      +----+
+------+    |
            v color      size  weight  price
          +------------+------+------+------+
apples[0] | red\0      |  18  |  50  |  50  |
          +------------+------+------+------+
apples[1] |            |      |      |      |
          +------------+------+------+------+
apples[2] |            |      |      |      |
          +------------+------+------+------+
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
 apples
+------+
|      +----+
+------+    |
            v color      size  weight  price
          +------------+------+------+------+
apples[0] | red\0      |  18  |  50  |  50  |
          +------------+------+------+------+
apples[1] | yellow\0   |  18  |  40  |  40  |
          +------------+------+------+------+
apples[2] |            |      |      |      |
          +------------+------+------+------+
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
 apples
+------+
|      +----+
+------+    |
            v color      size  weight  price
          +------------+------+------+------+
apples[0] | red\0      |  18  |  50  |  50  |
          +------------+------+------+------+
apples[1] | yellow\0   |  18  |  40  |  40  |
          +------------+------+------+------+
apples[2] | green\0    |  16  |  30  |  30  |
          +------------+------+------+------+
```

<!-- slide -->
### 題目1 - 程式碼

``` C
int main(){
  int n;
  scanf("%d", &n);
  struct Apple * apples = (struct Apple*) malloc(sizeof(struct Apple) * n);
  for(int i = 0; i < n; i++){
    scanf("%s%d%d%d", apples[i].color, &apples[i].size, &apples[i].weight, &apples[i].price);
  }
  while(true){
    int i;
    scanf("%d", &i);
    if(i < n && i >= 0)
      printf("color: %s, size: %d, weight: %d, price: %d\n", apples[i].color, apples[i].size, apples[i].weight, apples[i].price);
    else
      printf("Out of range\n") ;
  }
}
```

<!-- slide -->
## 題目2

請設計一個儲存學生期中成績的structure，期中包含英文(EN)、國文(CN)、體育(PE)、社會(SS)、物理(HIST)成績，並將成績最高的學生成績印出
(此題沒有框架)

<!-- slide -->
### 題目2 - 輸入

``` text
3
80 90 40 50 20
84 93 86 82 75
10 40 40 50 24
```

### 題目2 - 輸出

``` text
EN: 84, CN: 93, PE: 86, SS: 82, HIST: 75
```
<!-- slide -->
### 題目2 - 程式碼

``` C
#include <stdio.h>
#include <stdlib.h>

struct Student{
    int en;
    int cn;
    int pe;
    int ss;
    int hist;
};
int main(){
  int n;
  scanf("%d", &n);
  struct Student st, maxSt;
  int maxSum = 0;
  for(int i = 0; i < n; i++){
    scanf("%d%d%d%d%d", &st.en, &st.cn, &st.pe, &st.ss, &st.hist);
    int sum = st.en + st.cn + st.pe + st.ss + st.hist;
    if(sum > maxSum){
      maxSt = st;
      maxSum = sum;
    }
  }
  printf("EN: %d, CN: %d, PE: %d, SS: %d, HIST: %d\n", maxSt.en, maxSt.cn, maxSt.pe, maxSt.ss, maxSt.hist);
}
```

<!-- slide -->
## 直接宣告

``` C
struct Apple{
    char color[10];
    int size;
    int weight;
    int price;
} apple;
```

<!-- slide -->
## typedef

將資料型別取別名

<!-- slide -->
### typedef - 例子1

``` C
typedef int* intPtr;
intPtr ptr;
```

相當於

``` C
int* ptr;
```

<!-- slide -->
### typedef - 應用在structure

``` C
struct Apple{
    char *color;
    int size;
    int weight;
    int price;
};
typedef struct Apple Apple
```

<!-- slide -->
``` C
typedef struct Apple{
    char *color;
    int size;
    int weight;
    int price;
} Apple;
```

<!-- slide -->
## structure指標

<!-- slide -->
## structure function

<!-- slide -->
## nested structure

<!-- slide -->
## 應用 CRUD

<!-- slide -->
## union

<!-- slide -->
``` C
struct Data{
  int numInt;
  double numDouble;
  float numFloat;
  long long numLongLong;
};
```

```ditaa {cmd=true args=["-E"]}
  numInt   numDouble   numFloat  numLongLong
+-------+--------------+-------+-------------+
|       |              |       |             |
+-------+--------------+-------+-------------+
```

<!-- slide -->
``` C
union Data{
  int numInt;
  double numDouble;
  float numFloat;
  long long numLongLong;
};
```

```ditaa {cmd=true args=["-E"]}
  numInt
  numDouble
  numFloat
  numLongLong
+--------------+
|              |
+--------------+
```

<!-- slide -->
``` C
#include <stdio.h>
#include <stdlib.h>

union Data{
  int numInt;
  double numDouble;
  float numFloat;
  long long numLongLong;
};

int main(){
  union Data d;
  d.numInt = 10;
  printf("when d.numInt = %d\n", d.numInt);
  printf("int: %d\n", d.numInt);
  printf("double: %lf\n", d.numDouble);
  printf("float: %f\n", d.numFloat);
  printf("long long: %lld\n\n", d.numLongLong);
  d.numDouble = 10;
  printf("when d.numDouble = %.0lf\n", d.numDouble);
  printf("int: %d\n", d.numInt);
  printf("double: %lf\n", d.numDouble);
  printf("float: %f\n", d.numFloat);
  printf("long long: %lld\n\n", d.numLongLong);
  d.numFloat = 10;
  printf("when d.numFloat = %.0f\n", d.numFloat);
  printf("int: %d\n", d.numInt);
  printf("double: %lf\n", d.numDouble);
  printf("float: %f\n", d.numFloat);
  printf("long long: %lld\n\n", d.numLongLong);
  d.numLongLong = 10;
  printf("when d.numLongLong = %lld\n", d.numLongLong);
  printf("int: %d\n", d.numInt);
  printf("double: %lf\n", d.numDouble);
  printf("float: %f\n", d.numFloat);
  printf("long long: %lld\n\n", d.numLongLong);
}
```

<!-- slide -->
### union使用目的

* 節省空間

<!-- slide -->
## 題目4

撰寫一個陣列儲存資料，且每一格的資料型態不一樣，可能為int, long long, char, short, double, float，最後將儲存的資料以輸入相反的順序輸出

<!-- slide -->
### 題目4 - 輸入

``` text
4
doube
100000.10
float
8.9
int
30
char
c
```

### 題目4 - 輸出

``` text
c
30
8.900000
100000.100000
```

<!-- slide -->
### 題目4 - 框架

``` C
#include <stdio.h>
#include <stdlib.h>

#define INT_TYPE 0
#define DOUBLE_TYPE 1
#define FLOAT_TYPE 2
#define LONGLONG_TYPE 3
#define CHAR_TYPE 4

int main(){

}
```

<!-- slide -->
### 題目4 - 程式碼

``` C
#include <stdio.h>
#include <stdlib.h>
#define INT_TYPE 0
#define DOUBLE_TYPE 1
#define FLOAT_TYPE 2
#define LONGLONG_TYPE 3
#define CHAR_TYPE 4

union Data{
  int _int;
  double _double;
  float _float;
  long long _llong;
  char _char;
};

typedef struct SData{
  union Data data;
  int type;
} SData;

int main(){
  int n;
  scanf("%d", &n);
  SData *d = (SData*) malloc(sizeof(SData) * n);
  for(int i = 0; i < n; i++){
    char type[10];
    scanf("%s\n", type);
    if(type[0] == 'i'){
      d[i].type = INT_TYPE;
      scanf("%d", &d[i].data._int);
    }
    else if(type[0] == 'd'){
      d[i].type = DOUBLE_TYPE;
      scanf("%lf", &d[i].data._double);
    }
    else if(type[0] == 'f'){
      d[i].type = FLOAT_TYPE;
      scanf("%f", &d[i].data._float);
    }
    else if(type[0] == 'l'){
      d[i].type = LONGLONG_TYPE;
      scanf("%lld", &d[i].data._llong);
    }
    else if(type[0] == 'c'){
      d[i].type = CHAR_TYPE;
      scanf("%c", &d[i].data._char);
    }
  }
  for(int i = n - 1; i >= 0; i--){
    switch(d[i].type){
      case INT_TYPE:
        printf("%d\n", d[i].data._int);
        break;
      case DOUBLE_TYPE:
        printf("%lf\n", d[i].data._double);
        break;
      case FLOAT_TYPE:
        printf("%f\n", d[i].data._float);
        break;
      case LONGLONG_TYPE:
        printf("%lld\n", d[i].data._llong);
        break;
      case CHAR_TYPE:
        printf("%c\n", d[i].data._char);
        break;
    }
  }
}
```

<!-- slide -->
## enum

### enum

<!-- slide -->
## 題目5

請將題目4的type的部分改用enum實作

<!-- slide -->
### 題目5 - 程式碼

``` C
```
