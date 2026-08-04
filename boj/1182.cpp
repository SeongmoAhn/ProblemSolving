#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 21

int N, S, ans;
int input[SIZE];

void initInput() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
}

void DFS(int idx, int part) {
    if (idx == N) return;

    if (part + input[idx] == S) ans++;

    DFS(idx + 1, part);
    DFS(idx + 1, part + input[idx]);
}

void solve() {
    DFS(0, 0);
    cout << ans << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
