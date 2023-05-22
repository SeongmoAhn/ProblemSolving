#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, i, j;
    int mid;
    int input;
    int sum = 0;
    int most = -1, mostValue;
    bool isFirst = false;
    vector<int> v;
    int count[8001] = {0,};
    cin >> n;
    mid = n / 2;

    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
        sum += input;
        count[input + 4000]++;
    }

    for(int i = 0; i < 8001; i++) {
        if(count[i] == 0)
            continue;

        if(count[i] == most) {
            if(isFirst)
            {
                mostValue = i - 4000;
                isFirst = false;
            }
        }

        if(count[i] > most) {
            most = count[i];
            mostValue = i - 4000;
            isFirst = true;
        }
    }
    sort(v.begin(), v.end());
    int mean = round((float)sum / n);
    int midValue = v[v.size() / 2];
    int scope = v.back() - v.front();

    cout << mean << '\n' << midValue << '\n' << mostValue << '\n' << scope << '\n';

	return 0;
}
