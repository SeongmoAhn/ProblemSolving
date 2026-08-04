#include <iostream>
#include <vector>
using namespace std;

int n, sum;
vector<int> v;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    while (1) {
        cin >> n;
        if (n == -1)
            return 0;
        v.clear();
        sum = 0;

        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                v.push_back(i);
                sum += i;
            }
        }

        if (sum != n) {
            cout << n << " is NOT perfect.\n";
        }
        else {
            cout << n << " = ";
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i != v.size() - 1) {
                    cout << " + ";
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
