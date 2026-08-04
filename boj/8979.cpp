#include <iostream>
#include <tuple>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N, M, ans = 1; cin >> N >> M;
    tuple<int, int, int> arr[1001];
    for (int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        arr[a] = {b, c, d};
    }

    for (int i = 1; i <= N; i++) {
        if (get<0>(arr[i]) == get<0>(arr[M])) {
            if (get<1>(arr[i]) == get<1>(arr[M])) {
                if (get<2>(arr[i]) > get<2>(arr[M]))
                    ans++;
            }
            else if (get<1>(arr[i]) > get<1>(arr[M])) {
                ans++;
            }
        }
        else if (get<0>(arr[i]) > get<0>(arr[M])) {
            ans++;
        }
    }

    cout << ans;
}
