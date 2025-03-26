## Ex 1

### Code Differences (Before Change)

```c
    n = n + 1;
```

### Corresponding Assembly (Before Change)

```asm
    add     w8, w8, #1
```

### Code Differences (After Change)
```c
    n = n * 3;
```
### Corresponding Assembly (After Change)
```asm
    mov     w9, #3
    mul     w8, w8, w9
```

## Ex 2
### Code Differences (Before Change)
```c
    if (x > 5) {
```

### Corresponding Assembly (Before Change)
```asm
        cset    w8, le
```

### Code Differences (After Change)
```c
    if ((x * 2 - 5) % 3 == 0) {
```

### Corresponding Assembly (After Change)
```asm
        lsl     w8, w8, #1
        mov     w10, #3
        sdiv    w9, w8, w10
        mul     w9, w9, w10
        subs    w8, w8, w9
        subs    w8, w8, #0
        cset    w8, ne
```

## Ex 3
### Code Differences (Before Change)
```c
    for (int i = 0; i < 10; i++) {
```
### Corresponding Assembly (Before Change)
```asm
        tbnz    w8, #0, LBB0_4
        b       LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
LBB0_4:
```

### Code Differences (After Change)
```c
    int i = 0;
    while (i < 10) {
        i++;
```
### Corresponding Assembly (After Change)
```asm
        tbnz    w8, #0, LBB0_3
LBB0_3:
```

## Ex 4
### Code Differences (Before Change)
```c
    n = n * 2;
```
### Corresponding Assembly (Before Change)



### Code Differences (After Change)
```c
    n = n << 1;
```
### Corresponding Assembly (After Change)


## Ex 5
### Code Differences (Before Change)
```c
    int a = 5;
    int b = 2;
    int c = a / b;
```
### Corresponding Assembly (Before Change)
```asm
        mov     w8, #5
        str     w8, [sp, #12]
        mov     w8, #2
        str     w8, [sp, #8]
        ldr     w8, [sp, #12]
        ldr     w9, [sp, #8]
        sdiv    w8, w8, w9
        str     w8, [sp, #4]
```
### Code Differences (After Change)
```c
    float a = 5.0;
    float b = 2.0;
    float c = a / b;
```
### Corresponding Assembly (After Change)
```asm
        fmov    s0, #5.00000000
        str     s0, [sp, #12]
        fmov    s0, #2.00000000
        str     s0, [sp, #8]
        ldr     s0, [sp, #12]
        ldr     s1, [sp, #8]
        fdiv    s0, s0, s1
        str     s0, [sp, #4]
```