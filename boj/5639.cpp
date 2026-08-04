#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 10001

vector<int> tree;

void initInput() {
    int input;
    while (cin >> input) {
        tree.push_back(input);
    }
}

void postOrder(int start, int end) {
    int rootIdx = start;
    int leftRoot = start + 1;
    int rightRoot = leftRoot;
    if (start > end) return;
    if (start == end) {
        cout << tree[rootIdx] << endl;
        return;
    }
    for (int i = leftRoot; i <= end; i++) {
        if (tree[rootIdx] < tree[i]) {
            rightRoot = i;
            break;
        }
    }
    postOrder(leftRoot, rightRoot - 1);
    postOrder(rightRoot, end);
    cout << tree[rootIdx] << endl;
}

void solve() {
    postOrder(0, tree.size() - 1);
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
