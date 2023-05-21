#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
int main() {
    char ch;
    bool flag;
    string input;
    int strLength;

    while (1) {
        input;
        stack<char> s;
        flag = 0;
        getline(cin, input);
        strLength = input.length();
 
        if (input == ".") {
            break;
        }
 
        for (int i = 0; i < strLength; i++) {
            ch = input[i];
                
            if ((ch == '(') || (ch == '[')) {
                s.push(ch);
            }
            else if (ch == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    flag = 1;
                    break;
                }
            }
            else if (ch == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    flag = 1;
                    break;
                }
            }
        }
 
        if (flag == 0 && s.empty()) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}
