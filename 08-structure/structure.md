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
### 題目2 - 圖解

<!-- slide -->
### 題目2 - 程式碼

``` C
```
