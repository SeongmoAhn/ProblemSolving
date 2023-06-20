#include <iostream>
// #include <string>
// #include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 126
#define INF 1e9

int testCase = 5;
int graph[SIZE][SIZE];
int distTable[SIZE][SIZE];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
priority_queue<pair<int, pair<int, int>>> pq;

void initInput() {
}

bool isInDomain(int y, int x) {
    return (x >= 0) && (y >= 0) && (x < testCase) && (y < testCase);
}

void shortPath() {
    distTable[0][0] = graph[0][0];
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        auto cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (isInDomain(ny, nx)) {
                int cost = distTable[cur.first][cur.second] + graph[ny][nx];

                if (cost < distTable[ny][nx]) {
                    distTable[ny][nx] = cost;
                    pq.push({-cost, {ny, nx}});
                }
            }
        }
    }
}

void solve() {
    int cnt = 1;
    while (1) {
        cin >> testCase;
        if (!testCase) return;

        for (int i = 0; i < testCase; i++) {
            for (int j = 0; j < testCase; j++) {
                cin >> graph[i][j];
                distTable[i][j] = INF;
            }
        }

        shortPath();

        cout << "Problem " << cnt++ << ": " << distTable[testCase - 1][testCase - 1] << endl;
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
