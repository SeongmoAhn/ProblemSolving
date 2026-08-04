#include <iostream>
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
    int low = 1, mid;
    int ans = 2e9;

    while (low <= high) {
        mid = (low + high) / 2;

        int cnt = 1, temp_sum = 0;
        for (int n : v) {
            if (mid < n) {
                cnt = M + 1;
                break;
            }

            if (temp_sum + n <= mid) {
                temp_sum += n;
            } else {
                temp_sum = n;
                cnt++;
            }
        }

        if (cnt <= M) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    cout << solve() << endl;

    return 0;
}