#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ten;
    int one;
    char str[13];
} Number;

int compare(const void *a, const void *b) {
    const Number *numA = (const Number *)a;
    const Number *numB = (const Number *)b;
    return strcmp(numA->str, numB->str);
}

char *numberToString[] = { "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine" };

int start, end;
Number arr[101];

int main(void) {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &start, &end);

    for (int i = start, j = 0; i <= end; i++, j++) {
        int ten, one, num = i;
        one = num % 10; num /= 10; ten = num % 10;
        arr[j].ten = ten;
        arr[j].one = one;

        if (ten == 0) sprintf(arr[j].str, "%s", numberToString[one]);
        else sprintf(arr[j].str, "%s %s", numberToString[ten], numberToString[one]);
    }

    qsort(arr, end - start + 1, sizeof(Number), compare);

    for (int i = 0; i < end - start + 1; i++) {
        int num = arr[i].ten * 10;
        num += arr[i].one;
        printf("%d ", num);
        if (i % 10 == 9) printf("\n");
    }

    return 0;
}
