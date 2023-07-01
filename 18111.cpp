#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 501

int map[SIZE][SIZE];
int N, M, B;
int minTime = INF, maxHeight = -1;

void initInput() {
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

void solve() {
    for (int chkHeight = 0; chkHeight <= 256; chkHeight++) {
        int build = 0, remove = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int curHeight = map[i][j] - chkHeight;

                if (curHeight > 0)
                    remove += curHeight;
                else if (curHeight < 0) 
                    build -= curHeight;
            }
        }
        if (remove + B >= build) {
            int curTime = remove * 2 + build;

            if (curTime <= minTime) {
                minTime = curTime;
                maxHeight = chkHeight;
            }
        }
    }
    cout << minTime << ' ' << maxHeight << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
