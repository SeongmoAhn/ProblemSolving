#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 2005

int N;
int tree[SIZE];

void init_input() {
    cin >> N;
    tree[1] = 1;
    for (int i = 1; i <= N; i++) {
        int a, b, c; cin >> a >> b >> c;
        tree[a * 2] = b;
        tree[a * 2 + 1] = c;
    }
}

void dfs(int order, int node) {
    if (node <= 0) return ;

    if (order == 1) cout << node << ' ';
    dfs(order, tree[node * 2]);
    if (order == 0) cout << node << ' ';
    dfs(order, tree[node * 2 + 1]);
    if (order == 2) cout << node << ' ';
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    for (int i = 0; i < 3; i++) {
        dfs(i, 1);
        cout << endl;
    }

    return 0;
}
