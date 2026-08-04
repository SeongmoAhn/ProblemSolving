#include <iostream>
using namespace std;
#define endl '\n'

int n;

void initInput() {
    cin >> n;
}

void solve() {
    for (int i = n; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            cout << '*';
        }
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
