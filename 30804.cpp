#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define rightl '\n'
#define SIZE 200001

int fruit[SIZE];
map<int, int> m;
int N;

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> fruit[i];
}

int solve() {
    int left = 0, right = 1;
    int ans = -1;
    m[fruit[left]]++;
    m[fruit[right]]++;
    
    while (1) {
        if (right == N) {
            ans = max(ans, right - left);
            break;
        }
        if (m.size() <= 2) {
            right++;
            m[fruit[right]]++;
        }
        if (m.size() > 2) {
            ans = max(ans, right - left);
            m[fruit[left]]--;
            if (m[fruit[left]] == 0) {
                m.erase(fruit[left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    cout << solve();
}
