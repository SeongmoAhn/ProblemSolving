#include <iostream>
#include <cstring>
using namespace std;

int testCase, row, col;
int board[21][21];
char temp[21];
const int coverType[4][3][2] = {
         {{0, 0}, {0, 1}, {1, 0}},
         {{0, 0}, {0, 1}, {1, 1}}, 
         {{0, 0}, {1, 0}, {1, 1}}, 
         {{0, 0}, {1, -1}, {1, 0}}
};

bool set(int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= row || nx < 0 || nx >= col)
            ok = false;
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover() {
    int y = -1, x = -1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    if (y == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        if (set(y, x, type, 1))
            ret += cover();
        set(y, x, type, -1);
    }
    return ret;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    for (int t = 0; t < testCase; t++) {
        memset(board, 0, sizeof(board));
        cin >> row >> col;
        for (int i = 0; i < row; i++) {
            cin >> temp;

            for (int j = 0; j < col; j++) {
                temp[j] == '#' ? board[i][j] = 1 : board[i][j] = 0;
            }
        }

        cout << cover() << '\n';
    }

    return 0;
}
