#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define endl '\n'
#define SIZE 3000

char map[SIZE][SIZE];
int mid;

void solve(int N, int startRow) {
    int height = pow(2, N) - 1;
    int length = height * 2 - 1;

    if (N == 1) {
        map[startRow][mid] = '*';
        return ;
    }

    if (N & 1) {
        map[startRow][mid] = '*';
        for (int i = 1, j = 1; i < height; i++, j++)
            map[startRow + i][mid + j] = map[startRow + i][mid - j] = '*';
        for (int i = 0; i < length / 2 + 1; i++)
            map[startRow + height - 1][mid - i] = map[startRow + height - 1][mid + i] = '*';
        solve(N - 1, startRow + (height - 1) / 2);
    }
    else {
        for (int i = 0; i < length / 2 + 1; i++)
            map[startRow][mid - i] = map[startRow][mid + i] = '*';
        for (int i = 0, j = 1; height - 2 - i > 0 ; i++, j++)
            map[startRow + height - 2 - i][mid + j] = map[startRow + height - 2 - i][mid - j] = '*';
        map[startRow + height - 1][mid] = '*';
        solve(N - 1, startRow + 1);
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N; cin >> N;
    int height = pow(2, N) - 1;
    int length = height * 2 - 1;
    mid = length / 2;
    memset(map, ' ', sizeof(map));
    solve(N, 0);
    if (N & 1) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j <= mid + i; j++)
                cout << map[i][j];
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j <= length - i; j++)
                cout << map[i][j];
            cout << endl;
        }
    }

    return 0;
}
