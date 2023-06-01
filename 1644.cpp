#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define PRIME false
#define NOT_PRIME true

vector<bool> table(4000001);

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    cin >> n;
    vector<int> primeArr;

    for (i = 2; i <= sqrt(n); i++) {
        if (table[i] == PRIME) {
            j = 2;
            while (i * j <= n) {
                table[i * j] = NOT_PRIME;
                j++;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        if (table[i] == PRIME)
            primeArr.push_back(i);
    }

    int start = 0, end = 0;
    int count = 0;
    int sum = 0;
    while (1) {
        if (sum >= n) {
            sum -= primeArr[start++];
        }
        else if (end == primeArr.size()) {
            break;
        }
        else {
            sum += primeArr[end++];
        }

        if (sum == n) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
