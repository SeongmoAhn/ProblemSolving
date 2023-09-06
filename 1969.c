#include <stdio.h>

int N, M;
int ans;
char ansStr[51];
char DNA[4] = {'T', 'G', 'C', 'A'};

int getIdx(char ch) {
    if (ch == 'T') return 0;
    else if (ch == 'G') return 1;
    else if (ch == 'C') return 2;
    else return 3;
}
int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &M);
    char input[N][51];
    for (int i = 0; i < N; i++)
        scanf("%s", input[i]);

    for (int i = 0; i < M; i++) {
        int cnt[4] = {0};
        for (int j = 0; j < N; j++) {
            cnt[getIdx(input[j][i])]++;
        }

        int max = 0;
        for (int j = 1; j < 4; j++) {
            if (cnt[j] >= cnt[max]) max = j; 
        }
        ansStr[i] = DNA[max];

        for (int j = 0; j < 4; j++) {
            if (j == max) continue;
            ans += cnt[j];
        }
    }

    printf("%s\n%d\n", ansStr, ans);

    return 0;
}
