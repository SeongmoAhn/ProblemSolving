#include <iostream>
#include <algorithm>
using namespace std;

bool compare(char p, char n) {
    return p > n;
}

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string input;
    cin >> input;
    int len = input.size(), i, j;
    int sum = 0;
    bool zeroCheck = true;

    sort(input.begin(), input.end(), compare);

    if (input[len - 1] != '0') { // 0이 없으면 -1 출력
        cout << "-1" << '\n';
        return 0;
    }

    for (i = 0; i < len; i++) {
        sum += input[i] - '0';
    }

    if (sum % 3 != 0)  { // 합이 3의 배수가 아니면 -1출력
        cout << "-1" << '\n';
        return 0;
    }

    cout << input << endl;
	return 0;
}
