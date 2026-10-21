#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long solution(int n) {
    int dp[2001] = {1, 1};
    for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    return dp[n];
}

int main(void) {
    cout << solution(4) << endl;
    cout << solution(3) << endl;
}
