#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n;
string input;
int sum;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> input >> n;

    for (int i = 0; i < input.length(); i++) {
        int temp = input[input.length() - i - 1];

        if (temp >= '0' && temp <= '9') {
            sum += (temp - '0') * (int)pow(n, i); 
        }
        else {
            sum += (temp - 'A' + 10) * (int)pow(n, i);
        }
    }
    cout << sum << '\n';

    return 0;
}
