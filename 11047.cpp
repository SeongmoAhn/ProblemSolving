#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    vector<int> coins;
    int money;
    cin >> n >> money;
    for (i = 0; i < n; i++) {
        cin >> input;
        coins.push_back(input);
    }
    sort(coins.begin(), coins.end(), greater<>());

    int cnt = 0;
    i = 0;
    while (money != 0) {
        while (money >= coins[i]) {
            cnt++;
            money -= coins[i];
        }
        i++;
    }
    cout << cnt << '\n';

    return 0;
}
