#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 10001

int n, d;
vector<pii> graph[SIZE];
int dist[SIZE];

void initInput() {
    cin >> n >> d;
    for (int i = 0; i < d; i++) {
        int start, to, dist;
        cin >> start >> to >> dist;
        graph[to].push_back({start, dist});
    }
    fill(dist, dist + SIZE, INF);
}

void solve() {
    dist[0] = 0;
    for (int i = 1; i <= d; i++) {
        if (!graph[i].size()) dist[i] = dist[i - 1] + 1;
        else {
            for (int j = 0; j < graph[i].size(); j++) {
                dist[i] = min(dist[i], min(dist[i - 1] + 1, dist[graph[i][j].first] + graph[i][j].second));
            }
        }
    }

    cout << dist[d] << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
