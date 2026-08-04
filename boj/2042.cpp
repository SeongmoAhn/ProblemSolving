#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define endl '\n'
#define ll long long
#define SIZE 1000001

int N, M, K;
int h, treeSize;
ll input[SIZE];

void initInput() {
    cin >> N >> M >> K;
    h = (int)ceil(log2(N));
    treeSize = (1 << (h + 1));
    for (int i = 0; i < N; i++) cin >> input[i];
}

ll initTree(vector<ll> &segTree, int curNode, int start, int end) {
    if (start == end) return segTree[curNode] = input[start];
    else {
        int mid = (start + end) / 2;
        return segTree[curNode] = initTree(segTree, curNode * 2, start, mid) 
            + initTree(segTree, curNode * 2 + 1, mid + 1, end);
    }
}

ll sumTree(vector<ll> &segTree, int curNode, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;

    if (left <= start && end <= right)
        return segTree[curNode];

    else {
        int mid = (start + end) / 2;
        return sumTree(segTree, curNode * 2, start, mid, left, right)
            + sumTree(segTree, curNode * 2 + 1, mid + 1, end, left, right);
    }
}

void updateTree(vector<ll> &segTree, int curNode, int start, int end, int Idx, ll diff) {
    if (Idx < start || end < Idx) return ;

    segTree[curNode] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        updateTree(segTree, curNode * 2, start, mid, Idx, diff);
        updateTree(segTree, curNode * 2 + 1, mid + 1, end, Idx, diff);
    }
}

void solve() {
    vector<ll> segTree(treeSize);
    initTree(segTree, 1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            int b; ll c; cin >> b >> c;
            b--;
            ll diff = c - input[b];
            input[b] = c;
            updateTree(segTree, 1, 0, N - 1, b, diff);
        }
        else {
            int b, c; cin >> b >> c;
            cout << sumTree(segTree, 1, 0, N - 1, b - 1, c - 1) << endl;
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
