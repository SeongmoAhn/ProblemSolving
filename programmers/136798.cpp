#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> getCount(int n) {
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) cnt++;
        }
        ret.push_back(cnt);
    }
    return ret;
}

int solution(int number, int limit, int power) {
    int cnt = 0;
    for (auto n : getCount(number)) {
        cnt += n > limit ? power : n;
    }
    return cnt;
}

int main(void) {
    cout << solution(5, 3, 2) << endl;
    cout << solution(10, 3, 2) << endl;
}
