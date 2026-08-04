#include <iostream>
using namespace std;

int n = 5;
char input[5][16];
int maxLen;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 5; i++) {
            if (input[i][j] != '\0')
                cout << input[i][j];
        }
    }
    cout << '\n';

    return 0;
}
