# C Sort Library

A simple generic sorting library for C that supports multiple data types using `void *` and compare functions.

## Features

- Generic sort function (`sort()`)
- Supports multiple data types
- Built-in compare functions:
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
- Array length macro

---

## File Structure

```txt
project/
│── main.c
│── sort.c
│── length.h
```

---

## Installation

Include the header:

```c
#include "length.h"
```

Compile:

```bash
gcc main.c sort.c -o app
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

## Functions

### sort()

Sorts any array type.

Syntax:

```c
sort(array, length, sizeof(type), compareFunction);
```

Parameters:

| Parameter | Description |
|----------|-------------|
| arr | Array to sort |
| length | Number of elements |
| size | Size of one element |
| compare | Compare function |

Example:

```c
sort(nums, length(nums), sizeof(int), compareInt);
```

---

## length()

Gets array size automatically.

Syntax:

```c
length(array)
```

Example:

```c
int nums[] = {1,2,3,4};

int len = length(nums);

printf("%d", len);
```

Output:

```txt
4
```

> Note: `length()` only works with arrays, not pointers.

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

# Supported Compare Functions

| Data Type | Compare Function |
|---|---|
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

## Example: Integer Sorting

```c
#include <stdio.h>
#include "length.h"

int main() {

    int nums[] = {11, 21, 13, 24, 5};

    sort(nums,
         length(nums),
         sizeof(int),
         compareInt);

    for(int i = 0; i < length(nums); i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
```

Output:

```txt
5 11 13 21 24
```

---

## Example: Character Sorting

```c
#include <stdio.h>
#include "length.h"

int main() {

    char chars[] = {'z', 'b', 'x', 'a'};

    sort(chars,
         length(chars),
         sizeof(char),
         compareChar);

    for(int i = 0; i < length(chars); i++) {
        printf("%c ", chars[i]);
    }

    return 0;
}
```

Output:

```txt
a b x z
```

---

## Example: Float Sorting

```c
#include <stdio.h>
#include "length.h"

int main() {

    float prices[] = {3.5, 1.2, 9.7};

    sort(prices,
         length(prices),
         sizeof(float),
         compareFloat);

    for(int i = 0; i < length(prices); i++) {
        printf("%.2f ", prices[i]);
    }

    return 0;
}
```

Output:

```txt
1.20 3.50 9.70
```

---

## Example: String Sorting

```c
#include <stdio.h>
#include "length.h"

int main() {

    char *names[] = {
        "Tusar",
        "Alex",
        "John",
        "Bob"
    };

    sort(names,
         length(names),
         sizeof(char *),
         compareString);

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

## How It Works

The library uses:

```c
void *
```

to accept any data type.

The compare function determines how two values are compared.

Example:

```c
int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
```

---

## License

Free to use and modify.
