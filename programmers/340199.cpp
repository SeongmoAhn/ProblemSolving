#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int row = max(wallet[0], wallet[1]); // 긴 쪽이 row
    int col = min(wallet[0], wallet[1]); // 짧은 쪽이 col

    int cnt = 0;
    int M = max(bill[0], bill[1]);
    int m = min(bill[0], bill[1]);
    while (1) {
        if (M <= row && m <= col) return cnt;
        int temp = M / 2;
        M = max(m, temp);
        m = min(m, temp);
        cnt++;
    }
}

int main(void) {
    cout << solution({30, 15}, {26, 17}) << endl;
    cout << solution({50, 50}, {100, 241}) << endl;
}
