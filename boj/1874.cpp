#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    stack<int> s;
    vector<char> v;
    int n, i, input;
    int sequency = 1;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> input;

        while (sequency <= input) {
            s.push(sequency++);
            v.push_back('+');
        }

        if (s.top() == input) {
            s.pop();
            v.push_back('-');
        }

        else {
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

	return 0;
}
