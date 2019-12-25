<!-- slide -->
# quick sort

<!-- slide -->
## 整體邏輯 - 圖解

<!-- slide vertical = true-->
用quick sort排序此陣列

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
| 89 | 70 | 80 | 29 | 99 | 90 | 75 | 46 |
+----+----+----+----+----+----+----+----+
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
   +----+----+----+----+----+----+----+----+
   |cRED|    |    |    |    |    |    |    |
   | 89 | 70 | 80 | 29 | 99 | 90 | 75 | 46 |
   |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+
           |                           |
           v                           v
 +----+----+----+----+----+        +----+----+
 |cRED|    |    |    |    |        |cRED|    |
 | 75 | 70 | 80 | 29 | 46 |        | 90 | 99 |
 |    |    |    |    |    |        |    |    |
 +----+----+----+----+----+        +----+----+
          |         |                     |
        +-+         +-----+               +----+
        |                 |                    |
        v                 v                    v
+----+----+----+        +----+               +----+
|cRED|    |    |        |cRED|               |cRED|
| 29 | 70 | 46 |        | 80 |               | 99 |
|    |    |    |        |    |               |    |
+----+----+----+        +----+               +----+
         |
         v
    +----+----+
    |cRED|    |
    | 70 | 46 |
    |    |    |
    +----+----+
         |
         v
      +----+
      |cRED|
      | 46 |
      |    |
      +----+
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.3"]}
   +----+----+----+----+----+----+----+----+
   |cRED|    |    |    |    |    |    |    |
   | 89 | 70 | 80 | 29 | 99 | 90 | 75 | 46 |
   |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+
           |                           |
           v                           v
 +----+----+----+----+----+ +=---+ +----+----+
 |cRED|    |    |    |    | |    | |cRED|    |
 | 75 | 70 | 80 | 29 | 46 | | 89 | | 90 | 99 |
 |    |    |    |    |    | |    | |    |    |
 +----+----+----+----+----+ +----+ +----+----+
          |         |                     |
        +-+         +-----+               +----+
        |                 |                    |
        v                 v                    v
+----+----+----+ +=---+ +----+ +=---+ +=---+ +----+
|cRED|    |    | |    | |cRED| |    | |    | |cRED|
| 29 | 70 | 46 | | 75 | | 80 | | 89 | | 90 | | 99 |
|    |    |    | |    | |    | |    | |    | |    |
+----+----+----+ +----+ +----+ +----+ +----+ +----+
         |
         v
+=---+ +----+----+ +=---+ +=---+ +=---+ +=---+ +=---+
|    | |cRED|    | |    | |    | |    | |    | |    |
| 29 | | 70 | 46 | | 75 | | 80 | | 89 | | 90 | | 99 |
|    | |    |    | |    | |    | |    | |    | |    |
+----+ +----+----+ +----+ +----+ +----+ +----+ +----+
         |
         v
+=---+ +----+ +=---+ +=---+ +=---+ +=---+ +=---+ +=---+
|    | |cRED| |    | |    | |    | |    | |    | |    |
| 29 | | 46 | | 70 | | 75 | | 80 | | 89 | | 90 | | 99 |
|    | |    | |    | |    | |    | |    | |    | |    |
+----+ +----+ +----+ +----+ +----+ +----+ +----+ +----+

+=---+ +=---+ +=---+ +=---+ +=---+ +=---+ +=---+ +=---+
|    | |    | |cRED| |    | |    | |    | |    | |    |
| 29 | | 46 | | 70 | | 75 | | 80 | | 89 | | 90 | | 99 |
|    | |    | |    | |    | |    | |    | |    | |    |
+----+ +----+ +----+ +----+ +----+ +----+ +----+ +----+
```

<!-- slide -->
## 演算法 - 圖解

<!-- slide vertical = true-->
用quick sort排序此陣列

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
| 89 | 70 | 80 | 29 | 99 | 90 | 75 | 46 |
+----+----+----+----+----+----+----+----+
```

<!-- slide vertical = true-->
選擇一個數字做為中間值
此演算法選擇最左邊的位置作為中間值

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|cRED|    |    |    |    |    |    |    |
| 89 | 70 | 80 | 29 | 99 | 90 | 75 | 46 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|cRED|    |    |    |    |    |    |    |
| 89 | 70 | 80 | 29 | 99 | 90 | 75 | 46 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
  ^                                   ^
  |                                   |
  i                                   j
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|cRED|    |    |    |    |    |    |    |
| 89 | 70 | 80 | 29 | 99 | 90 | 75 | 46 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
                       ^              ^
                       |              |
                       i              j
```
<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|cRED|    |    |    |    |    |    |    |
| 89 | 70 | 80 | 29 | 46 | 90 | 75 | 99 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
                       ^              ^
                       |              |
                       i              j
```
<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|cRED|    |    |    |    |    |    |    |
| 89 | 70 | 80 | 29 | 46 | 90 | 75 | 99 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
                            ^    ^
                            |    |
                            i    j
```
<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|cRED|    |    |    |    |    |    |    |
| 89 | 70 | 80 | 29 | 46 | 75 | 90 | 99 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
                            ^    ^
                            |    |
                            i    j
```
<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|cRED|    |    |    |    |    |    |    |
| 89 | 70 | 80 | 29 | 46 | 75 | 90 | 99 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
                            ^    ^
                            |    |
                            j    i
```
<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+----+----+----+
|    |    |    |    |    |cRED|    |    |
| 75 | 70 | 80 | 29 | 46 | 89 | 90 | 99 |
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
                            ^    ^
                            |    |
                            j    i
```

<!-- slide vertical = true-->
分別把左右兩邊的陣列做同樣的排序

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+----+----+----+----+----+ +----+ +----+----+
|    |    |    |    |    | |    | |    |    |
| 75 | 70 | 80 | 29 | 46 | | 89 | | 90 | 99 |
|    |    |    |    |    | |    | |    |    |
+----+----+----+----+----+ +----+ +----+----+
```

<!-- slide -->
## 實作quick sort

<!-- slide vertical = true-->

將陣列中的int元素使用quick sort排列

<!-- slide vertical = true-->
### 題目1 - 輸出

``` text
2 5 7 8 9 
29 46 70 75 80 89 90 99
```

<!-- slide vertical = true-->
### 題目1 - 框架

``` C
#include <stdio.h>

void swap(int * var1, int * var2){
}

void print(int *array, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void quicksort(int *array, int start, int end, int size){
}

int main(){
  int array[] = {9, 5, 8, 2, 7};
  quicksort(array, 0, 5, 5);
  print(array, 5);
  int array2[] = {89, 70, 80, 29, 46, 90, 75, 99};
  quicksort(array2, 0, 8, 8);
  print(array2, 8);
}
```

<!-- slide vertical = true-->
### 題目1 - 程式碼

``` C
#include <stdio.h>

void swap(int * var1, int * var2){
    int tmp = *var1;
    *var1 = *var2;
    *var2 = tmp;
}

void print(int *array, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void quicksort(int *array, int start, int end){
  if(start >= end) return;
  int *pivot = array + start;
  int i, j;
  for (i = start, j = end; i < j;){
    do i++; while (i < end && array[i] < *pivot);
    do j--; while (j >= start && array[j] > *pivot);
    if(i < j) swap(array + i, array + j);
  }
  swap(pivot, array + j);
  quicksort(array, start, j);
  quicksort(array, j + 1, end);
}

int main(){
  int array[] = {9, 5, 8, 2, 7};
  quicksort(array, 0, 5);
  print(array, 5);
  int array2[] = {89, 70, 80, 29, 46, 90, 75, 99};
  quicksort(array2, 0, 8);
  print(array2, 8);
}
```


<!-- slide -->
## 實作泛型quick sort

<!-- slide vertical = true-->

將陣列中的任意元素使用quick sort排列

<!-- slide vertical = true-->
### 題目2 - 輸出

``` text
x of square one = 3, y of square one = 3
x of square two = 1, y of square two = 5
area1 = 9,  area2 = 5
x of square one = 2, y of square one = 4
x of square two = 1, y of square two = 5
area1 = 8,  area2 = 5
x of square one = 9, y of square one = 2
x of square two = 1, y of square two = 5
area1 = 18,  area2 = 5
x of square one = 3, y of square one = 3
x of square two = 1, y of square two = 5
area1 = 9,  area2 = 5
x of square one = 1, y of square one = 5
x of square two = 1, y of square two = 5
area1 = 5,  area2 = 5
Print sorted numbers of type int:
1 3 4 8 9

Print sorted numbers of type float:
0.90 2.10 3.40 5.90 4.30
```

<!-- slide vertical = true-->
### 題目2 - 框架

``` C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
 int x, y;
} Square;

typedef struct {
 int x, y;
} Point;

int compareSqrArea(const void *p, const void *q) {
 int area1, area2;
 const Square *a1 = p, *a2 = q;

 printf("x of square one = %d, y of square one = %d\n", a1->x, a1->y);
 printf("x of square two = %d, y of square two = %d\n", a2->x, a2->y);
 area1 = a1->x * a1->y;
 area2 = a2->x * a2->y;
 printf("area1 = %d,  area2 = %d\n", area1, area2);
 if (area1 > area2)  return 1;
 else if (area1 < area2) return -1;
 else return 0;
}

int comparePoint(const void *p, const void *q) {
 double dist1, dist2;
 const Point *pt1 = p, *pt2 = q;

 dist1 = sqrt(pt1->x * pt1->x + pt1->y * pt1->y);
 dist2 = sqrt(pt2->x * pt2->x + pt2->y * pt2->y);

 if (dist1 < dist2)  return -1;
 else if (dist1 > dist2)  return 1;
 else return 0;
}

int compareStr(const void* v1, const void* v2) {
 char *const*a1 = v1, *const*a2 = v2;

 return strcmp(*a1, *a2);
}

int compareFloat(const void *p, const void *q) {
 const float *n1 = p, *n2 = q;

 if (*n1 > *n2)  return 1;
 else if (*n1 < *n2) return -1;
 else return 0;
}

int compareInt(const void *p, const void *q) {
 const int *n1 = p, *n2 = q;

 if (*n1 > *n2)  return 1;
 else if (*n1 < *n2) return -1;
 else return 0;
}


void swap(void * var1, void * var2, int size){
}

void quicksort(void *array, int start, int end, int size, int compare(void*, void*)){
}


int main(void) {
 int list[5] = {4, 8, 1, 3, 9};
 float numbers[5] = {2.1, 3.4, 0.9, 5.9, 4.3};
 char* str[] = {"ball", "zibra", "enthernet", "donut", "animal", "loop", "home", "opera", "how"};
 Square sq[5];
 sq[0].x = 1;
 sq[0].y = 5;
 sq[1].x = 3;
 sq[1].y = 3;
 sq[2].x = 9;
 sq[2].y = 2;
 sq[3].x = 2;
 sq[3].y = 4;
 sq[4].x = 8;
 sq[4].y = 5;

 Point pts[5];
 pts[0].x = 0;
 pts[0].y = 5;
 pts[1].x = 3;
 pts[1].y = 3;
 pts[2].x = 9;
 pts[2].y = -1;
 pts[3].x = 2;
 pts[3].y = 4;
 pts[4].x = 4;
 pts[4].y = 5;

 quicksort(list, 0, 4, sizeof(int), compareInt);
 quicksort(numbers, 0, 4, sizeof(float), compareFloat);
 quicksort(str, 0, 8, sizeof(char*), compareStr);
 quicksort(sq, 0, 4, sizeof(Square), compareSqrArea);
 quicksort(pts, 0, 4, sizeof(Point), comparePoint);

 printf("Print sorted numbers of type int:\n");
 for(int i=0; i<=4; i++)
  printf("%d ", list[i]);

 printf("\n\nPrint sorted numbers of type float:\n");
 for(int i=0; i<=4; i++)
  printf("%.2f ", numbers[i]);

 printf("\n\nPrint sorted strings:\n");
 for(int i=0; i<=8; i++)
  printf("%s ", str[i]);

 printf("\n\nPrint sorted rectangles by area (height=x and width=y):\n");
 for(int i=0; i<5; i++)
  printf("x = %d,  y = %d\n", sq[i].x, sq[i].y);

 printf("\nPrint sorted points by distance to the origin:\n");
 for(int i=0; i<5; i++)
  printf("x = %d,  y = %d\n", pts[i].x, pts[i].y);
 return 0;
}
```

<!-- slide vertical = true-->
### 題目2 - 程式碼

``` C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
 int x, y;
} Square;

typedef struct {
 int x, y;
} Point;

int compareSqrArea(const void *p, const void *q) {
 int area1, area2;
 const Square *a1 = p, *a2 = q;

 printf("x of square one = %d, y of square one = %d\n", a1->x, a1->y);
 printf("x of square two = %d, y of square two = %d\n", a2->x, a2->y);
 area1 = a1->x * a1->y;
 area2 = a2->x * a2->y;
 printf("area1 = %d,  area2 = %d\n", area1, area2);
 if (area1 > area2)  return 1;
 else if (area1 < area2) return -1;
 else return 0;
}

int comparePoint(const void *p, const void *q) {
 double dist1, dist2;
 const Point *pt1 = p, *pt2 = q;

 dist1 = sqrt(pt1->x * pt1->x + pt1->y * pt1->y);
 dist2 = sqrt(pt2->x * pt2->x + pt2->y * pt2->y);

 if (dist1 < dist2)  return -1;
 else if (dist1 > dist2)  return 1;
 else return 0;
}

int compareStr(const void* v1, const void* v2) {
 char *const*a1 = v1, *const*a2 = v2;

 return strcmp(*a1, *a2);
}

int compareFloat(const void *p, const void *q) {
 const float *n1 = p, *n2 = q;

 if (*n1 > *n2)  return 1;
 else if (*n1 < *n2) return -1;
 else return 0;
}

int compareInt(const void *p, const void *q) {
 const int *n1 = p, *n2 = q;

 if (*n1 > *n2)  return 1;
 else if (*n1 < *n2) return -1;
 else return 0;
}


void swap(void * var1, void * var2, int size){
    void *tmp = malloc(size);
    memcpy(tmp, var1, size);
    memcpy(var1, var2, size);
    memcpy(var2, tmp, size);
    free(tmp);
}

void quicksort(void *array, int start, int end, int size, int compare(void*, void*)){
  if(start >= end) return;
  int *pivot = array + start*size;
  int i, j;
  for (i = start, j = end; i < j;){
    do i++; while (i < end && compare(array + i*size, pivot) < 0);
    do j--; while (j >= start && compare(array + j*size, pivot) > 0);
    if(i < j) swap(array + i*size, array + j*size, size);
  }
  swap(pivot, array + j*size, size);
  quicksort(array, start, j, size, compareInt);
  quicksort(array, j + 1, end, size, compareInt);
}


int main(void) {
 int list[5] = {4, 8, 1, 3, 9};
 float numbers[5] = {2.1, 3.4, 0.9, 5.9, 4.3};
 char* str[] = {"ball", "zibra", "enthernet", "donut", "animal", "loop", "home", "opera", "how"};
 Square sq[5];
 sq[0].x = 1;
 sq[0].y = 5;
 sq[1].x = 3;
 sq[1].y = 3;
 sq[2].x = 9;
 sq[2].y = 2;
 sq[3].x = 2;
 sq[3].y = 4;
 sq[4].x = 8;
 sq[4].y = 5;

 Point pts[5];
 pts[0].x = 0;
 pts[0].y = 5;
 pts[1].x = 3;
 pts[1].y = 3;
 pts[2].x = 9;
 pts[2].y = -1;
 pts[3].x = 2;
 pts[3].y = 4;
 pts[4].x = 4;
 pts[4].y = 5;

 quicksort(list, 0, 4, sizeof(int), compareInt);
 quicksort(numbers, 0, 4, sizeof(float), compareFloat);
 quicksort(str, 0, 8, sizeof(char*), compareStr);
 quicksort(sq, 0, 4, sizeof(Square), compareSqrArea);
 quicksort(pts, 0, 4, sizeof(Point), comparePoint);

 printf("Print sorted numbers of type int:\n");
 for(int i=0; i<=4; i++)
  printf("%d ", list[i]);

 printf("\n\nPrint sorted numbers of type float:\n");
 for(int i=0; i<=4; i++)
  printf("%.2f ", numbers[i]);

 printf("\n\nPrint sorted strings:\n");
 for(int i=0; i<=8; i++)
  printf("%s ", str[i]);

 printf("\n\nPrint sorted rectangles by area (height=x and width=y):\n");
 for(int i=0; i<5; i++)
  printf("x = %d,  y = %d\n", sq[i].x, sq[i].y);

 printf("\nPrint sorted points by distance to the origin:\n");
 for(int i=0; i<5; i++)
  printf("x = %d,  y = %d\n", pts[i].x, pts[i].y);
 return 0;
}
```
