#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 26

string str;

void initInput()
{
    cin >> str;
}

void solve()
{
    int cnt[SIZE] = {0};

    for (char c : str) {
        cnt[toupper(c) - 'A']++;
    }

    int ans = 0, idx = 0, count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (cnt[i] > cnt[idx]) {
            idx = i;
            count = 1;
        } else if (cnt[i] == cnt[idx]) {
            idx = i;
            count++;
        }
    }

    cout << (count == 1 ? char(idx + 'A') : '?') << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // for (int i = 0; i < 4; i++) {
        initInput();
        solve();
    // }

    return 0;
}
