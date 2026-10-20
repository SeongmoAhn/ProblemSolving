#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // (n X m) * (m X p) => n X p
    int n = arr1.size(), m = arr2.size(), p = arr2[0].size();
    vector<vector<int>> ans(n, vector<int>(p, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return ans;
}

int main(void) {
    for (auto& row : solution({{1, 4}, {3, 2}, {4, 1}}, {{3, 3}, {3, 3}})) { for (int x : row) cout << x << " "; cout << endl; }
    cout << endl;
    for (auto& row : solution({{2, 3, 2}, {4, 2, 4}, {3, 1, 4}}, {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}})) { for (int x : row) cout << x << " "; cout << endl; }
    cout << endl;
}
