<!-- slide -->
# 泛型程式設計

<!-- slide vertical = true-->
無型別的程式，同一個演算法可以套用在不同型別上

<!-- slide vertical = true-->
## 實作方式

* void指標
* 巨集 (macro)
* _Generic 敘述 (C11)

<!-- slide vertical = true-->
## void指標

void指標可以指向任意型別的資料

<!-- slide vertical = true-->
``` C
int * pint;
void *pvoid;
pvoid = pint; 
```

<!-- slide vertical = true-->
如果要將void指標賦給其他型別指標
則需要強制型別轉換

``` C
pint=(int *)pvoid;
```

<!-- slide vertical = true-->
其實我們常見的malloc需要轉換就是這個概念

* 定義

    ``` C
    void *malloc(size_t size);
    ```

* 使用

    ``` C
    int *num = (int*) malloc(sizeof(int) * size);
    ```

<!-- slide vertical = true-->
### void的含義

* void的字面意思是`無型別`
* void*則為`無型別指標`

<!-- slide -->
## 題目1

寫一個函式，可以取得一個輸入值到指定的變數

<!-- slide vertical = true-->
### 題目1 - 輸入

``` text
10

```

### 題目1 - 輸出

``` text
10
```

<!-- slide vertical = true-->
### 題目1 - 框架

``` C
#include <stdio.h>

int main(void) {
  int a = 10;
  scanfCopy("%d", &a);
  printf("%d", a);

  return 0;
}
```

<!-- slide vertical = true-->
### 題目1 - 程式碼

``` C
#include <stdio.h>

int scanfCopy(char format[10], void* var){
  scanf(format, var);
}

int main(void) {
  int a = 10;
  scanfCopy("%d", &a);
  printf("%d", a);

  return 0;
}
```

<!-- slide -->
## 相關常用函式

<!-- slide -->
### memcpy

<!-- slide vertical = true-->
* string.h 的函數 memcpy() 類似 strncpy() ，
* 從某一記憶體區段拷貝 n 個字元到另一記憶體區段。
* 實際應用不限於copy字元，任何型態都行，代表copy n個位元組的資料到指定區段

``` C
void *memcpy(void* dest, const void *src, size_t n);
```

<!-- slide vertical = true-->

* dest: 目的位置的指標
* src:  來源位置的指標
* n: 要複製的位元數
* 回傳目的位置的指標

<!-- slide vertical = true-->
#### memcpy - 範例

``` C
#include<stdio.h>
#include<string.h>

int main()
{
　　char *s = "abcd";
　　char d[20];
　　memcpy(d, s, strlen(s));
　　d[strlen(s)]='\0';
　　printf("%s",d);
　　return 0;
}
```

<!-- slide vertical = true-->
#### memcpy - 範例圖解

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+---+---+---+---+---+
| a | b | c | d |   |
+---+---+---+---+---+
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+---+---+---+---+---+
| a | b | c | d |   |
+---+---+---+---+---+

+---+---+---+---+---+
| a | b | c | d | X |
+---+---+---+---+---+
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+---+---+---+---+---+
| a | b | c | d |   |
+---+---+---+---+---+

+---+---+---+---+---+
| a | b | c | d |   |
+---+---+---+---+---+
```

<!-- slide -->
### memset

<!-- slide vertical = true-->
* string.h 的函數 memset()
* 從某一記憶體區段每一位元填入特定的值

<!-- slide vertical = true-->
``` C
void *memset(void *str, int c, size_t n);
```

* str: 指向這是要填充的區域的指標
* c: 要填充的值
* n: 要填充的位元數

<!-- slide vertical = true-->
#### memset - 範例

``` C
#include <stdio.h>
#include <string.h>

int main()
{
  char str[40] = "Merry Christmas";
  printf("%s\n", str);
  memset(str + 3, '$', 7);
  printf("%s\n", str);
  return(0);
}
```

<!-- slide vertical = true-->
#### memset - 範例輸出

``` text
Merry Christmas
Mer$$$$$$$stmas
```

<!-- slide -->
## 題目2

寫一個函示，交換兩個相同型態變數的值

<!-- slide vertical = true-->

### 題目2 - 輸出

``` text
befoe: a = 10, b = 20
after: a = 20, b = 10
befoe: c = 10, c = 20
after: c = 20, d = 10
befoe: e = abc, f = efg
after: e = efg, f = abc
```

<!-- slide vertical = true-->
### 題目2 - 框架

``` C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int a = 10, b = 20;
  printf("befoe: a = %d, b = %d\n", a, b);
  swap(&a, &b, sizeof(int));
  printf("after: a = %d, b = %d\n", a, b);

  char c = 10, d = 20;
  printf("befoe: c = %d, c = %d\n", c, d);
  swap(&c, &d, sizeof(char));
  printf("after: c = %d, d = %d\n", c, d);

  char e[10] = "abc", f[10] = "efg";
  printf("befoe: e = %s, f = %s\n", e, f);
  swap(e, f, 4);
  printf("after: e = %s, f = %s\n", e, f);
  return(0);
}
```

<!-- slide vertical = true-->
### 題目2 - 圖解

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+---+---+---+---+---+---+---+---+---+---+
| a | b | c |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

+---+---+---+---+---+---+---+---+---+---+
| e | g | f |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+---+---+---+---+---+---+---+---+---+---+
| a | b | c |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

+---+---+---+---+---+---+---+---+---+---+
| e | g | f |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

+---+---+---+---+---+---+---+---+---+---+
| a | b | c |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
```

<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+---+---+---+---+---+---+---+---+---+---+
| e | g | f |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

+---+---+---+---+---+---+---+---+---+---+
| e | g | f |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

+---+---+---+---+---+---+---+---+---+---+
| a | b | c |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
```


<!-- slide vertical = true-->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
+---+---+---+---+---+---+---+---+---+---+
| e | g | f |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

+---+---+---+---+---+---+---+---+---+---+
| a | b | c |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

+---+---+---+---+---+---+---+---+---+---+
| a | b | c |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
```

<!-- slide vertical = true-->
### 題目2 - 程式碼

``` C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void* var1, void* var2, int typeSize){
  void *tmp = malloc(typeSize);
  memcpy(tmp, var1, typeSize);
  memcpy(var1, var2, typeSize);
  memcpy(var2, tmp, typeSize);
}

int main()
{
  int a = 10, b = 20;
  printf("befoe: a = %d, b = %d\n", a, b);
  swap(&a, &b, sizeof(int));
  printf("after: a = %d, b = %d\n", a, b);

  char c = 10, d = 20;
  printf("befoe: c = %d, c = %d\n", c, d);
  swap(&c, &d, sizeof(char));
  printf("after: c = %d, d = %d\n", c, d);

  char e[10] = "abc", f[10] = "efg";
  printf("befoe: e = %s, f = %s\n", e, f);
  swap(e, f, 4);
  printf("after: e = %s, f = %s\n", e, f);
  return(0);
}
```
