#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 9

int N, M;
vector<int> v;

void initInput() {
    cin >> N >> M;
}

void recur() {
    if (v.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= N; i++) {
        v.push_back(i);
        recur();
        v.pop_back();
    }
}

void solve() {
    recur();
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
