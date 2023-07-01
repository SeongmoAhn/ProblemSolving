#include <iostream>
#include <string>
#include <deque>
using namespace std;
#define endl '\n'
#define SIZE

int T;

void initInput() {
    cin >> T;
}

void solve() {
    while (T--) {
        string func; cin >> func;
        int len; cin >> len;
        string input; cin >> input;
        deque<int> dq;
        int i = 1;
        while (input[i] != '\0') {
            int temp = 0;
            while (input[i] >= '0' && input[i] <= '9') {
                temp = temp * 10 + (input[i] - '0');
                i++;
            }

            if (temp) {
                dq.push_back(temp);
            }
            i++;
        }
        
        bool flag = 1, error = 0;
        for (int i = 0; i < func.size(); i++) {
            if (func[i] == 'R') {
                flag = !flag;
            }
            else {
                if (dq.empty()) {
                    error = 1;
                    break;
                }

                if (flag) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (error) {
            cout << "error" << endl;
        }
        else {
            cout << '[';
            if (flag) {
                for (int i = 0; i < dq.size(); i++) {
                    cout << dq[i];
                    if (i != dq.size() - 1) cout << ',';
                }
            }
            else {
                for (int i = dq.size() - 1; i >= 0; i--) {
                    cout << dq[i];
                    if (i != 0) cout << ',';
                }
            }
            cout << ']' << endl;
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
