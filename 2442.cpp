#include <iostream>
using namespace std;
#define endl '\n'

int n;

void initInput() {
    cin >> n;
}

void solve() {
    int cnt = 0;
    while (n--) {
        for (int i = 0; i < n; i++) cout << ' ';
        for (int i = 0; i < 2 * cnt + 1; i++) cout << '*';
        cout << endl;
        cnt++;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
