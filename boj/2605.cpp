#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 101

int N;
int line[SIZE];

void initInput() {
    cin >> N;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int num; cin >> num;

        for (int j = 0; j < num; j++)
            line[i - j] = line[i - (j + 1)];
        line[i - num] = i;
    }

    for (int i = 1; i <= N; i++) {
        cout << line[i] << ' ';
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
