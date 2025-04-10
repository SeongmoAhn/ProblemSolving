#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, M, high;
vector<int> v;

void init_input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        high += n;
        v.push_back(n);
    }
}

int solve()
{
    int low = v[N - 1], mid;
    int temp_sum, cnt, ans = 10e9;
    while (low <= high) {
        mid = (low + high) / 2;

        temp_sum = cnt = 0;
        for (int n : v) {
            int tmp = temp_sum + n;
            if (tmp > mid) {
                cout << "1: " << temp_sum << endl;
                temp_sum = n;
                cnt++;
            } else if (tmp == mid) {
                cout << "2: " << temp_sum << endl;
                temp_sum = 0;
                cnt++;
            } else {
                cout << "3: " << temp_sum << endl;
                temp_sum += n;
            }
        }
        
        printf("low: %d, mid: %d, high: %d, cnt: %d\n", low, mid, high, cnt);

        if (cnt >= M) {
            low = mid + 1;
        } else if (cnt < M) {
            high = mid - 1;
        } else {
        }
    }

    return mid;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    init_input();
    cout << solve() << endl;

    return 0;
}
