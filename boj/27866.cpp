#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string input;
    int n;
    cin >> input;
    cin >> n;
    cout << input[n - 1] << '\n';

    return 0;
}
