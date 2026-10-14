#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int cnt = 1;
    int front = section[0];
    int back = front + m - 1;
    for (auto s : section) {
        if (s <= back) continue;
        else {
            front = s;
            back = front + m - 1;
            cnt++;
        }
    }

    return cnt;
}

int main(void) {
    cout << solution(8, 4, {2, 3, 6}) << endl;
    cout << solution(5, 4, {1, 3}) << endl;
    cout << solution(4, 1, {1, 2, 3, 4}) << endl;
}
