# Shorter.h

A lightweight single-header sorting library for C.

`shorter.h` provides:

- Generic sorting using `void *`
- Multiple compare functions for different data types
- Automatic array length macro
- Single header file (just include and use)

---

# Installation

Copy `shorter.h` into your project folder.

Example:

```txt
project/
│── main.c
│── shorter.h
```

Include it:

```c
#include "shorter.h"
```

Compile:

```bash
gcc main.c -o app
```

Run:

```bash
./app
```

Windows:

```bash
app.exe
```

---

# Features

- Generic `sort()` function
- `length()` macro for array size
- Built-in compare functions

Supported types:

- int
- char
- short
- long
- long long
- unsigned int
- float
- double
- long double
- string (`char *`)

---

# Functions

## length()

Gets array size automatically.

### Syntax

```c
length(array)
```

### Example

```c
int numbers[] = {1,2,3,4};

int len = length(numbers);

printf("%d", len);
```

Output:

```txt
4
```

### Important

`length()` only works with arrays.

Correct:

```c
int arr[] = {1,2,3};

length(arr);
```

Wrong:

```c
int *ptr = arr;

length(ptr);
```

---

## sort()

Sorts any array type.

### Syntax

```c
sort(array, length, sizeof(type), compareFunction);
```

### Parameters

| Parameter | Description |
|------------|-------------|
| array | Array to sort |
| length | Number of elements |
| sizeof(type) | Size of one item |
| compareFunction | Compare function |

---

# Compare Functions

| Type | Function |
|------|----------|
| int | compareInt |
| char | compareChar |
| short | compareShort |
| long | compareLong |
| long long | compareLongLong |
| unsigned int | compareUnsignedInt |
| float | compareFloat |
| double | compareDouble |
| long double | compareLongDouble |
| string (`char *`) | compareString |

---

# Examples

## Integer Sorting

```c
#include <stdio.h>
#include "shorter.h"

int main() {

    int numbers[] = {11, 21, 13, 24, 5};

    sort(
        numbers,
        length(numbers),
        sizeof(int),
        compareInt
    );

    for(int i = 0; i < length(numbers); i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
```

Output:

```txt
5 11 13 21 24
```

---

## Character Sorting

```c
#include <stdio.h>
#include "shorter.h"

int main() {

    char letters[] = {'z', 'b', 'x', 'a'};

    sort(
        letters,
        length(letters),
        sizeof(char),
        compareChar
    );

    for(int i = 0; i < length(letters); i++) {
        printf("%c ", letters[i]);
    }

    return 0;
}
```

Output:

```txt
a b x z
```

---

## Float Sorting

```c
#include <stdio.h>
#include "shorter.h"

int main() {

    float nums[] = {3.5, 1.2, 9.7};

    sort(
        nums,
        length(nums),
        sizeof(float),
        compareFloat
    );

    for(int i = 0; i < length(nums); i++) {
        printf("%.2f ", nums[i]);
    }

    return 0;
}
```

Output:

```txt
1.20 3.50 9.70
```

---

## String Sorting

```c
#include <stdio.h>
#include "shorter.h"

int main() {

    char *names[] = {
        "Tusar",
        "Alex",
        "John",
        "Bob"
    };

    sort(
        names,
        length(names),
        sizeof(char *),
        compareString
    );

    for(int i = 0; i < length(names); i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
```

Output:

```txt
Alex
Bob
John
Tusar
```

---

# How It Works

`sort()` uses:

```c
void *
```

This allows sorting of any data type.

The compare function decides how values are compared.

Example:

```c
int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
```

---

# Example Project

```txt
project/
│── main.c
│── shorter.h
```

Example:

```c
#include <stdio.h>
#include "shorter.h"

int main() {

    int arr[] = {4, 2, 9, 1};

    sort(
        arr,
        length(arr),
        sizeof(int),
        compareInt
    );

    for(int i = 0; i < length(arr); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

Output:

```txt
1 2 4 9
```

---

# License

Free to use and modify.
