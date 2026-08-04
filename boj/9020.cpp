#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define PRIME false
#define NOT_PRIME true

queue<int> q;
int maxValue = -1;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> input;
        q.push(input);
        maxValue = max(maxValue, input);
    }

    // 소수 테이블 생성
    vector<bool> v(maxValue + 1);
    for (i = 2; i <= sqrt(maxValue); i++) {
        if (v[i] == PRIME) {
            int j = 2;
            while (i * j <= maxValue) {
                v[i * j] = NOT_PRIME;
                j++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        int curCheck = q.front();
        q.pop();

        // test case 절반 값 부터 인덱스를 왼쪽, 오른쪽으로 하나 씩 이동시키며
        // 두 값이 모두 소수이면 그 인덱스를 출력
        for (j = curCheck / 2; j < curCheck; j++) {
            if (v[j] == PRIME && v[curCheck - j] == PRIME) {
                cout << curCheck - j << " " << j << '\n';
                break;
            }
        }
    }

    return 0;
}
