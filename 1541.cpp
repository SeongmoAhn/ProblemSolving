#include <iostream>
#include <string>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE
#define INF 1e9

string input;
int result;
bool minusChk;

void initInput() {
    cin >> input;
}

void solve() {
    int len = input.size();
    int temp = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            temp *= 10;
            temp += input[i] - '0';
        }

        else {
            if (minusChk) {
                result -= temp;
                temp = 0;
            }
            else {
                result += temp;
                temp = 0;
            }

            if (input[i] == '-') minusChk = 1;
        }
    }
    if (minusChk) result -= temp;
    else result += temp;
    cout << result << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
