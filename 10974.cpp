#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define SIZE 9
#define endl '\n'

int N;
bool visited[SIZE];
vector<int> ans;

void initInput() {
    cin >> N;
}

void solve(int cnt) {
    if (ans.size() == N) {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << ' ';
        }cout << endl;
        return ;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        visited[i] = 1;
        ans.push_back(i);
        solve(cnt + 1);
        ans.pop_back();
        visited[i] = 0;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve(0);

    return 0;
}
