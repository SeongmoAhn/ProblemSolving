#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
vector<char> s;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> input;

    for (int i = 0; i < input.size(); i++) {
        char cur = input[i];
        if (cur >= 'A' && cur <= 'Z') cout << cur;

        else {
            if (cur == '(')
                s.push_back(cur);
            else if (cur == ')') {
                while (!s.empty() && s.back() != '(') {
                    cout << s.back();
                    s.pop_back();
                }
                s.pop_back();
            }
            else if (cur == '+' || cur == '-') {
                while (!s.empty() && s.back() != '(') {
                    cout << s.back();
                    s.pop_back();
                }
                s.push_back(cur);
            }
            else if (cur == '*' || cur == '/') {
                while (!s.empty() && (s.back() == '*' || s.back() == '/')) {
                    cout << s.back();
                    s.pop_back();
                }
                s.push_back(cur);
            }
        }
    }
    
    while (!s.empty()) {
        cout << s.back();
        s.pop_back();
    }

    return 0;
}
