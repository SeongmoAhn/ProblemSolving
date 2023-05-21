#include <cmath>
#include <iostream>
using namespace std;

void hanoiTower(int n, int from, int by, int to) {
    if (n == 1) {
        cout << from << " " << to << '\n';
        return;
    }
    hanoiTower(n - 1, from, to, by);
    cout << from << " " << to << '\n';
    hanoiTower(n - 1, by, from, to);
}

int main(void)
{
    int n;
    int cnt = 1;
    int x;
    cin >> n;
    string count = to_string(pow(2, n));

    x = count.find('.');
    count = count.substr(0, x);
    count[count.length() - 1] -= 1;

    cout << count << '\n';

    if (n <= 20)
        hanoiTower(n, 1, 2, 3);

	return 0;
}
