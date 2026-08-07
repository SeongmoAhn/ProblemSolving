#include <iostream>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int type, n; cin >> type >> n;
    int arr[10000] = {0};
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[a]++;
        if (arr[a] > 1) flag = 1;
    }

    if (type == 1) {
        for (int i = 1; i <= 9; i++) {
            cout << i << ":" << arr[i] << "개" << endl;
        }
    } else { cout << (flag ? "중복발견" : "중복없음"); }

    return 0;
}
