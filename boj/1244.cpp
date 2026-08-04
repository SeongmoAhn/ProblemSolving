#include <iostream>
using namespace std;
#define endl '\n'
#define SIZE 101

int N, T, sex, num;
bool arr[SIZE];

void initInput() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> T;
}

void male() {
    for (int i = num; i <= N; i += num)
        arr[i] = !arr[i];
}

void female() {
    arr[num] = !arr[num];
    for (int i = 1; arr[num - i] == arr[num + i]; i++) {
        if (num - i < 1 || num + i > N) return ;
        arr[num - i] = arr[num + i] = !arr[num + i];
    }
}

void solve() {
    while (T--) {
        cin >> sex >> num;
        sex == 1 ? male() : female();
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
        (i % 20 == 0) && cout << endl;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
