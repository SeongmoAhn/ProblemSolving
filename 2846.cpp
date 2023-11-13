#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 1001

int main() {
    // freopen("input.txt", "r", stdin);
    int N; cin >> N;
    int ans = 0, input[SIZE];
    int l = 1, r = 1;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
    for (int i = 1; i <= N - 1; i++) {
        if (input[i] < input[i + 1])
            ans = max(ans, input[++r] - input[l]);
        else if(input[i] >= input[i + 1])
            l = r = i + 1;
    }
    cout << ans << '\n';
}
