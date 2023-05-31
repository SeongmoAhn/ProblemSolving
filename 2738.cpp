#include <iostream>
using namespace std;

int v1[100][100];
int v2[100][100];

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, i, j, n, m;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> input;
            v1[i][j] = (input);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> input;
            v2[i][j] = (input);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << v1[i][j] + v2[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
