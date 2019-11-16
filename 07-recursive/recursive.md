<!-- slide -->
# 遞迴

<!-- slide -->
## 目的

簡化程式，大問題切成小問題解決

<!-- slide -->
## 舉例 - 費氏數列

``` C
int f(int n){
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 2);
}
```

<!-- slide -->
``` C
f(4);
```

``` dot
digraph f{
    a [label="f(4)", fillcolor=yellow, style=filled];
}
```

<!-- slide -->
``` C
//n = 4
return f(n - 1) + f(n - 2); // f(3) + f(2);
```

``` dot
digraph f{
    a [label="f(4)", fillcolor=yellow, style=filled];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    a->{b1 b2};
}
```

<!-- slide -->
``` C
//n = 3
return f(n - 1) + f(n - 2); // f(2) + f(1);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)", fillcolor=yellow, style=filled];
    b2 [label="f(2)"];
    c1 [label="f(2)"];
    c2 [label="f(1)"];
    a->{b1 b2};
    b1->{c1 c2};
}
```

<!-- slide -->
``` C
//n = 2
return f(n - 1) + f(n - 2); // f(1) + f(0);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)", fillcolor=yellow, style=filled];
    c2 [label="f(1)"];
    d1 [label="f(1)"];
    d2 [label="f(0)"];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 1
return 1;
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)"];
    c2 [label="f(1)"];
    d1 [label="1", fillcolor=yellow, style=filled];
    d2 [label="f(0)"];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
return f(n - 1) + f(n - 2); // 1 + f(0);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)", fillcolor=yellow, style=filled];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="f(0)"];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 1
return 1;
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="f(2)"];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="1", fillcolor=yellow, style=filled];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
return f(n - 1) + f(n - 2); // 1 + 1;
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="2", fillcolor=yellow, style=filled];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 3
return f(n - 1) + f(n - 2); // 2 + f(1);
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)", fillcolor=yellow, style=filled];
    b2 [label="f(2)"];
    c1 [label="2"];
    c2 [label="f(1)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 1
int f(int n){
    return 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)"];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", fillcolor=yellow, style=filled];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 3
int f(int n){
    return f(n - 1) + f(n - 2); // 2 + 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="f(3)", fillcolor=yellow, style=filled];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 4
int f(int n){
    return f(n - 1) + f(n - 2); // 3 + f(2);
}
```

``` dot
digraph f{
    a [label="f(4)", fillcolor=yellow, style=filled];
    b1 [label="3", style=dashed];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return f(n - 1) + f(n - 2); // f(1) + f(0);
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)", fillcolor=yellow, style=filled];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", fillcolor=yellow, style=filled];
    c4 [label="f(0)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return f(n - 1) + f(n - 2); // 1 + f(0);
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)", fillcolor=yellow, style=filled];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="f(0)"];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 0
int f(int n){
    return 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="f(2)"];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="1", fillcolor=yellow, style=filled];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 2
int f(int n){
    return f(n - 1) + f(n - 2); // 1 + 1;
}
```

``` dot
digraph f{
    a [label="f(4)"];
    b1 [label="3", style=dashed];
    b2 [label="2", fillcolor=yellow, style=filled];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```

<!-- slide -->
``` C
//n = 4
int f(int n){
    return f(n - 1) + f(n - 2); // 3 + 2;
}
```

``` dot
digraph f{
    a  [label="5", fillcolor=yellow, style=filled];
    b1 [label="3", style=dashed];
    b2 [label="2", style=dashed];
    c1 [label="2", style=dashed];
    c2 [label="1", style=dashed];
    c3 [label="1", style=dashed];
    c4 [label="1", style=dashed];
    d1 [label="1", style=dashed];
    d2 [label="1", style=dashed];
    a->{b1 b2};
    b1->{c1 c2};
    b2->{c3 c4};
    c1->{d1 d2};
}
```


<!-- slide -->
GCD