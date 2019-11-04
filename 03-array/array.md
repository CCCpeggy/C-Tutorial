# array

## 一維陣列

|1|2|3|4|5|6|7|8|
|---|---|---|---|---|---|---|---|

## 二維陣列

|→ column|||||||||
|---|---|---|---|---|---|---|---|---|
|row↓|1|2|3|4|5|6|7|8|
|^|2|3|4|5|6|7|8|9|
|^|3|4|5|6|7|8|9|0|

## insert

|1|2|4|5|6|7|-|-|
|---|---|---|---|---|---|---|---|

add 9

|1|2|4|5|6|7|9|-|
|---|---|---|---|---|---|---|---|

add 3(?)

|1|2|-|4|5|6|7|9|
|---|---|---|---|---|---|---|---|

|1|2|3|4|5|6|7|9|
|---|---|---|---|---|---|---|---|

## update

|1|2|4|5|6|7|-|-|
|---|---|---|---|---|---|---|---|

update 3->4

|1|2|3|5|6|7|9|-|
|---|---|---|---|---|---|---|---|

## delete

|1|2|3|4|5|6|7|8|
|---|---|---|---|---|---|---|---|

delete 3

|1|2|-|4|5|6|7|8|
|---|---|---|---|---|---|---|---|

|1|2|4|5|6|7|8|-|
|---|---|---|---|---|---|---|---|


## 題目

### 學生餐廳點餐（array的新增、刪除、印出）

學生餐廳通常價錢較便宜，所以一到下課時間就很多人來買，不過因為人力限制，最多未出訂單最多只有100份。每個人都有自己的編號，每天的編號都會重1開始，然後流水號下去，一天的客人不會超過2147483647人。店家一忙不過來的時候，會不知道還剩下多少客人，請你幫店家還沒出餐的客人編號，並且依點餐順序輸出

#### Input

會先有一個N代表後面會輸入幾筆資料，接著會有N筆店家的命令。每筆命令的開頭第一個數字是C，C=1代表多了一人點餐；C=2時會再接一個數字M，代表M編號的餐點已經完成；當C=3時，代表店家想知道目前的未出餐點的編號有哪些。

#### Output

確認訂單後輸出`[INSERT ORDER]`
刪除訂單後輸出`[DLETE ORDER]`
印出未出餐點的編號請以小到大用空白隔開印出

#### Sample

##### input

``` data = 1
13
1
1
1
1
1
1
1
1
1
2 5
2 3
2 2
3
```

##### output

``` data = 1
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[DELETE ORDER]
[DELETE ORDER]
[DELETE ORDER]
1 4 6 7 8 9

```

##### input（針對insert跟print）

``` data = 1
5
1
1
1
1
1
3
```

##### output

``` data = 1
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
[INSERT ORDER]
1 2 3 4 5

```

#### code

``` c = 1
#include <stdio.h>

int main(){
    int queue[100];
    int number = 1, N, size = 0;
    scanf("%d", &N);
    while(N--){
        int C;
        scanf("%d", &C);
        if(C==1){
            queue[size++] = number++;
            printf("[INSERT ORDER]\n");
        }
        else if(C==2){
            int delNum;
            scanf("%d", &delNum);
            for(int i = 0; i < size; i++){
                if(queue[i] == delNum){
                    for(int j = i+1; j < size; j++){
                        queue[j - 1] = queue[j];
                    }
                    size--;
                    break;
                }
            }
            printf("[DELETE ORDER]\n");
        }
        else if(C==3){
            for(int i = 0; i < size; i++){
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }
}
```



$x^2\delta\sigma\sum\sum\limits_{x=1}$