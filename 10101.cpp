#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, sum = 0;
vector<int> v;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input;
    for (int i = 0; i < 3; i++) {
        cin  >> input;
        v.push_back(input);
        sum += input;
    }

    if (sum != 180) {
        cout << "Error" << '\n';
        return 0;
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        if (v[i] != v[i + 1])
            cnt++;
    }

    if (cnt == 0) {
        cout << "Equilateral" << '\n';
        return 0;
    }
    else if (cnt == 1) {
        cout << "Isosceles" << '\n';
        return 0;
    }
    else {
        cout << "Scalene" << '\n';
    }

    return 0;
}
