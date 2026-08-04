#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n , result = -1, temp = 0;
int visited[9], input[9];
vector<int> v;

void solve() {
    if (v.size() == n) {
        temp = 0;
        for (int i = 0; i < n - 1; i++) {
            temp += abs(v[i] - v[i + 1]);
        }
        result = max(temp, result);

        return ;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(input[i]);
            solve();
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> input[i]; }

    solve();
    cout << result << '\n';

    return 0;
}
