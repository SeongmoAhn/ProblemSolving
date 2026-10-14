#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<>());
    int ans = 0;
    for (int i = m - 1; i < score.size(); i += m) ans += score[i] * m;

    return ans;
}

int main(void) {
    cout << solution(3, 4, {1, 2, 3, 1, 2, 3, 1}) << endl;
    cout << solution(4, 3, {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2}) << endl;
}
