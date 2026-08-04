#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 3073

int N;
char map[SIZE][SIZE * 2];

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 2 * N; j++)
            map[i][j] = ' ';
}

void recur(int y, int x, int height) {
    if (height == 3) {
        map[y][x] = '*';
        map[y + 1][x - 1] = map[y + 1][x + 1] = '*';
        for (int i = x - 2; i <= x + 2; i++) map[y + 2][i] = '*';
        return;
    }

    int nextHeight = height / 2;
    recur(y, x, nextHeight);
    recur(y + nextHeight, x - nextHeight, nextHeight);
    recur(y + nextHeight, x + nextHeight, nextHeight);
}

void solve() {
    recur(0, N - 1, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
