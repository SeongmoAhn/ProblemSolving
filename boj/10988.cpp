#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, i, j;
    string input;
    cin >> input;
    bool flag = 1;

    if (input.length() == 1) {
        cout << flag << '\n';
        return 0;
    }

    for (i = 0; i <= input.length() / 2 - 1; i++) {
        if (input[i] != input[input.length() - 1 - i]) {
            flag = 0;
            break;
        }
    }

    cout << flag << '\n';

    return 0;
}
