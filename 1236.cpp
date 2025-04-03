#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 51

int N, M;
int cnt_row, cnt_col;
char arr[SIZE][SIZE];

void init_input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        bool chk = 1;
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'X') {
                chk = 0;
                break;
            }
        }
        if (chk)
            cnt_row++;
    }
}

int solve()
{
    for (int j = 0; j < M; j++) {
        bool chk = 1;
        for (int i = 0; i < N; i++) {
            if (arr[i][j] == 'X') {
                chk = 0;
                break;
            }
        }
        if (chk)
            cnt_col++;
    }

    return max(cnt_row, cnt_col);
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    cout << solve() << endl;

    return 0;
}
