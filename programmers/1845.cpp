#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> nums) {
    bool a[10000000] = {0};
    int cnt = 0;
    for (auto n : nums) {
        if (!a[n]) {
            a[n] = true;
            cnt++;
        }
    }
    return min(cnt, (int)nums.size() / 2);
}

int main(void) {
    cout << solution({3, 1, 2, 3}) << endl;
    cout << solution({3, 3, 3, 2, 2, 4}) << endl;
    cout << solution({3, 3, 3, 2, 2, 2}) << endl;
}
