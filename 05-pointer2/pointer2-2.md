<!-- slide -->
# pointer3

<!-- slide -->
## 陣列 vs 指標 2

<!-- slide -->
舉個例子

``` C
int arr[] = {0, 1, 2, 3, 4};
int *ptr;
```

```ditaa {cmd=true args=["-E"]}
+-----+-----+-----+-----+-----+
|  0  |  1  |  2  |  3  |  4  |
+-----+-----+-----+-----+-----+
  0x00  0x04  0x08  0x0c  0x10

                ^
     +------+   |
 ptr | 0x08 +---+
     +------+
```

<!-- slide -->
``` C
int *ptr[4];
```

```ditaa {cmd=true args=["-E"]}
    +------+------+------+------+
ptr | 0x10 | 0x7c | 0x50 | 0x88 |
    +------+------+------+------+
      0x00   0x04   0x08   0x0c
        |      |     |       |         +-----+-----+-----+-----+-----+
        |      |     |       +-------> |  5  |  1  |  1  |  3  |  4  |
        |      |     |                 +-----+-----+-----+-----+-----+
        |      |     |                   0x88  0x8c  0x90  0x94  0x98
        |      |     |                 +-----+
        |      |     +---------------> |  2  |
        |      |                       +-----+
        |      |                         0x50
        |      |                       +-----+-----+-----+
        |      +---------------------> |  9  |  2  |  2  |
        |                              +-----+-----+-----+
        |                                0x7c  0x80  0x84
        |                              +-----+-----+-----+-----+
        +----------------------------> |  2  |  1  |  2  |  3  |
                                       +-----+-----+-----+-----+
                                         0x10  0x14  0x18  0x1c
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
      ptr[0]  ptr[1]  ptr[2]  ptr[3]
    +-------+-------+-------+-------+
ptr |  0x10 |  0x7c |  0x50 |  0x88 |
    +-------+-------+-------+-------+
       0x00    0x04    0x08    0x0c
        |       |       |        |         +-----+-----+-----+-----+-----+
        |       |       |        +-------> |  5  |  1  |  1  |  3  |  4  |
        |       |       |                  +-----+-----+-----+-----+-----+
        |       |       |                    0x88  0x8c  0x90  0x94  0x98
        |       |       |                  +-----+
        |       |       +----------------> |  2  |
        |       |                          +-----+
        |       |                            0x50
        |       |                          +-----+-----+-----+
        |       +------------------------> |  9  |  2  |  2  |
        |                                  +-----+-----+-----+
        |                                    0x7c  0x80  0x84
        |                                  +-----+-----+-----+-----+
        +--------------------------------> |  2  |  1  |  2  |  3  |
                                           +-----+-----+-----+-----+
                                             0x10  0x14  0x18  0x1c
```

<!-- slide -->
```ditaa {cmd=true args=["-E"]}
     ptr+0  ptr+1  ptr+2  ptr+3
    +------+------+------+------+
ptr | 0x10 | 0x7c | 0x50 | 0x88 |
    +------+------+------+------+
      0x00   0x04   0x08   0x0c
       |      |      |       |         +-----+-----+-----+-----+-----+
       |      |      |       +-------> |  5  |  1  |  1  |  3  |  4  |
       |      |      |                 +-----+-----+-----+-----+-----+
       |      |      |                   0x88  0x8c  0x90  0x94  0x98
       |      |      |                 +-----+
       |      |      +---------------> |  2  |
       |      |                        +-----+
       |      |                          0x50
       |      |                        +-----+-----+-----+
       |      +----------------------> |  9  |  2  |  2  |
       |                               +-----+-----+-----+
       |                                 0x7c  0x80  0x84
       |                               +-----+-----+-----+-----+
       +-----------------------------> |  2  |  1  |  2  |  3  |
                                       +-----+-----+-----+-----+
                                         0x10  0x14  0x18  0x1c
```

<!-- slide -->
``` C
int *ptr[4];

int arr[5] = {5, 1, 1, 3, 4};
ptr[0] = arr;

int number = 2;
ptr[1] = &number;

ptr[2] = (int*)malloc(sizeof(int) * 3);
ptr[2][0] = 9; ptr[2][1] = 2; ptr[2][2] = 2;

ptr[3] = (int*)malloc(sizeof(int) * 4);
*(ptr[3] + 0) = 2; *(ptr[3] + 1) = 1;
*(ptr[3] + 2) = 2; *(ptr[3] + 3) = 3;
```

<!-- slide -->
``` C
int (*ptr)[4];
```

```ditaa {cmd=true args=["-E"]}
    +------+
ptr | 0x10 |
    +------+
      0x00  
        |         +-----+-----+-----+-----+
        +-------> |  5  |  0  |  1  |  3  |
                  +-----+-----+-----+-----+
                    0x10  0x14  0x18  0x1c
                  +-----+-----+-----+-----+
                  |  2  |  2  |  1  |  3  |
                  +-----+-----+-----+-----+
                    0x20  0x24  0x28  0x2c
                  +-----+-----+-----+-----+
                  |  9  |  1  |  3  |  0  |
                  +-----+-----+-----+-----+
                    0x30  0x34  0x38  0x3c
                  +-----+-----+-----+-----+
                  |  2  |  1  |  2  |  3  |
                  +-----+-----+-----+-----+
                    0x40  0x44  0x48  0x4c
```

<!-- slide -->

```ditaa {cmd=true args=["-E"]}
    +------+
ptr | 0x10 |
    +------+
      0x00  
        |         +-----+-----+-----+-----+
        +-------> |  5  |  0  |  1  |  3  |
                  +-----+-----+-----+-----+
                    0x10  0x14  0x18  0x1c
                  +-----+-----+-----+-----+
   ptr + 1------> |  2  |  2  |  1  |  3  |
                  +-----+-----+-----+-----+
                    0x20  0x24  0x28  0x2c
                  +-----+-----+-----+-----+
   ptr + 2------> |  9  |  1  |  3  |  0  |
                  +-----+-----+-----+-----+
                    0x30  0x34  0x38  0x3c
                  +-----+-----+-----+-----+
   ptr + 3------> |  2  |  1  |  2  |  3  |
                  +-----+-----+-----+-----+
                    0x40  0x44  0x48  0x4c
```


<!-- slide -->
``` C
int **ptr;
```

```ditaa {cmd=true args=["-E"]}
    +------+
ptr | 0x00 |
    ++--+--+
     |
     v
+------+------+------+------+
| 0x10 | 0x7c | 0x50 | 0x88 |
+------+------+------+------+
  0x00   0x04   0x08   0x0c
   |      |      |       |         +-----+-----+-----+-----+-----+
   |      |      |       +-------> |  5  |  1  |  1  |  3  |  4  |
   |      |      |                 +-----+-----+-----+-----+-----+
   |      |      |                   0x88  0x8c  0x90  0x94  0x98
   |      |      |                 +-----+
   |      |      +---------------> |  2  |
   |      |                        +-----+
   |      |                          0x50
   |      |                        +-----+-----+-----+
   |      +----------------------> |  9  |  2  |  2  |
   |                               +-----+-----+-----+
   |                                 0x7c  0x80  0x84
   |                               +-----+-----+-----+-----+
   +-----------------------------> |  2  |  1  |  2  |  3  |
                                   +-----+-----+-----+-----+
                                     0x10  0x14  0x18  0x1c
```

<!-- slide -->

## 之前的問題

<!-- slide -->
``` C
int main()
{
    int m = 3;
    int array[][2]={{1, 2}, {3, 4}, {5, 6}};
    Reverse2D(array, m);
    return 0;
}
```

<!-- slide -->
``` C
void Reverse2D(int (*array)[2], int m)
{
    for(int i = m - 1; i >= 0; i--){
        int rowSize = sizeof(array[i]) / sizeof(int);
        for(int j = rowSize - 1; j >= 0; j--)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
```

<!-- slide -->
``` C
void Reverse2D(int (*array)[2], int m)
{
    for(int i = m - 1; i >= 0; i--){
        int rowSize = sizeof(*(array + i)) / sizeof(int);
        for(int j = rowSize - 1; j >= 0; j--)
        {
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}
```

<!-- slide -->
``` C
void Reverse2D(int (*array)[2], int m)
{
    for(int (*ptr)[2] = array + m - 1; ptr >= array; ptr--){
        int rowSize = sizeof(*(ptr)) / sizeof(int);
        for(int* ptr2 = *(ptr) + rowSize - 1; ptr2 >= *(ptr); ptr2--)
        {
            printf("%d ", *(ptr2));
        }
        printf("\n");
    }
}
```