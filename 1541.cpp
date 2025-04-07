#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'

int solve()
{
    string str; cin >> str;
    reverse(str.begin(), str.end());

    int ten = 1;
    int cur = 0, temp = 0, ans = 0;
    for (char ch : str) {
        if ('0' <= ch && ch <= '9') {
            cur += (ch - '0') * ten;
            ten *= 10;
        } else {
            temp += cur;
            ten = 1;
            cur = 0;
            if (ch == '-') {
                ans -= temp;
                temp = 0;
            }
        }
    }
    ans += (temp + cur);

    return ans;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cout << solve() << endl;

    return 0;
}
