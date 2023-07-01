#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int N, M, cnt, len;
string input;
string chk;
bool previous = false;

void initInput() {
    cin >> N >> M >> input;
    for (int i = 0; i < 2 * N + 1; i++) {
        if (i % 2 == 0) chk += 'I';
        else chk += 'O';
    }
    len = 2 * N + 1;
}

int func(int x) {
    for (int i = 0; i < len; i++) {
        if (input[x + i] != chk[i]) return 0;
    }
    return 1;
}

int func2(int x) {
    if (input[x + len - 1] == 'I' && input[x + len - 2] == 'O')
        return 1;
    else return 0;
}

void solve() {
    if (func(1)) {
        previous = true;
        cnt++;
    }
    for (int i = 2; i <= M - len; i += 2) {
        if (previous) {
            if (func2(i)) {
                previous = true;
                cnt++;
            }
            else previous = false;
        }
        else {
            if (func(i)) {
                previous = true;
                cnt++;
            }
            else previous = false;
        }
    }
    cout << cnt << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
