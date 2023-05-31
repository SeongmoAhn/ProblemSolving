#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    int one, ten, hund;
    cin >> num1 >> num2;

    one = num2 % 10; num2 = num2 / 10;
    ten = num2 % 10; num2 = num2 / 10;
    hund = num2 % 10; num2 = num2 / 10;

    cout << num1 * one << '\n' << num1 * ten << '\n' << num1 * hund << '\n';
    cout << num1 * one + (num1 * ten * 10) + (num1 * hund * 100) << '\n';

    return 0;
}
