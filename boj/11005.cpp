#include <deque>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string input;
int n;
deque<int> dq;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> input >> n;
    int num = stoi(input);

    while (num >= 1) {
        int cur = num % n;
        num /= n;
        dq.push_front(cur);
    }

    for (int i = 0; i < dq.size(); i++) {
        int cur = dq[i];
        if (cur >= 0 && cur <= 9) {
            cout << cur;
        }
        else {
            cout << (char)(cur - 10 + 'A');
        }
    }
    cout << '\n';

    return 0;
}
