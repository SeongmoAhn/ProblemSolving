#include <iostream>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 100001

int N, S, sum, minLen = INF;
int arr[SIZE];

void initInput() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
    int start = 0, end = 0;
    sum = arr[start];
    while (start <= end && end < N) {
        if (sum >= S) minLen = min(minLen, end - start + 1);
        if (sum < S) {
            end++;
            sum += arr[end];
        }    
        else {
            sum -= arr[start];
            start++;
        }
    }
    if (minLen == INF) cout << 0 << endl;
    else cout << minLen << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
