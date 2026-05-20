#ifndef LENGTH_H
#define LENGTH_H

#include <string.h>

#define length(x) (sizeof(x) / sizeof((x)[0]))

void sort(void *arr, int length, int size, int (*compare)(const void *, const void *));


int compareInt(const void *a, const void *b);
int compareChar(const void *a, const void *b);
int compareShort(const void *a, const void *b);
int compareLong(const void *a, const void *b);
int compareLongLong(const void *a, const void *b);
int compareUnsignedInt(const void *a, const void *b);
int compareFloat(const void *a, const void *b);
int compareDouble(const void *a, const void *b);
int compareLongDouble(const void *a, const void *b);
int compareString(const void *a, const void *b);

#endif


void sort(void *arr, int length, int size, int (*compare)(const void *, const void *)) {
    char *array = (char *)arr;
    char temp[size];
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1 - i; j++) {
            void *a = array + (j * size);
            void *b = array + ((j + 1) * size);
            if(compare(a, b) > 0) {
                memcpy(temp, a, size);
                memcpy(a, b, size);
                memcpy(b, temp, size);
            }
        }
    }
}




/* int */
int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* char */
int compareChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

/* short */
int compareShort(const void *a, const void *b) {
    return (*(short *)a - *(short *)b);
}

/* long */
int compareLong(const void *a, const void *b) {
    long x = *(long *)a;
    long y = *(long *)b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

/* long long */
int compareLongLong(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

/* unsigned int */
int compareUnsignedInt(const void *a, const void *b) {
    unsigned int x = *(unsigned int *)a;
    unsigned int y = *(unsigned int *)b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

/* float */
int compareFloat(const void *a, const void *b) {
    float x = *(float *)a;
    float y = *(float *)b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

/* double */
int compareDouble(const void *a, const void *b) {
    double x = *(double *)a;
    double y = *(double *)b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

/* long double */
int compareLongDouble(const void *a, const void *b) {
    long double x = *(long double *)a;
    long double y = *(long double *)b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

/* string (char *) */
int compareString(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}
