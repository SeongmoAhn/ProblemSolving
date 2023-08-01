#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 65
#define WHITE 0
#define BLACK 1

int N;
int map[SIZE][SIZE];

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        for (int j = 0; j < N; j++)
            map[i][j] = input[j] - '0';
    }
}

void divide(int y, int x, int size) {
    if (size == 1) {
        cout << map[y][x];
        return;
    }

    int nSize = size / 2;
    bool flag = 1;
    int curColor = (map[y][x] == WHITE ? WHITE : BLACK);
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (curColor != map[i][j]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag) {
        cout << curColor;
        return ;
    }

    cout << '(';
    divide(y, x, nSize);
    divide(y, x + nSize, nSize);
    divide(y + nSize, x, nSize);
    divide(y + nSize, x + nSize, nSize);
    cout << ')';
}

void solve() {
        divide(0, 0, N);
        cout << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
