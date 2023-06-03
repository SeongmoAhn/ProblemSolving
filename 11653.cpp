#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define PRIME false
#define NOT_PRIME true

vector<bool> v(10000001);
vector<int> prime;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    cin >> n;
    for (i = 2; i <= sqrt(n); i++) {
        if (v[i] == PRIME) {
            int j = 2;
            while (i * j <= n) {
                v[i * j] = NOT_PRIME;
                j++;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        if (v[i] == PRIME)
            prime.push_back(i);
    }

    i = 0;
    while (n != 1) {
        if ((n % prime[i]) == 0) {
            cout << prime[i] << '\n';
            n /= prime[i];
        }
        else {
            i++;
        }
    }

    return 0;
}
