#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> topping) {
    int cnt1[10001] = {0};
    int cnt2[10001] = {0};
    int type1 = 0, type2 = 0;
    for (auto t : topping) {
        if (cnt1[t] == 0) type1++;
        cnt1[t]++;
    }

    int ans = 0;
    for (auto t : topping) {
        cnt1[t]--;
        if (cnt1[t] == 0) type1--;

        if (cnt2[t] == 0) type2++;
        cnt2[t]++;

        if (type1 == type2) ans++;
    }
    return ans;
}

int main(void) {
    cout << solution({1, 2, 1, 3, 1, 4, 1, 2}) << endl;
    cout << solution({1, 2, 3, 1, 4}) << endl;
}
