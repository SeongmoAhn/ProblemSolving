#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define PRIME false
#define NOT_PRIME true

vector<bool> prime(10001);
vector<int> primeV;
int a, b;
int sum;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> a >> b;

    prime[0] = prime[1] = NOT_PRIME;
    for (int i = 2; i <= sqrt(10001); i++) {
        if (prime[i] == PRIME) {
            int j = 2;
            while (i * j <= 10001) {
                prime[i * j] = NOT_PRIME;
                j++;
            }
        }
    }

    for (int i = a; i <= b; i++) {
        if (prime[i] == PRIME) {
            sum +=i;
            primeV.push_back(i);
        }
    }

    if (primeV.empty()) {
        cout << -1 << '\n';
    }
    else {
        cout << sum << " " << primeV[0] << '\n';
    }

    return 0;
}
