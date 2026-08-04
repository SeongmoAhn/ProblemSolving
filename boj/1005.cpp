#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 1001

int testCase, n, k, win;
int timeTable[SIZE];
int inDegree[SIZE];
vector<int> graph[SIZE];
int dp[SIZE];
queue<int> q;

void initInput() {
    fill(timeTable, timeTable + SIZE, 0);
    fill(inDegree, inDegree + SIZE, 0);
    fill(dp, dp + SIZE, 0);
    for (int i = 1; i <= n; i++) graph[i].clear();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> timeTable[i];
        dp[i] = timeTable[i];
    }

    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        inDegree[y]++;
    }
    cin >> win;
}

void topologySort() {
    for (int i = 1; i <= n; i++) {
        if (i == win)
            continue;

        if (!inDegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            inDegree[next]--;
            dp[next] = max(dp[cur] + timeTable[next], dp[next]);

            if (!inDegree[next]) {
                q.push(next);
            }
        }
    }
}

void solve() {
    topologySort();
    cout << dp[win] << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    while (testCase--) {
        initInput();
        solve();
    }

    return 0;
}
