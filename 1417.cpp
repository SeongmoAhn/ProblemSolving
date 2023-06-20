#include <iostream>
#include <queue>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 

int n, dasom, cnt;
priority_queue<int> pq;

void initInput() {
    cin >> n >> dasom;
    if (n == 1) {
        cout << 0 << endl;
        exit(0);
    }
    for (int i = 0; i < n - 1; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }
}

void solve() {
    while (1) {
        if (dasom > pq.top()) return;

        int temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
        dasom++;
        cnt++;
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();
    cout << cnt << endl;

    return 0;
}
