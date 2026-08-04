#include <iostream>
#include <queue>
using namespace std;
#define FOR0(x, y) for(int (x) = 0; (x) < (y); (x)++)
#define FOR1(x, y) for(int (x) = 1; (x) < (y); (x)++)

int n;
queue<int> q;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    FOR1(i, n + 1) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
        q.push(q.front());
        q.pop();
    }

    return 0;
}
