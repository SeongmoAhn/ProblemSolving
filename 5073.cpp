#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input;
    while (1) {
        vector<int> v;
        int sum = 0;

        for (int i = 0; i < 3; i++) {
            cin  >> input;
            v.push_back(input);
            sum += input;
        }

        if (sum == 0)
            return 0;

        sort(v.begin(), v.end());

        if (v[0] + v[1] <= v[2]) {
            cout << "Invalid" << '\n';
            continue;
        }

        int cnt = 0;
        for (int i = 0; i < 2; i++) {
            if (v[i] != v[i + 1])
                cnt++;
        }

        if (cnt == 0) {
            cout << "Equilateral" << '\n';
            continue;
        }
        else if (cnt == 1) {
            cout << "Isosceles" << '\n';
            continue;
        }
        else {
            cout << "Scalene" << '\n';
        }
    }

    return 0;
}
