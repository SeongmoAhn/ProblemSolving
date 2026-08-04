#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    int N, M;
    while (scanf("%d%d", &N, &M) != EOF) {
        int cnt = 0;
        for (int i = N; i <= M; i++) {
            bool flag = 1;
            int cur = i, check[10] = {0}; 
            while (cur > 0) {
                check[cur % 10]++;
                if (check[cur % 10] > 1) { flag = 0; break; }
                cur /= 10;
            }
            if (flag) cnt++;
        }
        printf("%d\n", cnt);
    }
}
