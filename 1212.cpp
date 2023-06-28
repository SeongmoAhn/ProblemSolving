#include <iostream>
#include <string>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE

string input;
string temp;

void getBinary(int x, int cnt) {
    if (cnt == 3) return;
    getBinary(x / 2, cnt + 1);
    temp += x % 2 + '0';
}

void solve() {
    int cur = input[0] - '0';
    getBinary(cur, 0);
    cout << stoi(temp);

    for (int i = 1; i < input.size(); i++) {
        temp.clear();
        cur = input[i] - '0';
        getBinary(cur, 0);
        cout << temp;
    }
    cout << endl;
}

int main(void)
{
    PS_INPUT; 
    cin >> input;
    solve();

    return 0;
}
