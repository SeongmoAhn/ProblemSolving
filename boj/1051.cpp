#include <algorithm>
#include <iostream>
using namespace std;

int arr[51][51];

int main()
{
    string input;
    int n = 3, m = 5;
    int i, j;
    int maxsize = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> input;
        for (j = 0; j < input.length(); j++) {
            arr[i][j] = input[j] - '0';
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (int k = 0;; k++) {
                if ((i + k) == n || (j + k) == m) {
                    break;
                }
                if ((arr[i][j] == arr[i][j + k]) && (arr[i][j + k] == arr[i + k][j + k]) && (arr[i + k][j] == arr[i + k][j + k]) && (arr[i][j] == arr[i + k][j])) {
                    maxsize = max(maxsize, k);
                }
            }
        }
    }
    maxsize += 1;
    maxsize *= maxsize;
    cout << maxsize << endl;

    return 0;
}
