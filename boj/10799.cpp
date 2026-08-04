#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

string input;
vector<int> s;
int cnt = 0;

void initInput() {
    cin >> input;
}
void solve() {
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            s.push_back(i);
            if (input[i + 1] == ')') {
                s.pop_back();
                cnt += s.size();
                i++;
            }
        }
        else {
            s.pop_back();
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
