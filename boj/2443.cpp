#include <iostream>
using namespace std;
#define endl '\n'

int n;

void initInput() {
    cin >> n;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << ' ';
        for (int j = 0; j < (n - i) * 2 - 1; j++) cout << '*';
        cout << endl;
    } 
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
