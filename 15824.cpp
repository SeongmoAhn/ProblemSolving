#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define INF 1e9
#define ll long long
#define SIZE 300001
#define MOD 1000000007

int N;
ll input[SIZE];
ll powArray[SIZE];
ll front, rear;

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    sort(input, input + N);
    ll temp = 1;
    for (int i = 0; i < N; i++) {
        powArray[i] = temp - 1;
        temp *= 2;
        temp %= MOD;
    }
}

void solve() {
    for (int i = N - 1; i > 0; i--) {
        front += (powArray[i] * input[i]) % MOD;
        rear += (powArray[i] * input[N - 1 - i]) % MOD;
    }

    cout << ((front % MOD + MOD) - (rear % MOD)) % MOD << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
