#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;
bool check[2002];

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (!check[input + 1000]) {
            check[input + 1000] = 1;
            v.push_back(input);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';

    return 0;
}
