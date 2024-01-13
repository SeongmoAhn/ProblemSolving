#include <stdio.h>
int main(void) {
    int N; scanf("%d", &N);
    if (N < 3) { printf("4"); return 0; }
    for (int i = 2;; i++) {
        if (N <= i * (i + 1)) {
            printf("%d", 4 * i - 2 - (N <= i * i ? 2 : 0));
            return 0;
        }
    }
}
