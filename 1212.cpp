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

void initInput() {
    cin >> input;
}

void getBinary(int x, int cnt) {
    if (cnt == 3) return;
    getBinary(x / 2, cnt + 1);
    cout << x % 2;
}

void solve() {
    int cur = input[0] - '0';
    string temp;
    for (int i = 0; i < 3; i++) {
        temp += cur % 2 + '0';
        cur /= 2;
    }
    char a = temp[0];
    temp[0] = temp[2];
    temp[2] = a;
    cout << stoi(temp);

    for (int i = 1; i < input.size(); i++) {
        cur = input[i] - '0';
        getBinary(cur, 0);
    }
    cout << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
