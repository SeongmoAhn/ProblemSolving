#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define SIZE 101

ll dp[SIZE][SIZE];
int graph[SIZE][SIZE];
int N;
int dy[] = {0, 1};
int dx[] = {1, 0};

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++)
            cin >> graph[i][j];
}

bool isInDomain(int y, int x) { return (y <= N) && (x <= N); }

void solve() {
    dp[1][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!graph[i][j] || i == N && j == N) continue;
            for (int k = 0; k < 2; k++) {
                int ny = i + dy[k] * graph[i][j];
                int nx = j + dx[k] * graph[i][j];
                if (isInDomain(ny, nx))
                    dp[ny][nx] += dp[i][j];
            }
        }
    }
    cout << dp[N][N] << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
