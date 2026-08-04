#include <iostream>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, i;
    int sum = 0;
    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> input;
        sum += input - 1;
    }
    cin >> input;
    sum += input;
    cout << sum << '\n';

    return 0;
}
