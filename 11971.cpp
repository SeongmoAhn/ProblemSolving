#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int N, M, ans;
int road[101];

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    int prev = 0;
    for (int i = 0; i < N; i++) {
        int input1, input2; cin >> input1 >> input2;
        for (int j = prev; j < prev + input1; j++) road[j] = input2;
        prev += input1;
    }
    prev = 0;
    for (int i = 0; i < M; i++) {
        int input1, input2; cin >> input1 >> input2;
        for (int j = prev; j < prev + input1; j++) {
            if (road[j] < input2) ans = max(input2 - road[j], ans);
        }
        prev += input1;
    }
    cout << ans << endl;
}
