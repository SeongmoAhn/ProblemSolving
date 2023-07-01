#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 129
#define WHITE 0
#define BLUE 1

int n;
int map[SIZE][SIZE];
int blueCnt, whiteCnt;

void initInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
}

void recur(int y, int x, int size) {
    if (size == 1) {
        map[y][x] == BLUE ? blueCnt++ : whiteCnt++;
        return;
    }
    int nextSize = size / 2;
    int cur = map[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (cur != map[i][j]) {
                recur(y, x, nextSize);
                recur(y, x + nextSize, nextSize);
                recur(y + nextSize, x, nextSize);
                recur(y + nextSize, x + nextSize, nextSize);
                return;
            }
        }
    }
    cur == BLUE ? blueCnt++ : whiteCnt++;
}

void solve() {
    recur(1, 1, n);
    cout << whiteCnt << endl << blueCnt << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
