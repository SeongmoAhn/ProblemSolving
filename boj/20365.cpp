#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<char> v;

int solve()
{
    int N; cin >> N;
    char c, before = 'A';
    for (int i = 0; i < N; i++) {
        cin >> c;

        if (c != before) {
            before = c;
            v.push_back(c);
        }
    }

    int b = 0, r = 0;
    for (char ch : v) {
        ch == 'B' ? b++ : r++;
    }

    return min(b, r) + 1;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cout << solve() << endl;

    return 0;
}