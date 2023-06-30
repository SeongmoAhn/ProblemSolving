#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'
#define INF 1e18
#define ll long long
#define tlll tuple<ll, ll, ll>
#define SIZE 5001

int n;
ll sum;
ll arr[SIZE];
tlll ans;

void initInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
}

void solve() {
    ll minValue = INF;
    for (int i = 0; i < n - 1; i++) {
        ll cur = arr[i];
        int left = i + 1, right = n - 1;
        while (left < right) {
            ll sum = cur + arr[left] + arr[right];

            if (sum == 0) {
                ans = {cur, arr[left], arr[right]};
                break;
            }
            else if (sum < 0) {
                if (abs(sum) < minValue) {
                    minValue = abs(sum);
                    ans = {cur, arr[left], arr[right]};
                }
                left++;
            }
            else {
                if (abs(sum) < minValue) {
                    minValue = abs(sum);
                    ans = {cur, arr[left], arr[right]};
                }
                right--;
            }
        }
    }
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans) << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
