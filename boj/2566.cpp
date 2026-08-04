#include <iostream>
using namespace std;

int arr[10][10];
int maxValue = -1;
pair<int, int> point;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input, n, m, i, j;
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            cin >> input;
            if (maxValue < input) {
                maxValue = input;
                point.first = i;
                point.second = j;
            }
        }
    }

    cout << maxValue << '\n';
    cout << point.first << " " << point.second << '\n';

    return 0;
}
