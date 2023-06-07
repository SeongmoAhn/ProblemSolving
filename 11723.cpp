#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> v(21);
int n, x;
string input;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;

        if (input == "add") {
            cin >> x;
            v[x] = 1;
        }
        else if (input == "remove") {
            cin >> x;
            v[x] = 0;
        }
        else if (input == "check") {
            cin >> x;
            cout << v[x] << '\n';
        }
        else if (input == "toggle") {
            cin >> x;
            if (v[x])
                v[x] = 0;
            else
                v[x] = 1;
        }
        else if (input == "all") {
            for (int i = 1; i < 21; i++) {
                v[i] = 1;
            }
        }
        else {
            for (int i = 1; i < 21; i++) {
                v[i] = 0;
            }
        }
    }

    return 0;
}
