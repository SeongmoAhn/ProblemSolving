#include <iostream>
// #include <string>
#include <algorithm>
#include <vector>
// #include <queue>
// #include <deque>
using namespace std;

vector<int> v;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);

    int input, sum = 0;
    pair<int, int> p;
    for (int i = 0; i < 9; i++) {
        cin >> input;
        v.push_back(input);
        sum += input;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if ((sum - v[i] - v[j]) == 100) {
                p = {i, j};
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != p.first && i != p.second)
            cout << v[i] << '\n';
    }

    return 0;
}
