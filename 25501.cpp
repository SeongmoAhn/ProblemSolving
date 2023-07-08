#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define SIZE

int T;
ll cnt;

int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

void initInput() {
    cin >> T;
}

void solve() {
    while (T--) {
        char input[1001];
        cin >> input;
        cnt = 0;
        cout << isPalindrome(input) << ' ' << cnt << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
