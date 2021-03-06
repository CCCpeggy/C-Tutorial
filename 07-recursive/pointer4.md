<!-- slide -->
# pointer 題目練習

<!-- slide -->
## 題目

政府對台灣各國中進行幾個項目的評測，其中包含整潔、讀書風氣、課外活動、教師、幸福度，並希望依加權後的成果進行排名並列出。

<!-- slide -->
因為記錄的資料是不會變的，所以關於score的型態都會是const的

<!-- slide -->
## 思路

1. copy一份array
2. 用指標陣列儲存指向每一層array

<!-- slide -->
## 框架

``` C
#include<stdio.h>
#define col 5

void printSort(const int score[][col], const int weight[col], int size){

}

int main(){
  const int score[6][col]{
    {83, 34, 42, 20, 75},
    {20, 35, 62, 94, 58},
    {50, 82, 24, 98, 83},
    {30, 63, 54, 32, 53},
    {34, 63, 52, 32, 64},
    {76, 44, 38, 10, 32}
  };
  int weight[col] = {2, 1, 3, 2, 1};
  printSort(score, weight, 6);
  return 0;
}
```

<!-- slide -->
## 輸入範例

無

## 輸出範例

``` text
> 50 82 24 98 83
> 20 35 62 94 58
> 83 34 42 20 75
> 34 63 52 32 64
> 30 63 54 32 53
> 76 44 38 10 32
```

<!-- slide -->
## 圖解 - 初始sort跟sum

<!-- slide -->
初始

```ditaa {cmd=true args=["-E"]}
       +-----+-----+-----+-----+-----+
weight |  2  |  1  |  3  |  2  |  1  |
       +-----+-----+-----+-----+-----+
         0x3c  0x40  0x44  0x48  0x4c

      +------+------+------+------+------+
score |  83  |  34  |  42  |  20  |  75  |
      +------+------+------+------+------+
        0x00   0x04   0x08   0x0c   0x10  
      +------+------+------+------+------+
      |  20  |  35  |  62  |  94  |  58  |
      +------+------+------+------+------+
        0x14   0x18   0x1c   0x20   0x24  
      +------+------+------+------+------+
      |  50  |  82  |  24  |  98  |  83  |
      +------+------+------+------+------+
        0x28   0x2c   0x30   0x34   0x38  

      +--+---+--+---+--+---+
sort  | XXXX | XXXX | XXXX |
      +------+------+------+
        0x50   0x54   0x58

      +-----+-----+-----+
sum   | XXX | XXX | XXX |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 0;
sum[i] = 0;
// sum += 83 * 2 + 34 * 1 + 42 * 3 + 20 * 2 + 75 * 1
// sum += 441
for(int j = 0; j < col; j++){
  sum[i] += score[i][j] * weight[j];
}
// sort[i] = 0x00
sort[i] = score[i];
```

```ditaa {cmd=true args=["-E"]}
       +-----+-----+-----+-----+-----+
weight |  2  |  1  |  3  |  2  |  1  |
       +-----+-----+-----+-----+-----+
         0x3c  0x40  0x44  0x48  0x4c

                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |                        :  20  :  35  :  62  :  94  :  58  :
         |                        +------+------+------+------+------+
         |                          0x14   0x18   0x1c   0x20   0x24  
         |                        +------+------+------+------+------+
         |                        |  50  :  82  :  24  :  98  :  83  :
         |                        +------+------+------+------+------+
         |                          0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | XXXX | XXXX |
      +------+------+------+
        0x50   0x54   0x58

      +-----+-----+-----+
sum   | 441 | XXX | XXX |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 1;
sum[i] = 0;
// sum += 20 * 2 + 35 * 1 + 62 * 3 + 94 * 2 + 58 * 1
// sum += 507
for(int j = 0; j < col; j++){
  sum[i] += score[i][j] * weight[j];
}
// sort[i] = 0x14
sort[i] = score[i];
```

```ditaa {cmd=true args=["-E"]}
       +-----+-----+-----+-----+-----+
weight |  2  |  1  |  3  |  2  |  1  |
       +-----+-----+-----+-----+-----+
         0x3c  0x40  0x44  0x48  0x4c

                                　+------+------+------+------+------+
score    +----------------------->:  83  :  34  :  42  :  20  :  75  :
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |                 |  50  :  82  :  24  :  98  :  83  :
         |      |                 +------+------+------+------+------+
         |      |                   0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | XXXX |
      +------+------+------+
        0x50   0x54   0x58

      +-----+-----+-----+
sum   | 441 | 507 | XXX |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 2;
sum[i] = 0;
// sum += 50 * 2 + 82 * 1 + 24 * 3 + 98 * 2 + 83 * 1
// sum += 533
for(int j = 0; j < col; j++){
  sum[i] += score[i][j] * weight[j];
}
// sort[i] = 0x28
sort[i] = score[i];
```

```ditaa {cmd=true args=["-E"]}
       +-----+-----+-----+-----+-----+
weight |  2  |  1  |  3  |  2  |  1  |
       +-----+-----+-----+-----+-----+
         0x3c  0x40  0x44  0x48  0x4c

                                　+------+------+------+------+------+
score    +----------------------->:  83  :  34  :  42  :  20  :  75  :
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->:  20  :  35  :  62  :  94  :  58  :
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | 0x28 |
      +------+------+------+
        0x50   0x54   0x58

      +-----+-----+-----+
sum   | 441 | 507 | 533 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
## 圖解 - sort

<!-- slide -->
``` C
i = 0;
int select = i;
for(int j = i + 1; j < size; j++)
  if(sum[j] > sum[select]) select = j;
// select = 2
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | 0x28 |
      +------+------+------+
        0x50   0x54   0x58

      +--+--+--+--+--+--+
sum   | 441 | 507 | 533 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 0;
select = 2;
for(int j = 0; j < col; j++){
  printf("%d ", sort[select][j]);
}
printf("\n");
// 50 82 24 98 83
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->:  83  :  34  :  42  :  20  :  75  :
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->:  20  :  35  :  62  :  94  :  58  :
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | 0x28 |
      +------+------+------+
        0x50   0x54   0x58

      +--+--+--+--+--+--+
sum   | 441 | 507 | 533 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 0;
select = 2;
sort[select] = sort[i];
sum[select] = sum[i];
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  : 0x00 : 0x14 | 0x00 |
      +------+------+------+
        0x50   0x54   0x58

      +-----+-----+-----+
sum   : 441 : 507 | 441 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 1;
int select = i;
for(int j = i + 1; j < size; j++)
  if(sum[j] > sum[select]) select = j;
// select = 1
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | 0x28 |
      +------+------+------+
        0x50   0x54   0x58

      +--+--+--+--+--+--+
sum   | 441 | 507 | 533 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 1;
select = 1;
for(int j = 0; j < col; j++){
  printf("%d ", sort[select][j]);
}
printf("\n");
// 20 35 62 94 58
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->:  83  :  34  :  42  :  20  :  75  :
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  :  82  :  24  :  98  :  83  :
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | 0x28 |
      +------+------+------+
        0x50   0x54   0x58

      +--+--+--+--+--+--+
sum   | 441 | 507 | 533 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 1;
select = 1;
sort[select] = sort[i];
sum[select] = sum[i];
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  : 0x00 | 0x14 | 0x00 :
      +------+------+------+
        0x50   0x54   0x58

      +-----+-----+-----+
sum   : 441 | 507 | 441 :
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 2;
int select = i;
for(int j = i + 1; j < size; j++)
  if(sum[j] > sum[select]) select = j;
// select = 0
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | 0x28 |
      +------+------+------+
        0x50   0x54   0x58

      +--+--+--+--+--+--+
sum   | 441 | 507 | 533 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 2;
select = 0;
for(int j = 0; j < col; j++){
  printf("%d ", sort[select][j]);
}
printf("\n");
// 20 35 62 94 58
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->:  20  :  35  :  62  :  94  :  58  :
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  :  82  :  24  :  98  :  83  :
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 | 0x28 |
      +------+------+------+
        0x50   0x54   0x58

      +--+--+--+--+--+--+
sum   | 441 | 507 | 533 |
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
``` C
i = 2;
select = 0;
sort[select] = sort[i];
sum[select] = sum[i];
```

```ditaa {cmd=true args=["-E"]}
                                　+------+------+------+------+------+
score    +----------------------->|  83  |  34  |  42  |  20  |  75  |
         |                        +------+------+------+------+------+
         |                          0x00   0x04   0x08   0x0c   0x10  
         |                        +------+------+------+------+------+
         |      +---------------->|  20  |  35  |  62  |  94  |  58  |
         |      |                 +------+------+------+------+------+
         |      |                   0x14   0x18   0x1c   0x20   0x24  
         |      |                 +------+------+------+------+------+
         |      |      +--------->|  50  |  82  |  24  |  98  |  83  |
         |      |      |          +------+------+------+------+------+
         |      |      |            0x28   0x2c   0x30   0x34   0x38  
      +--+---+--+---+--+---+
sort  | 0x00 | 0x14 : 0x00 :
      +------+------+------+
        0x50   0x54   0x58

      +-----+-----+-----+
sum   | 441 | 507 : 441 :
      +-----+-----+-----+
       0x5C  0x60  0x64
```

<!-- slide -->
## 程式碼

``` C
#include<stdio.h>
#define col 5

void printSort(const int score[][col], const int weight[col], int size){
  int *sum = new int[size];
  const int **sort = new const int*[size]{};

  // init
  for(int i = 0; i < size; i++){
    sum[i] = 0;
    for(int j = 0; j < col; j++){
      sum[i] += score[i][j] * weight[j];
    }
    sort[i] = score[i];
  }

  for(int i = 0; i < size; i++){
    int select = i;
    for(int j = i + 1; j < size; j++){
      if(sum[j] > sum[select]){
        select = j;
      }
    }

    for(int j = 0; j < col; j++){
      printf("%d ", sort[select][j]);
    }
    printf(", sum = %d\n", sum[select]);

    sort[select] = sort[i];
    sum[select] = sum[i];
  }
}
```

<!-- slide -->

## sort 排列

```ditaa {cmd=true args=["-E"]}
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
  i j
  | |
  v v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
  ^
  |
 max

```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
  i j
  | |
  v v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
   ^
   |
  max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
  i j
  | |
  | +------+
  |        |
  v        v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
   ^
   |
  max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
  i j
  | |
  | +-------------+
  |               |
  v               v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
   ^
   |
  max
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
  i j
  | |
  | +--------------------+
  |                      |
  v                      v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
   ^
   |
  max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
  i j
  | |
  | +---------------------------+
  |                             |
  v                             v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
   ^
   |
  max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
  i j
  | |
  | +---------------------------+
  |                             |
  v                             v
+------+------+------+------+------+
|  83  |  34  :  42  :  20  :  75  |
+------+------+------+------+------+
   ^
   |
  max
```





<!-- slide -->
```ditaa {cmd=true args=["-E"]}
          i j
          | |
          v v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
           ^
           |
          max

```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
         i j
         | |
         | +------+
         |        |
         v        v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
                  ^
                  |
                 max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
          i j
          | |
          | +-------------+
          |               |
          v               v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
                  ^
                  |
                 max
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
          i j
          | |
          | +-------------------+
          |                     |
          v                     v
+------+------+------+------+------+
|  83  |  34  |  42  |  20  |  75  |
+------+------+------+------+------+
                                ^
                                |
                               max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
           i  j
           |  |
           |  +------------------+
           |                     |
           v                     v
+------+------+------+------+------+
:  83  |  75  |  42  :  20  |  34  |
+------+------+------+------+------+
                                ^
                                |
                               max
```





<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                i  j
                |  |
                v  v
+------+------+------+------+------+
|  83  |  75  |  42  |  20  |  34  |
+------+------+------+------+------+
                  ^
                  |
                 max

```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                  i  j
                  |  |
                  |  +----+
                  |       |
                  v       v
+------+------+------+------+------+
|  83  |  75  |  42  |  20  |  34  |
+------+------+------+------+------+
                  ^
                  |
                 max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                  i  j
                  |  |
                  |  +---------+
                  |            |
                  v            v
+------+------+------+------+------+
|  83  |  75  |  42  |  20  |  34  |
+------+------+------+------+------+
                  ^
                  |
                 max
```





<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                       i  j
                       |  |
                       v  v
+------+------+------+------+------+
|  83  |  75  |  42  |  20  |  34  |
+------+------+------+------+------+
                         ^
                         |
                        max

```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                         i  j
                         |  |
                         |  +----+
                         |       |
                         v       v
+------+------+------+------+------+
|  83  |  75  |  42  |  20  |  34  |
+------+------+------+------+------+
                                ^
                                |
                               max
```
<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                         i  j
                         |  |
                         |  +----+
                         |       |
                         v       v
+------+------+------+------+------+
|  83  :  75  :  42  |  34  |  20  |
+------+------+------+------+------+
                                ^
                                |
                               max
```




<!-- slide -->
```ditaa {cmd=true args=["-E"]}
                              i  j
                              |  |
                              v  v
+------+------+------+------+------+
|  83  :  75  :  42  |  34  |  20  |
+------+------+------+------+------+
                                ^
                                |
                               max

```
<!-- slide -->