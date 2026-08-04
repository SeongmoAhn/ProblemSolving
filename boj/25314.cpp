#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    int i;
    cin >> n;

    while (n >= 4) {
        cout << "long ";
        n -= 4;
    }
    cout << "int" << '\n';

	return 0;
}
