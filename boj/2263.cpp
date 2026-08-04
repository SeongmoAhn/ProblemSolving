#include <iostream>
using namespace std;
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 100001

int n;
int inOrder[SIZE];
int postOrder[SIZE];
int idx[SIZE];

void initInput() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> inOrder[i];
        idx[inOrder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> postOrder[i];
    }
}

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if ((inStart > inEnd) || (postStart > postEnd))
        return ;

    int rootIdx = idx[postOrder[postEnd]];
    int leftSize = rootIdx - inStart;
    cout << inOrder[rootIdx] << ' ';

    preOrder(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);
    preOrder(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

void solve() {
    preOrder(1, n, 1, n);
    cout << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
