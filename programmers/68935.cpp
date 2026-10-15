#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(int n) {
    string str = "";
    while (n) {
        str += (n % 3) + '0';
        n /= 3;
    }

    int ans = 0;
    int cur = 1;
    while (str.size()) {
        ans += (str[str.size() - 1] - '0') * cur;
        cur *= 3;
        str.pop_back();
    }
    return ans;
}

int main(void) {
    cout << solution(45) << endl;
    cout << solution(125) << endl;
}
