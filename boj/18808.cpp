#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'
#define SIZE 15

int R, C, S;
int labtop[41][41];

class Sticker {
public:
    int row;
    int col;
    bool shape[SIZE][SIZE];

    Sticker(int r, int c) : row(r), col(c) {
        memset(shape, 0, sizeof(shape));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                cin >> shape[i][j];
        }
    }
    void rotate() {
        bool temp[SIZE][SIZE] = {0,};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                temp[j][row - i - 1] = shape[i][j];
        }

        swap(row, col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                shape[i][j] = temp[i][j];
        }
    }

    void printSticker() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                cout << shape[i][j] << ' ';
            cout << endl;
        }
    }
};

bool stick(Sticker *s, int y, int x) {
    for (int i = 0; i < s->row; i++) {
        for (int j = 0; j < s->col; j++) {
            if (labtop[y + i][x + j] && s->shape[i][j])
                return 0;
        }
    }

    for (int i = 0; i < s->row; i++) {
        for (int j = 0; j < s->col; j++) {
            if (s->shape[i][j]) labtop[y + i][x + j] = 1;
        }
    }
    return 1;
}

void solve() {
    cin >> R >> C >> S;
    while (S--) {
        int r, c; cin >> r >> c;
        Sticker *s = new Sticker(r, c);

        for (int t = 0; t < 4; t++) {
            bool flag = 0;
            for (int i = 0; i <= (R - s->row); i++) {
                if (flag) break;
                for (int j = 0; j <= (C - s->col); j++) {
                    if (stick(s, i, j)) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) break;
            s->rotate();
        }

        delete s;
    }

    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cnt += labtop[i][j];
        }
    }
    cout << cnt << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
