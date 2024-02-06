#include <stdio.h>
using namespace std;
#define endl '\n'

int main(void) {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int N; 
        scanf("%d", &N);
        int a, cnt = 0;
        double b, sum = 0.0;
        for (int i = 0; i < N; i++) {
            scanf("%d %lf", &a, &b);
            cnt += a;
            sum += (b * (double)a);
        }
        printf("%d %.1f\n",cnt, sum / (double)cnt);
    }
}
