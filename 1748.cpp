#include <iostream>
#include <string>
using namespace std;

int ans;

int main(void) {
    string N; cin >> N;
    int i, cur = 9, start = 1;
    for (i = 1; i < N.size(); i++, cur *= 10, start *= 10)
        ans += cur * i;
    ans += (stoi(N) - start + 1) * i;
    cout << ans << endl;
}
