#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define INT_INF 2147483647
#define SIZE 100001
#define MAX_TREE 1
#define MIN_TREE 0

int N, M, h, treeSize;
int input[SIZE];
pii test[SIZE];
vector<int> maxSeg;
vector<int> minSeg;

void initInput() {
    cin >> N >> M;
    h = (int)ceil(log2(N));
    treeSize = (1 << (h + 1));

    for (int i = 0; i < N; i++) cin >> input[i];
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        test[i] = {a, b};
    }
}

int initTree(int curNode, int start, int end, bool whatTree) {
    if (start == end) {
        if (whatTree == MAX_TREE) {
            return maxSeg[curNode] = input[start];
        }
        else {
            return minSeg[curNode] = input[start];
        }
    }

    int mid = (start + end) / 2;
    int leftSum = initTree(curNode * 2, start, mid, whatTree);
    int rightSum = initTree(curNode * 2 + 1, mid + 1, end, whatTree);
    if (whatTree == MAX_TREE) {
        maxSeg[curNode] = max(leftSum, rightSum);
        return maxSeg[curNode];
    }
    else {
        minSeg[curNode] = min(leftSum, rightSum);
        return minSeg[curNode];
    }
}

int getSum(int curNode, int start, int end, int left, int right, bool whatTree) {
    if (right < start || left > end) {
        if (whatTree == MAX_TREE) return -INT_INF;
        else return INT_INF;
    }

    if (left <= start && end <= right) {
        if (whatTree == MAX_TREE) return maxSeg[curNode];
        else return minSeg[curNode];
    }

    int mid = (start + end) / 2;
    int leftSum = getSum(curNode * 2, start, mid, left, right, whatTree);
    int rightSum = getSum(curNode * 2 + 1, mid + 1, end, left, right, whatTree);
    if (whatTree == MAX_TREE) return max(leftSum, rightSum);
    else return min(leftSum, rightSum);
}

void solve() {
    maxSeg.resize(treeSize);
    minSeg.resize(treeSize);
    initTree(1, 0, N - 1, MAX_TREE);
    initTree(1, 0, N - 1, MIN_TREE);

    for (int i = 0; i < M; i++) {
        int a = test[i].first - 1;
        int b = test[i].second - 1;

        cout << getSum(1, 0, N - 1, a, b, MIN_TREE) << ' ' << getSum(1, 0, N - 1, a, b, MAX_TREE) << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
