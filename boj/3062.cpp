#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) {
        string a; cin >> a;
        int n = stoi(a);
        reverse(a.begin(), a.end());
        int m = stoi(a);
        int sum = n + m;
        a = to_string(sum);
        bool flag = 0;
        for (int i = 0; i < a.size() / 2; i++) {
            if (a[i] != a[a.size() - 1 - i]) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "NO" : "YES") << endl;
    }
}
