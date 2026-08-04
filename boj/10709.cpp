#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 101

int row, col;
string input[SIZE];
int result[SIZE][SIZE];
vector<pii> v;

void initInput() {
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        fill(result[i], result[i] + SIZE, -1);
        cin >> input[i];
        for (int j = 0; j < col; j++) {
            if (input[i][j] == 'c') {
                result[i][j] = 0;
                v.push_back({i, j});
            }
        }
    }
}

void solve() {
    int y, x;
    for (int i = 0; i < v.size(); i++) {
        y = v[i].first;
        x = v[i].second;
        for (int j = 1; result[y][x + j] == -1; j++) {
            if ((x + j) == col) break;
            result[y][x + j] = j;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << result[i][j] << ' ';
        cout << endl;
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
