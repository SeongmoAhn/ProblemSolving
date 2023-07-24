#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 101

int N;
int visited[SIZE];
vector<int> v[SIZE];

void initInput() {
    cin >> N;
    int input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input;
            if (input)
                v[i].push_back(j);
        }
    }
}

void DFS(int node) {
    for (int i = 0; i < v[node].size(); i++) {
        int nextNode = v[node][i];
        if (visited[nextNode]) continue;
        visited[nextNode] = 1;
        DFS(nextNode);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        memset(visited, 0, sizeof(visited));
        DFS(i);
        for (int j = 0; j < N; j++) {
            cout << visited[j] << ' ';
        }
        cout << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input", "r", stdin);
    initInput();
    solve();

    return 0;
}
