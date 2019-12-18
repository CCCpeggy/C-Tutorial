<!-- slide -->
# stack and queue

<!-- slide vertical -->
* stack - 先進後出
  * 例如：蝶盤子
* queue - 先進先出
  * 例如：排隊

<!-- slide vertical -->
## 實現方式

* array
* linked list

<!-- slide -->
## stack - array

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
stack[12]
+---+---+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
push 9
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 8
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 3
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 | 3 |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 5
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 | 3 | 5 |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
pop
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 | 3 |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
pop 
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 1
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 | 1 |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
```

<!-- slide vertical -->
### stack - array 優點

* 實作簡單
* 好取得特定位置的值

### stack - array 缺點

* 數量受限制

<!-- slide vertical -->
### stack - array 實作練習

<!-- slide vertical -->
#### stack - array 框架

``` C
#include <stdio.h>

void push(int num){
}

void pop(){
}

void print(){
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```

<!-- slide vertical -->
#### stack - array 輸出結果

``` text
9 
9 8 
9 8 3 
9 8 3 5 
9 8 3 
9 8 
9 8 1
```

<!-- slide vertical -->
#### stack - array 程式碼

``` C
#include <stdio.h>

int stack[12];
int size=0;

void push(int num){
  if(size < 12) stack[size++] = num;
}

void pop(){
  if(size > 0) size--;
}

void print(){
  for(int i = 0; i < size; i++) printf("%d ", stack[i]);
  printf("\n");
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```

<!-- slide -->
## stack - linked list

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+
head |   |
     +---+

push9
     +---+  +---+---+
head |   +->| 9 |   +
     +---+  +---+---+
     
push8
     +---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +
     +---+  +---+---+  +---+---+

push3
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+

push5
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+

pop
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+

pop
     +---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +
     +---+  +---+---+  +---+---+
    
push1
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 1 |   +
     +---+  +---+---+  +---+---+  +---+---+
```

<!-- slide vertical -->
### stack - linked list - push

push 5

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+
```

<!-- slide vertical -->
讓cur指到最後一個Node的next

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+
       ^
       |
     +-+-+
 cur |   |
     +---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+
                  ^
                  |
                +-+-+
            cur |   |
                +---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+
                             ^
                             |
                           +-+-+
                       cur |   |
                           +---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+
                                        ^
                                        |
                                      +-+-+
                                  cur |   |
                                      +---+
```


<!-- slide vertical -->
讓cur指向的pointer，指向新的node

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->|   |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
                                        ^
                                        |
                                      +-+-+
                                  cur |   |
                                      +---+
```

<!-- slide vertical -->
賦值給新node

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
                                        ^
                                        |
                                      +-+-+
                                  cur |   |
                                      +---+
```

<!-- slide vertical -->
``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
```

<!-- slide vertical -->
### stack - linked list - pop

pop

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
```

<!-- slide vertical -->
讓cur指到倒數第二個Node的next

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
       ^
       |
     +-+-+
 cur |   |
     +---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
                  ^
                  |
                +-+-+
            cur |   |
                +---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
                             ^
                             |
                           +-+-+
                       cur |   |
                           +---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
                                        ^
                                        |
                                      +-+-+
                                  cur |   |
                                      +---+
```

<!-- slide vertical -->
讓cur指向的pointer，指向NULL

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+
                                        ^
                                        |
                                      +-+-+
                                  cur |   |
                                      +---+
```

<!-- slide vertical -->
### stack - linked list 優點

* 數量不受限制

### stack - linked list 缺點

* 執行的指令較多
* 不好取得特定位置的值

<!-- slide vertical -->
### stack - linked list 實作練習

<!-- slide vertical -->
#### stack - linked list 框架

``` C
#include <stdio.h>

void push(int num){
}

void pop(){
}

void print(){
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```

<!-- slide vertical -->
#### stack - linked list 輸出結果

``` text
9 
9 8 
9 8 3 
9 8 3 5 
9 8 3 
9 8 
9 8 1
```

<!-- slide vertical -->
#### stack - linked list 程式碼

``` C
#include <stdio.h>
#include <stdlib.h>

struct Node{
  int num;
  struct Node* next;
};

struct Node* head=NULL;
int size=0;

void push(int num){
  struct Node** cur = &head;
  for (int i = 0; i < size; i++) cur = &((*cur) -> next);
  *cur = (struct Node*)malloc(sizeof(struct Node));
  (*cur) -> num = num;
  (*cur) -> next = NULL;
  size++;
}

void pop(){
  if(size > 0) {
    size--;
    struct Node** cur = &head;
    for (int i = 0; i < size; i++) cur = &((*cur) -> next);
    *cur = NULL;
  }
}

void print(){
  struct Node* cur = head;
  for(int i = 0; i < size; i++) {
    printf("%d ", cur -> num);
    cur = cur -> next;
  }
  printf("\n");
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```


<!-- slide -->

## queue - array

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "2"]}
queue[12]
+---+---+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
push 9
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 8
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 3
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 | 3 |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 5
+---+---+---+---+---+---+---+---+---+---+---+---+
| 9 | 8 | 3 | 5 |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
pop
+---+---+---+---+---+---+---+---+---+---+---+---+
| 8 | 3 | 5 |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
pop 
+---+---+---+---+---+---+---+---+---+---+---+---+
| 3 | 5 |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
push 1
+---+---+---+---+---+---+---+---+---+---+---+---+
| 3 | 5 | 1 |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+
```

<!-- slide vertical -->
### queue - array 優點

* 實作簡單

### queue - array 缺點

* 數量受限制
* 每一次pop要移動array的所有的值

<!-- slide vertical -->
### queue - array 實作練習

<!-- slide vertical -->
#### queue - array 框架

``` C
#include <stdio.h>

void push(int num){
}

void pop(){
}

void print(){
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```

<!-- slide vertical -->
#### queue - array 輸出結果

``` text
9 
9 8 
9 8 3 
9 8 3 5 
8 3 5 
3 5 
3 5 1 
```

<!-- slide vertical -->
#### queue - array 程式碼

``` C
#include <stdio.h>
#include <stdlib.h>

int queue[12];
int size = 0;

void push(int num){
  if(size < 12) queue[size++] = num;
}

void pop(){
  if(size > 0) {
    for(int i = 1; i < size; i++) queue[i - 1] = queue[i];
    size--;
  }
}

void print(){
  for(int i = 0; i < size; i++) printf("%d ", queue[i]);
  printf("\n");
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```

<!-- slide -->

## queue - linked list

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+
head |   |
     +---+

push9
     +---+  +---+---+
head |   +->| 9 |   +
     +---+  +---+---+
     
push8
     +---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +
     +---+  +---+---+  +---+---+

push3
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +
     +---+  +---+---+  +---+---+  +---+---+

push5
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+

pop
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+

pop
     +---+  +---+---+  +---+---+
head |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+
    
push1
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 3 |   +->| 5 |   +->| 1 |   +
     +---+  +---+---+  +---+---+  +---+---+
```

<!-- slide vertical -->
### queue - linked list - push

跟stack一樣

<!-- slide vertical -->
### queue - linked list - pop

pop

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +->| 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
```

<!-- slide vertical -->

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+  +---+---+
head |   +  | 9 |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +-+-+  +---+---+  +---+---+  +---+---+  +---+---+
       |                     ^
       |                     |
       +---------------------+
```

<!-- slide vertical -->
相當於

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1.5"]}
     +---+  +---+---+  +---+---+  +---+---+
head |   +->| 8 |   +->| 3 |   +->| 5 |   +
     +-+-+  +---+---+  +---+---+  +---+---+
```

<!-- slide vertical -->
### queue - linked list 優點

* 數量不受限制
* pop不用整個移動

### queue - linked list 缺點

* 不好取得特定位置的值

<!-- slide vertical -->
### queue - linked list 實作練習

<!-- slide vertical -->
#### queue - linked list 框架

``` C
#include <stdio.h>

void push(int num){
}

void pop(){
}

void print(){
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```

<!-- slide vertical -->
#### queue - linked list 輸出結果

``` text
9 
9 8 
9 8 3 
9 8 3 5 
8 3 5 
3 5 
3 5 1 
```

<!-- slide vertical -->
#### queue - linked list 程式碼

``` C

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int num;
  struct Node* next;
};

struct Node* head=NULL;
int size=0;

void push(int num){
  struct Node** cur = &head;
  for (int i = 0; i < size; i++) cur = &((*cur) -> next);
  *cur = (struct Node*)malloc(sizeof(struct Node));
  (*cur) -> num = num;
  (*cur) -> next = NULL;
  size++;
}

void pop(){
  if(size > 0) {
    size--;
    head = head->next;
  }
}

void print(){
  struct Node* cur = head;
  for(int i = 0; i < size; i++) {
    printf("%d ", cur -> num);
    cur = cur -> next;
  }
  printf("\n");
}

int main(){
  push(9);
  print();
  push(8);
  print();
  push(3);
  print();
  push(5);
  print();
  pop();
  print();
  pop();
  print();
  push(1);
  print();
}
```
