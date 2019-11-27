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
如果今天有一顆新蘋果
而它的資訊如下
* 顏色：red
* 大小：10
* 重量：20
* 價格：50

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
如果這顆蘋果一直賣不出去
賣家只好降價改賣30元

``` C
apple1.price = 30;
```

<!-- slide -->
### 例子 - 程式碼2

``` C
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
  while(1)){
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

請設計一個儲存學生期中成績的structure，其中包含英文(EN)、國文(CN)、體育(PE)、社會(SS)、物理(HIST)成績，並將成績最高的學生成績印出
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

``` C
typedef struct Apple{
    char *color;
    int size;
    int weight;
    int price;
} Apple;
int main(){
  struct Apple apple = {"red", 10, 20, 30};
  struct Apple *applePtr = &apple;
}
```

<!-- slide -->
``` C
printf("size: %d\n", (*applePtr).size );
```

<!-- slide -->
``` C
printf("size: %d\n", applePtr->size );
```

<!-- slide -->
## nested structure

``` C
struct St{
    int id;
    char name[10];
};

struct Class{
    struct St st[10];
};
```

<!-- slide -->

``` C
struct St{
    int id;
    char name[10];
};

struct Class{
    struct St st[10];
};

int main(){
  struct Class class;
  class.st[0].id = 1;
}
```

<!-- slide -->
## 題目3

程式國小想要做一個學生資訊系統
請你幫他整理資訊

<!-- slide -->
他們所提出的需求如下：

* 需要有儲存學生的類別
  * 座號
  * 108年期末成績
  * 請假幾次
* 需要有儲存班級的類別
  * 班上所有的學生
  * 年級
  * 班別

<!-- slide -->
他們所提出的功能如下：

* 輸出全校的學生名單(command 1)
* 輸出各班的前三名(command 2)
* 輸出全校的前三名(command 3)
* 依班級再依成績輸出全班的名單(command 4)
* 輸出全校全勤名單(command 5)
* 輸出全校平均(command 6)

<!-- slide -->
### 題目3 - 輸入

``` text
5

4 1 1
1 90 3
2 59 0
3 70 2
4 60 1

3 1 2
1 90 3
2 89 0
4 40 1

4 2 1
1 40 3
2 79 2
3 80 3
5 40 0

2 2 2
1 30 0
3 40 1

3 2 3
2 70 1
3 29 1
4 80 0
1
2
3
4
5
6
```

<!-- slide -->
### 題目3 - 輸出

``` text
1-1
id: 1, score: 90, leave: 3
id: 2, score: 59, leave: 0
id: 3, score: 70, leave: 2
id: 4, score: 60, leave: 1

1-2
id: 1, score: 90, leave: 3
id: 2, score: 89, leave: 0
id: 4, score: 40, leave: 1

2-1
id: 1, score: 40, leave: 3
id: 2, score: 79, leave: 2
id: 3, score: 80, leave: 3
id: 5, score: 40, leave: 0

2-2
id: 1, score: 30, leave: 0
id: 3, score: 40, leave: 1

2-3
id: 2, score: 70, leave: 1
id: 3, score: 29, leave: 1
id: 4, score: 80, leave: 0

1-1
id: 1, score: 90, leave: 3
id: 3, score: 70, leave: 2
id: 4, score: 60, leave: 1

1-2
id: 1, score: 90, leave: 3
id: 2, score: 89, leave: 0
id: 4, score: 40, leave: 1

2-1
id: 3, score: 80, leave: 3
id: 2, score: 79, leave: 2
id: 1, score: 40, leave: 3

2-2
id: 3, score: 40, leave: 1
id: 1, score: 30, leave: 0

2-3
id: 4, score: 80, leave: 0
id: 2, score: 70, leave: 1
id: 3, score: 29, leave: 1

id: 1, score: 90, leave: 3
id: 1, score: 90, leave: 3
id: 2, score: 89, leave: 0

1-1
id: 1, score: 90, leave: 3
id: 3, score: 70, leave: 2
id: 2, score: 59, leave: 0
id: 4, score: 60, leave: 1

1-2
id: 1, score: 90, leave: 3
id: 2, score: 89, leave: 0
id: 4, score: 40, leave: 1

2-1
id: 3, score: 80, leave: 3
id: 1, score: 40, leave: 3
id: 2, score: 79, leave: 2
id: 5, score: 40, leave: 0

2-2
id: 3, score: 40, leave: 1
id: 1, score: 30, leave: 0

2-3
id: 4, score: 80, leave: 0
id: 2, score: 70, leave: 1
id: 3, score: 29, leave: 1

1-1-2
1-2-2
2-1-5
2-2-1
2-3-4

average: 61
```

<!-- slide -->
### 題目3 - 框架

``` C
#include <stdio.h>
#include <stdlib.h>

void printAllStdent(struct Class* myClass, int classSize) {
}

void printClassTopThree(struct Class* myClass, int classSize) {
}

void printSchoolTopThree(struct Class* myClass, int classSize) {
}

void printAllStdentByClassAndScore(struct Class* myClass, int classSize) {
}

void printFullAttendance(struct Class* myClass, int classSize) {
}

void printSchoolAverageScore(struct Class* myClass, int classSize) {
}

int main() {

	while (1) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			printAllStdent(myClass, n);
		}
		else if (cmd == 2) {
			printClassTopThree(myClass, n);
		}
		else if (cmd == 3) {
			printSchoolTopThree(myClass, n);
		}
		else if (cmd == 4) {
			printAllStdentByClassAndScore(myClass, n);
		}
		else if (cmd == 5) {
			printFullAttendance(myClass, n);
		}
		else if (cmd == 6) {
			printSchoolAverageScore(myClass, n);
		}
	}
}
```

<!-- slid
### 題目3 - 圖解 -->

<!-- slide -->
### 題目3 - 程式碼

``` C
#include <stdio.h>
#include <stdlib.h>

struct St {
	int id;
	int score;
	int leave;
};

struct Class {
	struct St* st;
	int stSize;
	int grade;
	int number;
};

void printAllStdent(struct Class* myClass, int classSize) {
	for (int i = 0; i < classSize; i++) {
		printf("%d-%d\n", myClass[i].grade, myClass[i].number);
		for (int j = 0; j < myClass[i].stSize; j++) {
			printf("id: %d, score: %d, leave: %d\n", myClass[i].st[j].id, myClass[i].st[j].score, myClass[i].st[j].leave);
		}
		printf("\n");
	}
}

void printClassTopThree(struct Class* myClass, int classSize) {
	for (int i = 0; i < classSize; i++) {
		printf("%d-%d\n", myClass[i].grade, myClass[i].number);
		struct St* topThree[3] = {};
		for (int j = 0; j < myClass[i].stSize; j++) {
			for (int k = 0; k < 3; k++) {
				if (!topThree[k]) {
					topThree[k] = myClass[i].st + j;
					break;
				}
				else if (myClass[i].st[j].score > topThree[k]->score) {
					for (int l = 2; l >= k; l--) 
            topThree[l + 1] = topThree[l];
					topThree[k] = myClass[i].st + j;
					break;
				}
			}
		}
		for (int j = 0; j < 3 && topThree[j]; j++) {
			printf("id: %d, score: %d, leave: %d\n", topThree[j]->id, topThree[j]->score, topThree[j]->leave);
		}
		printf("\n");
	}
}

void printSchoolTopThree(struct Class* myClass, int classSize) {
  struct St* topThree[3] = {};
  for (int i = 0; i < classSize; i++) {
		for (int j = 0; j < myClass[i].stSize; j++) {
			for (int k = 0; k < 3; k++) {
				if (!topThree[k]) {
					topThree[k] = myClass[i].st + j;
					break;
				}
				else if (myClass[i].st[j].score > topThree[k]->score) {
					for (int l = 2; l >= k; l--) 
            topThree[l + 1] = topThree[l];
					topThree[k] = myClass[i].st + j;
					break;
				}
			}
		}
	}
  for (int i = 0; i < 3 && topThree[i]; i++) {
    printf("id: %d, score: %d, leave: %d\n", topThree[i]->id, topThree[i]->score, topThree[i]->leave);
  }
  printf("\n");
}

void printAllStdentByClassAndScore(struct Class* myClass, int classSize) {
  for (int i = 0; i < classSize; i++) {
		printf("%d-%d\n", myClass[i].grade, myClass[i].number);
		struct St** sortSt = calloc(myClass[i].stSize, sizeof(struct St*));
    for (int j = 0; j < myClass[i].stSize; j++) sortSt[j] = myClass[i].st + j;
		for (int j = 0; j < myClass[i].stSize; j++) {
      int maxScore = 0, maxIndex;
			for (int k = j; k < myClass[i].stSize; k++) {
				if (myClass[i].st[k].score > maxScore) {
					maxScore = myClass[i].st[k].score;
          maxIndex = k;
				}
			}
      struct St* tmpSt = sortSt[maxIndex];
      sortSt[maxIndex] = sortSt[j];
      sortSt[j] = tmpSt;
		}
		for (int j = 0; j < myClass[i].stSize; j++) {
			printf("id: %d, score: %d, leave: %d\n", sortSt[j]->id, sortSt[j]->score, sortSt[j]->leave);
		}
		printf("\n");
	}
}

void printFullAttendance(struct Class* myClass, int classSize) {
  for (int i = 0; i < classSize; i++) {
		for (int j = 0; j < myClass[i].stSize; j++) {
			if(myClass[i].st[j].leave == 0)
        printf("%d-%d-%d\n", myClass[i].grade, myClass[i].number, myClass[i].st[j].id);
    }
	}
  printf("\n");
}

void printSchoolAverageScore(struct Class* myClass, int classSize) {
  int sum = 0;
  int count = 0;
  for (int i = 0; i < classSize; i++) {
		for (int j = 0; j < myClass[i].stSize; j++) {
			sum += myClass[i].st[j].score;
      count ++;
    }
	}
  printf("average: %d\n", sum / count);
}

int main() {
	struct Class* myClass;
	int n;
	scanf("%d", &n);
	myClass = (struct Class*)malloc(sizeof(struct Class) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &myClass[i].stSize, &myClass[i].grade, &myClass[i].number);
		myClass[i].st = (struct St*)malloc(sizeof(struct St) * myClass[i].stSize);
		for (int j = 0; j < myClass[i].stSize; j++) {
			scanf("%d%d%d", &myClass[i].st[j].id, &myClass[i].st[j].score, &myClass[i].st[j].leave);
		}
	}

	while (1) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			printAllStdent(myClass, n);
		}
		else if (cmd == 2) {
			printClassTopThree(myClass, n);
		}
		else if (cmd == 3) {
			printSchoolTopThree(myClass, n);
		}
		else if (cmd == 4) {
			printAllStdentByClassAndScore(myClass, n);
		}
		else if (cmd == 5) {
			printFullAttendance(myClass, n);
		}
		else if (cmd == 6) {
			printSchoolAverageScore(myClass, n);
		}
	}
}
```


<!-- slide -->
## union

<!-- slide -->
### 如果一個資料用structure時

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
### 如果改為union表示時

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
### size的差別 - 程式碼

``` C
union UData{
  int numInt;
  double numDouble;
  float numFloat;
  long long numLongLong;
};
struct SData{
  int numInt;
  double numDouble;
  float numFloat;
  long long numLongLong;
};
int main(){
  printf("union size: %d\n", sizeof(union UData));
  printf("struct size: %d\n", sizeof(struct SData));
}
```

<!-- slide -->
### size的差別 - output

``` text

> union size: 8
> struct size: 32
```

<!-- slide -->
### union的程式範例

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

<!-- slide -->
### enum-例子

``` C
#define MON 1
#define TUES 2
#define WED 3
#define THUR 4
#define FRI 5
#define SAT 6
#define SUN 7
```

<!-- slide -->
``` C
enum Week{MON = 1, TUES, WED,THUR,FRI,SAT,SUN };
```

<!-- slide -->
``` C
enum Week{MON = 1, TUES, WED, THUR, FRI, SAT, SUN };

int main(){
  for(enum Week i = MON; i <= SUN; i++){
    printf("week: %d\n", i);
  }
}
```

``` output
week: 1
week: 2
week: 3
week: 4
week: 5
week: 6
week: 7
```

<!-- slide -->
如果不給值得話就是從0開始

``` C
enum Week{MON, TUES, WED, THUR, FRI, SAT, SUN };

int main(){
  for(enum Week i = MON; i <= SUN; i++){
    printf("week: %d\n", i);
  }
}
```

``` output
week: 0
week: 1
week: 2
week: 3
week: 4
week: 5
week: 6
```

<!-- slide -->
### enum用途

讓程式看起來比較容易懂

<!-- slide -->
## 題目5

請將題目4的type的部分改用enum實作

<!-- slide -->
### 題目5 - 程式碼

``` C
#include <stdio.h>
#include <stdlib.h>

enum Type{
  INT_TYPE,
  DOUBLE_TYPE,
  FLOAT_TYPE,
  LONGLONG_TYPE,
  CHAR_TYPE
};

union Data{
  int _int;
  double _double;
  float _float;
  long long _llong;
  char _char;
};

typedef struct SData{
  union Data data;
  enum Type type;
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

## 關於判斷相等與assign

* 判斷相等是不行的
* 但assign是可以的
  * 只是指標與array只是複製address，跟function一樣
