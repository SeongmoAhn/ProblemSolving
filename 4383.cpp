#include <iostream>
#include <vector>
using namespace std;

bool checkJolly(int size) {
    int v[size];
    bool check[size];
    int i, diff;
    for (i = 0; i < size; i++) {
        scanf("%d", &v[i]);
        check[i] = false;
    }
    for (i = 0; i < size - 1; i++) {
        diff = abs(v[i] - v[i + 1]);
        if (diff >= size) {
            return false;
        }
        if (check[diff] == false) {
            check[diff] = true;
        }
        else {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int n, i;
    int trash;
    int result;
    while (EOF != scanf("%d", &n)) {
        if (n == 1) {
            cin >> trash;
            cout << "Jolly" << endl;
            continue;
        }
        result = checkJolly(n);
        if (result) {
            cout << "Jolly" << endl;
        }
        else {
            cout << "Not jolly" << endl;
        }
    }

	return 0;
}
