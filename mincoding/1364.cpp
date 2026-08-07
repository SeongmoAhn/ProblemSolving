#include <iostream>
#include <string>
using namespace std;
int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int arr[20] = {0};
    arr[1] = 3;
    arr[2] = 3;
    arr[3] = 3;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 2;
    arr[9] = 1;
    int a; cin >> a;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == a) cout << i << ' ';
    }

    return 0;
}
