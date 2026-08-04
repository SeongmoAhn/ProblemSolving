#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 51

int N, sum;
int A[SIZE], B[SIZE];

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A, A + N);
    sort(B, B + N, greater<>());
}

void solve() {
    for (int i = 0; i < N; i++) sum += A[i] * B[i];
    cout << sum << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
