#include <iostream>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m = 1, k = 1, i, j;
    cin >> input;
    m = input - 1;

    for (i = 1; i <= (2 * input) - 1; i += 2) {
        n = m--;
        while (n > 0) {
            cout << " ";
            n--;
        }
        for (j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (i = (2 * input) - 3; i >= 1; i -= 2) {
        n = k++;
        while (n > 0) {
            cout << " ";
            n--;
        }
        for (j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
