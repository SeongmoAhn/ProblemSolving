#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N * N; i++) {
        int input; cin >> input;
        pq.push(input);
        while (pq.size() > N)
            pq.pop();
    }
    cout << pq.top() << endl;

    return 0;
}
