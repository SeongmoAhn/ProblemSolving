#include <iostream>
using namespace std;
#define SIZE 200001

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int list[SIZE];
    int N, M, V;
    cin >> N >> M >> V;
    for (int i = 0; i < N; i++)
        cin >> list[i];
    V--;
    int mod = N - V;
    while (M--) {
        int input; cin >> input;
        cout << (input < N ? list[input] : list[(input - V) % mod + V]) << '\n';
    }
}
