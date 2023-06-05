#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input;
    for (int i = 0; i < 3; i++) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    int small = v[0] + v[1];

    while (v[2] >= small)
        v[2]--;

    cout << v[0] + v[1] + v[2] << '\n';

    return 0;
}
