#include <iostream>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k, i, j;
    bool arr[1001] = {0, };
    int count = 0;
    cin >> n >> k;
    
    for (i = 2; i <= n; i++) {
        for (j = i; j <= n; j += i) {
            if (arr[j] == false) {
                arr[j] = true;
                count++;
            }
            if (count == k) {
                cout << j << '\n';
                return 0;
            }
        }
    }

	return 0;
}
