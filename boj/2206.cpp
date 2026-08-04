#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 1001
#define INF 1e9

int row, col;
int graph[SIZE][SIZE];
int visited[SIZE][SIZE][2];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
queue<pair<pair<int, int>, pair<int, int>>> q;

void initInput() {
    cin >>row >> col;
    for (int i = 0; i < row; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < col; j++) {
            graph[i][j] = input[j] - '0';
        }
    }
}

bool isInDomain(int y, int x) {
    return (x >= 0) && (y >= 0) && (y < row) && (x < col);
}

int BFS(int y, int x) {
    q.push({{y, x}, {0, 1}}); 
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto cur = q.front().first;
        int block = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (cur.first == row - 1 && cur.second == col - 1) return cnt;

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (isInDomain(ny, nx)) {
                if (graph[ny][nx] && !block) {
                    visited[ny][nx][block + 1] = true;
                    q.push({{ny, nx}, {block + 1, cnt + 1}});
                }
                else if (!graph[ny][nx] && !visited[ny][nx][block]) {
                    visited[ny][nx][block] = true;
                    q.push({{ny, nx}, {block, cnt + 1}});
                }
            }
        }
    }

    return -1;
}

void solve() {
    cout << BFS(0, 0) << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
