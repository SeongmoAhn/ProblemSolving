#include <iostream>
#include <string>
#include <map>
using namespace std;
#define endl '\n'
#define SIZE 100001

int n, m;
map<string, int> book;
string name[SIZE];

void initInput() {
    cin >> n >> m;
    string input;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        name[i] = input;
        book.insert({input, i});
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (input[0] >= '1' && input[0] <= '9') {
            cout << name[stoi(input)] << endl;
        }
        else {
            map<string, int>::iterator iter = book.find(input);
            cout << iter->second << endl;
        }
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
