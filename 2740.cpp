#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 101

int row1, col1;
int row2, col2;
int m1[SIZE][SIZE];
int m2[SIZE][SIZE];
int ans[SIZE][SIZE];

void initInput() {
    cin >> row1 >> col1;
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            cin >> m1[i][j];

    cin >> row2 >> col2;
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            cin >> m2[i][j];
}

void solve() {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
