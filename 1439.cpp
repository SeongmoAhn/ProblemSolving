#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    string inputStr;
    cin >> inputStr;
    int len = inputStr.size();
    int i;
    int count0 = 0, count1 = 0;

    if (inputStr[0] == '1') {
        count0++;
    }
    else {
        count1++;
    }

    for (i = 0; i < len - 1; i++) {
        if (inputStr[i] != inputStr[i + 1]) {
            if (inputStr[i + 1] == '1') {
                count0++;
            }
            else {
                count1++;
            }
        }
    }

    cout << min(count0, count1) << '\n';

	return 0;
}
