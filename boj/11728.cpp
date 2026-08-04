#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input;
    int n, m, i;
    vector<int> v1;

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> input;
        v1.push_back(input);
    }
    for (i = 0; i < m; i++) {
        cin >> input;
        v1.push_back(input);
    }

    sort(v1.begin(), v1.end());
    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << '\n';

	return 0;
}
