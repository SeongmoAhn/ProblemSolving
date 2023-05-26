#include <iostream>
using namespace std;

int main(void)
{
    int check[31] = {0, };
    int input;
    int count = 0;

    for (int i = 0; i < 28; i++) {
        cin >> input;
        check[input] = 1;
    }

    for (int i = 1; i < 31; i++) {
        if (check[i] == 0) {
            cout << i << '\n';
            count++;
        }
        if (count == 2)
            break;
    }

	return 0;
}
