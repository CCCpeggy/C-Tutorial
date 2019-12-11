<!-- slide -->
# linked list

<!-- slide vertical=true -->
``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
+----+----+
| 11 |0x06|
+----+----+
 0x01
+----+----+
| 13 |0x04|
+----+----+
 0x02
+----+----+
| 15 |0x05|
+----+----+
 0x03
+----+----+
| 14 |0x03|
+----+----+
 0x04
+----+----+
| 16 |null|
+----+----+
 0x05
+----+----+
| 12 |0x02|
+----+----+
 0x06
```

<!-- slide vertical=true -->
``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
+--+---+  +--+---+  +--+---+  +--+---+  +--+---+  +--+---+
|11| *-+->|12| *-+->|13| *-+->|14| *-+->|15| *-+->|16|   |
+--+---+  +--+---+  +--+---+  +--+---+  +--+---+  +--+---+
```

<!-- slide -->
## 印出


<!-- slide vertical=true -->
印出裡面所有node的值


``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
### 印出 - 思路

* 將List從頭到尾跑一遍
* 可以用一個指標從頭到尾都指一遍
* 每一次要換下一個時，將自己指向目前指向的下一個的值

<!-- slide vertical=true -->

* 將List從頭到尾跑一遍

> for or while

* 可以用一個指標從頭到尾都指一遍

> Node* current

* 每一次要換下一個時，將自己指向目前指向的下一個的值

> current -> next的值給current

<!-- slide vertical=true -->
### 印出 - 圖解

<!-- slide vertical=true -->
印出這個list的所有值

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
``` C
current = head;
printf("%d ", current -> num);
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

  ^
  |
+-+----+
| 0x01 |
+------+
 current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
printf("%d ", current -> num);
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

               ^
               |
             +-+----+
             | 0x02 |
             +------+
              current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
printf("%d ", current -> num);
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

                            ^
                            |
                          +-+----+
                          | 0x03 |
                          +------+
                           current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
printf("%d ", current -> num);
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

                                         ^
                                         |
                                       +-+----+
                                       | 0x04 | 
                                       +------+
                                        current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
if (!current) break;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

                                       +-----+
                                       |     |
                                       +-----+
                                       current
```

<!-- slide -->
## 實作練習

請實作一些功能來維護一個list，
在這邊先完成當中的`印出`功能

<!-- slide vertical=true -->
### 實作框架

``` C
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int num;
  struct Node* next;
} Node;

Node * initList();

void print(Node* head){
}

void insert(Node* head, int forwardValue, int newValue){
}

Node* insertHead(Node* head, int value){
  retunn head;
}

Node* delete(Node* head, int value){
  retunn head;
}

void update(Node* head, int oldValue, int newValue){
}

int main(){
  Node *head = initList();
  printf("original: ");
  print(head);
  insert(head, 12, 13);
  printf("insert 13: ");
  print(head);
  insert(head, 15, 16);
  printf("insert 16: ");
  print(head);
  head = insertHead(head, 10);
  printf("insert 10: ");
  print(head);
  head = delete(head, 12);
  printf("delete 12: ");
  print(head);
  head = delete(head, 10);
  printf("delete 10: ");
  print(head);
  update(head, 11, 12);
  printf("update 11 -> 12: ");
  print(head);
}

Node * initList(){/*ZXCVBNVHG︿ＵＦ<FYGUHIM<FYGUHIJKL<YGUHJKM<MNVGCFDTFY@#$%^&*(*&^%^&VHGJＧＧＦ<FYGUHIJKL<YGUHJKM<MNVGCFDTFY@#$%^&ＹＦＹＦＤＢＪＢＤＪＮＬＫＮＬ？Ｍ？Ｋ？*/Node *head = (Node*) malloc(sizeof(Node));Node *current = head;current->num = 11; current->next = (Node*) malloc(sizeof(Node));current = current->next;current->num = 12; current->next = (Node*) malloc(sizeof(Node));current = current->next;current->num = 14; current->next = (Node*) malloc(sizeof(Node));current = current->next;current->num = 15; current->next = NULL;return head;}
```

<!-- slide vertical=true -->
### 印出 - 實作程式碼

``` C
void print(Node* head){
  for(Node* current = head; current; current = current -> next){
    printf("%d ", current -> num);
  }
  printf("\n");
}
```

<!-- slide -->
## 修正

<!-- slide vertical=true -->
修改已存在List中的某個node中的資料
例如將14改為13

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
### 修正 - 思路

* 從list的頭開始一個個找特定的node
* 將特定的node的值改掉

<!-- slide vertical=true -->
* 從list的頭開始一個個找特定的node

> for or while + 比對current的num值)

* 將特定的node的值改掉

> current的num改為新的值

<!-- slide vertical=true -->
### 修正 - 圖解

將14改為13

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
``` C
current = head;
if (current -> num == 14) // 不成立
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

  ^
  |
+-+----+
| 0x01 |
+------+
 current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
if (current -> num == 14) // 不成立
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

               ^
               |
             +-+----+
             | 0x02 |
             +------+
              current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
if (current -> num == 14) // 成立
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

                            ^
                            |
                          +-+----+
                          | 0x03 |
                          +------+
                           current
```

<!-- slide vertical=true -->
``` C
current -> num = 13;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 13 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

                            ^
                            |
                          +-+----+
                          | 0x03 |
                          +------+
                           current
```

<!-- slide vertical=true -->
### 修正 - 實作練習

<!-- slide vertical=true -->
### 修正 - 程式碼

``` C
void update(Node* head, int oldValue, int newValue){
  Node* current;
  for(current = head; current->num != oldValue; current = current -> next){}
  current -> num = newValue;
}
```

<!-- slide -->
## 新增

<!-- slide vertical=true -->
在其中兩個node中間插入新的node
例如在12與14中間插入13

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
## 新增 - 思路

* 找到被插入的前面那個node
* 創造新node
* 被插入前面的node的下一個成為新node的下一個
* 被插入前面的node的下一個為新的node

<!-- slide vertical=true -->
### 新增 - 圖解

在12後面插入13

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
先找到12的node

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
``` C
current = head;
if (current -> num == 12) // 不成立
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

  ^
  |
+-+----+
| 0x01 |
+------+
 current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
if (current -> num == 12) // 成立
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

               ^
               |
             +-+----+
             | 0x02 |
             +------+
              current
```

<!-- slide vertical=true -->
create 13 的 node

``` C
Node *newNode = (Node*) malloc(sizeof(Node));
newNode -> num = 13;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+       +----+----+
|0x01|       | 13 |    +
+-+--+       +----+----+
  |           0x05
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

               ^
               |
             +-+----+
             | 0x02 |
             +------+
              current
```

<!-- slide vertical=true -->
``` C
newNode -> next = current -> next;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head        newNode
+----+       +----+----+
|0x01|       | 13 |0x03+----+
+-+--+       +----+----+    |
  |           0x05          |
  v                         v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

               ^
               |
             +-+----+
             | 0x02 |
             +------+
              current
```

<!-- slide vertical=true -->

``` C
current -> next = newNode;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head        newNode
+----+       +----+----+
|0x01|    +->| 13 |0x03+----+
+-+--+    |  +----+----+    |
  |       |   0x05          |
  |       +---------+       |
  v                 |       v
+----+----+  +----+-+--+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x05+  | 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

               ^
               |
             +-+----+
             | 0x02 |
             +------+
              current
```

<!-- slide vertical=true -->

相當於

``` C
current -> next = newNode;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+-+--+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x05+->| 13 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x05         0x03         0x04
```
<!-- slide vertical=true -->
### 新增 - 實作練習

<!-- slide vertical=true -->
### 新增 - 程式碼

``` C
void insert(Node* head, int forwardValue, int newValue){
  Node* current;
  for(current = head; current && current->num != forwardValue; current = current -> next){}
  Node * newNode = (Node*) malloc(sizeof(Node));
  newNode -> next = current -> next;
  newNode -> num = newValue;
  current -> next = newNode;
}
```

<!-- slide -->
## 新增在最前面

<!-- slide vertical=true -->
插入node在最前面
例如在最前面插入node 10

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
### 新增在最前面 - 思路

* 新node的next指向目前的head
* head改為新的node

<!-- slide vertical=true -->
在最前面插入node 10

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
create 10

``` C
Node *newNode = (Node*) malloc(sizeof(Node));
newNode -> num = 10;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head        newNode
+----+       +----+----+
|0x01|       | 10 |    |
+-+--+       +----+-+--+
  |           0x05
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
``` C
newNode -> next = head;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head        newNode
+----+       +----+----+
|0x01|       | 10 |0x01|
+-+--+       +----+-+--+
  |           0x05  |
  | +---------------+
  | |
  v v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
``` C
head = newNode;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head        newNode
+----+       +----+----+
|0x05+------>| 10 |0x01|
+-+--+       +----+-+--+
              0x05  |
   +----------------+
   |
   v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
相當於

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+  +----+----+
| 10 |0x01+->| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+  +----+----+
 0x05         0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
### 新增在最前面 - 實作練習

<!-- slide vertical=true -->
### 新增在最前面 - 程式碼

``` C
Node* insertHead(Node* head, int value){
  Node * newNode = (Node*) malloc(sizeof(Node));
  newNode -> next = head;
  newNode -> num = value;
  return newNode;
}
```

<!-- slide -->
## 刪除

<!-- slide vertical=true -->
刪除某個node
例如刪除14

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
### 刪除 - 思路

* 找到前一個位置
* 將前一個node的next指向node的next的next

<!-- slide vertical=true -->
刪除14

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
先找到14`前面`的node

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
``` C
current = head;
if (current -> next -> num == 14) // 不成立
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

  ^
  |
+-+----+
| 0x01 |
+------+
 current
```

<!-- slide vertical=true -->
``` C
current = current -> next;
if (current -> next -> num == 14) // 成立
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04

               ^
               |
             +-+----+
             | 0x02 |
             +------+
              current
```

<!-- slide vertical=true -->
將current的next指向current的next的next

``` C
Node *newNode = (Node*) malloc(sizeof(Node));
newNode -> next = newNode -> next -> next;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head 
+----+
|0x01|
+-+--+
  |                  +-------------------+
  |                  |                   |
  v                  |                   v
+----+----+  +----+--+-+ +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+ | 14 |0x04+->| 15 |    |
+----+----+  +----+----+ +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
相當於

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+--+-+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 15 |    |
+----+----+  +----+----+  +----+----+
 0x01         0x02          0x04
```

<!-- slide -->
## 刪除最面的node

<!-- slide vertical=true -->
刪除11

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
### 刪除最面的node - 思路

* 將head指向下一個node

<!-- slide vertical=true -->
刪除11

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
``` C
head = head -> next;
```

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x02+---------+
+-+--+         |
               v
+----+----+  +----+----+  +----+----+  +----+----+
| 11 |0x02+->| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+  +----+----+
 0x01         0x02         0x03         0x04
```

<!-- slide vertical=true -->
相當於

``` ditaa {cmd=true args=["-E", "-S", "-t", "1", "-s", "1"]}
 head
+----+
|0x01|
+-+--+
  |
  v
+----+----+  +----+----+  +----+----+
| 12 |0x03+->| 14 |0x04+->| 15 |    |
+----+----+  +----+----+  +----+----+
 0x02         0x03         0x04
```

<!-- slide vertical=true -->
請思考如果是刪除最後面的node
要如何實作

<!-- slide vertical=true -->
## 刪除 - 實作時間
<!-- slide vertical=true -->

## 刪除 - 程式碼

``` C
Node* delete(Node* head, int value){
  if(head -> num == value) return head -> next;
  Node* current;
  for(current = head; current->next->num != value; current = current -> next){}
  current -> next = current -> next -> next;
  return head;
}
```

<!-- slide -->
## output

``` text
original: 11 12 14 15
insert 13: 11 12 13 14 15
insert 16: 11 12 13 14 15 16
insert 10: 10 11 12 13 14 15 16
delete 12: 10 11 13 14 15 16
delete 10: 11 13 14 15 16
update 11 -> 12: 12 13 14 15 16
```