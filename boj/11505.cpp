#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define INT_INF 2147483647
#define MOD 1000000007
#define SIZE 1000001

int N, M, K;
int h, treeSize;
ll input[SIZE];
vector<ll> segTree;

void initInput() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> input[i];
    h = (int)ceil(log2(N));
    treeSize = (1 << (h + 1));
}

ll initTree(int curNode, int start, int end) {
    if (start == end) return segTree[curNode] = input[start];

    int mid = (start + end) / 2;
    return segTree[curNode] = (initTree(curNode * 2, start, mid) 
        * initTree(curNode * 2 + 1, mid + 1, end)) % MOD;
}

ll updateTree(int curNode, int start, int end, int idx, ll diff) {
    if (idx < start || end < idx) return segTree[curNode];
    if (start == end) return segTree[curNode] = diff;
    int mid = (start + end) / 2;
    return segTree[curNode] = (updateTree(curNode * 2, start, mid, idx, diff)
        * updateTree(curNode * 2 + 1, mid + 1, end, idx, diff)) % MOD;
}

ll mulTree(int curNode, int start, int end, int left, int right) {
    if (end < left || right < start) return 1;

    if (left <= start && end <= right) return segTree[curNode] % MOD;

    int mid = (start + end) / 2;
    ll leftMul = mulTree(curNode * 2, start, mid, left, right) % MOD;
    ll rightMul = mulTree(curNode * 2 + 1, mid + 1, end, left, right) % MOD;
    return (leftMul * rightMul) % MOD;
}

void solve() {
    segTree.resize(treeSize);
    initTree(1, 0, N - 1);
    for (int i = 0; i < M + K; i++) {
        int a, b, c; cin >> a >> b >> c;

        if (a == 1) {
            updateTree(1, 0, N - 1, b - 1, c);
        }
        else {
            cout << mulTree(1, 0, N - 1, b - 1, c - 1) << endl;
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
