#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000
const int PERIOD = MOD / 10 * 15;

ll N;
int fibonacci[PERIOD] = {0, 1};

void initInput() {
    cin >> N;
}

void solve() {
    for (int i = 2; i < PERIOD; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % MOD;

    cout << fibonacci[N % PERIOD] << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
