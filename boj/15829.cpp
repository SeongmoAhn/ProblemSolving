#include <cmath>
#include <deque>
#include <iostream>
using namespace std;

const int M = 1234567891;

int main(void)
{
    int length;
    cin >> length;
    string input;
    cin >> input;
    int temp;
    long long r = 1;
    long long hash = 0;
    int i;

    for (i = 0; i < length; i++) {
        temp = input[i] - 96;
        hash = (hash + (temp) * r) % M;
        r = (r * 31) % M;
    }

    cout << hash << endl;

	return 0;
}
