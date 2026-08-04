#include <iostream>
#include <string>
using namespace std;
string input;
int main() {
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            cout << (char)(input[i] - 32);
        }
        else {
            cout << (char)(input[i] + 32);
        }
    }
}
