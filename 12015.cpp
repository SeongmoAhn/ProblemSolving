#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 1000001

int N;
int input[SIZE], idx[SIZE];
vector<int> v;

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (v.size() == 0 || v[v.size() - 1] < input[i]) {
            v.push_back(input[i]);
            idx[i] = v.size() - 1;
        }
        else {
            int left = 0;
            int right = v.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                
                if (v[mid] >= input[i]) right = mid;
                else left = mid + 1;
            }
            v[left] = input[i];
            idx[i] = left;
        }
    }

    cout << v.size() << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
