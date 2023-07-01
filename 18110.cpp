#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define endl '\n'

int n;
double sum;
vector<int> input;

void initInput() {
    cin >> n;
    if (!n) {
        cout << 0 << endl;
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        input.push_back(temp);
    }
    sort(input.begin(), input.end());
}

void solve() {
    double remove = round(n * 0.15);
    for (int i = remove; i < n - remove; i++) {
        sum += input[i];
    }
    sum /= (n - remove * 2);
    cout << round(sum) << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
