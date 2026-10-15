#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end());

    int total = stages.size();
    int idx = 0;
    vector<pair<double, int>> v;
    for (int stage = 1; stage <= N; stage++) {
        int tried = 0;
        for (int i = idx; i < stages.size(); i++) {
            if (stages[i] == stage) tried++;
            else {
                idx = i;
                break;
            }
        }
        if (total == 0) v.push_back({0.0, stage});
        else v.push_back({(double)tried / total, stage});
        total -= tried;
    }

    sort(v.begin(), v.end(), [](const pair<double, int> &a, const pair<double, int> &b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    vector<int> ans;
    for (auto cur : v) {
        ans.push_back(cur.second);
    }
    return ans;
}

int main(void) {
    for (int x : solution(5, {2, 1, 2, 6, 2, 4, 3, 3})) cout << x << " ";
    cout << endl;
    for (int x : solution(4, {4, 4, 4, 4, 4})) cout << x << " ";
    cout << endl;
}
