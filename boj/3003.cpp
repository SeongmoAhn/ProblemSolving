#include <iostream>
#include <vector>
using namespace std;

vector<int> table = {1, 1, 2, 2, 2, 8};

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    for (i = 0; i < 6; i++) {
        cin >> input;
        cout << table[i] - input << " ";
    }
    cout << '\n';

    return 0;
}
