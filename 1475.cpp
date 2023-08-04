#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'
#define SIZE 10

string input;
int number[SIZE], ans = -1;

void initInput() {
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        int cur = input[i] - '0';
        if (cur == 6 || cur == 9) {
            cur = (number[6] < number[9] ? 6 : 9);
        }
        number[cur]++;
    }
}

void solve() {
    for (int i = 0; i < SIZE; i++)
        ans = max(number[i], ans);
    cout << ans << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
