#include <iostream>
#include <string>
using namespace std;

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    string input; cin >> input;
    int ans = 10;
    char cur = input[0];
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == cur) 
            ans += 5;
        else {
            cur = input[i];
            ans += 10;
        }
    }
    cout << ans;
}
