#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());

    int sum = 0, cnt = 0;
    for (int n : d) {
        if (sum + n > budget) break;

        sum += n;
        cnt++;
    }

    return cnt;
}

int main(void) {
    cout << solution({1, 3, 2, 5, 4}, 9) << endl;
    cout << solution({2, 2, 3, 3}, 10) << endl;
}
