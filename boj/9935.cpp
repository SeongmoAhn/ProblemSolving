#include <iostream>
#include <string>
using namespace std;

string input, boom;
string result = "";

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> input >> boom;
    for (int i = 0; i < input.length(); i++) {
        result += input[i];

        if (result.back() == boom.back()) {
            if (result.length() < boom.length()) continue;

            bool check = 1;
            for (int j = 0; j < boom.length(); j++) {
                if (result[result.length() - boom.length() + j] != boom[j]) {
                    check = 0;
                    break;
                }
            }

            if (check) {
                for (int j = 0; j < boom.length(); j++) result.pop_back();
            }
        }
    }

    if (!result.length()) cout << "FRULA" << '\n';
    else cout << result << '\n';

    return 0;
}
