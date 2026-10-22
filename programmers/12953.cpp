#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int solution(vector<int> arr) {
    int ans = 1;
    for (auto a : arr) ans = lcm(ans, a);
    return ans;
}

int main(void) {
    cout << solution({2, 6, 8, 14}) << endl;
    cout << solution({1, 2, 3}) << endl;
}
