#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for (auto v : clothes) {
        m[v[1]]++;
    }

    int ans = 1;
    for (auto &[key, value] : m) {
        ans *= value + 1;
    }
    return ans - 1;
}

int main(void) {
    cout << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}) << endl;
    cout << solution({{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}) << endl;
}
