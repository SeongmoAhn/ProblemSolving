#include <cstdio>
#include <cstring>
int main() {
    char input[30];
    scanf("%s", input);
    char begin[30] = ":";
    strcat(begin, input);
    strcat(begin, ":");
    for (int i = 0; i < 9; i++) {
        if (i != 4)
            printf(":fan:");
        else
            printf("%s", begin);
        if (i % 3 == 2)
            printf("\n");
    }
}
