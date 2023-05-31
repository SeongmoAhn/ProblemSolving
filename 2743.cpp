#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string input;
    cin >> input;
    cout << input.length() << '\n';

    return 0;
}
