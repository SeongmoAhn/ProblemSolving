#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v = {{1, 0}, {0, 1}};
vector<int> indexV;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int maxIndex = 0;
    int n;
    int input;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        indexV.push_back(input);
        if (input > maxIndex)
            maxIndex = input;
    }
    for (int j = 2; j <= maxIndex; j++) {
        v.push_back({v[j - 1].first + v[j - 2].first, v[j - 1].second + v[j - 2].second});
    }

    for (int i = 0; i < n; i++) {
        int j = indexV[i];
        cout << v[j].first << " " << v[j].second << '\n';
    }

	return 0;
}
