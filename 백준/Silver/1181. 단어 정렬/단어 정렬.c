#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[20000][51];

int compare(const char *a, const char *b) {
    int x = strlen(a);
    int y = strlen(b);
    
    if (x > y) {
        return 1;
    }
    else if (x < y) {
        return -1;
    }
    else {
        return strcmp(a, b);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &arr[i]);
    }
    qsort(arr, n, 51*sizeof(char), compare);
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], arr[i+1])!=0) { printf("%s\n", arr[i]); }
            
    }
    return 0;
}