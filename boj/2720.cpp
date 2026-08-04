#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int testCase, money;
vector<int> returnMoney(4);
int coins[] = {25, 10, 5, 1};

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;
    returnMoney.clear();
    for (int i = 0; i < testCase; i++) {
        cin >> money;

        for (int j = 0; j < 4; j++) {
            int cnt = 0;
            while (money >= coins[j]) {
                cnt++;
                money -= coins[j];
            }
            returnMoney[j] = cnt;
        }

        for (int j = 0; j < 4; j++) {
            cout << returnMoney[j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
