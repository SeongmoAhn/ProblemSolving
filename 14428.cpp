#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define endl '\n'
#define SIZE 100001
#define INF 2100000000
#define pii pair<int, int>

int N, T, height;
int treeSize;
int input[SIZE];

void initInput() {
    cin >> N;
    height = (int)ceil(log2(N));
    treeSize = (1 << (height + 1));
    for (int i = 1; i <= N; i++)
        cin >> input[i];
    cin >> T;
}

pii initTree(vector<pii> &segTree, int cur, int start, int end) {
    if (start == end) return segTree[cur] = make_pair(input[start], start);
    else {
        int mid = (start + end) / 2;
        // 리프노드가 아닌 경우 왼쪽 자식노드와 오른쪽 자식노드 중 작은 값을 노드 값으로 갱신
        auto left = initTree(segTree, cur * 2, start, mid);
        auto right = initTree(segTree, cur * 2 + 1, mid + 1, end);
        if (left.first <= right.first) return segTree[cur] = left;
        else return segTree[cur] = right;
    }
}

pii getMinIdx(vector<pii> &segTree, int cur, int start, int end, int left, int right) {
    if (right < start || end < left) return make_pair(INF, 0);

    if (left <= start && end <= right) return segTree[cur];
    int mid = (start + end) / 2;
    auto l = getMinIdx(segTree, cur * 2, start, mid, left, right);
    auto r = getMinIdx(segTree, cur * 2 + 1, mid + 1, end, left, right);
    return (l.first <= r.first ? l : r);
}

pii updateTree(vector<pii> &segTree, int cur, int start, int end, int idx, int update) {
    if (idx < start || end < idx) return segTree[cur];

    if (start == end) return segTree[cur] = make_pair(update, segTree[cur].second);

    int mid = (start + end) / 2;
    auto left = updateTree(segTree, cur * 2, start, mid, idx, update);
    auto right = updateTree(segTree, cur * 2 + 1, mid + 1, end, idx, update);
    segTree[cur] = (left.first <= right.first ? left : right);
    return segTree[cur];
}

void solve() {
    int type, i, j;
    vector<pii> segTree(treeSize);
    initTree(segTree, 1, 1, N);

    while (T--) {
        cin >> type >> i >> j;
        if (type & 1) { // 값 변경
            updateTree(segTree, 1, 1, N, i, j);
        }
        else { // 최소값 인덱스 계산
            cout << getMinIdx(segTree, 1, 1, N, i, j).second << endl;
        }
    }
}

int main() {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();
}
