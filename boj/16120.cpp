#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define endl '\n'

const string ppap = "PPAP";
string input, result = "";


void initInput() {
    cin >> input;
}

void solve() {
    for (int i = 0; i < input.size(); i++) {
        result += input[i];

        if (result.back() == 'P') {
            if (result.length() < 4) continue;

            bool check = true;
            for (int j = 0; j < 4; j++) {
                if (result[result.length() - 4 + j] != ppap[j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                for (int j = 0; j < 3; j++) {
                    result.pop_back();
                }
            }
        }
    }
    if (!result.compare("P")) cout << "PPAP" << endl;
    else cout << "NP" << endl;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    initInput();
    solve();

    return 0;
}
