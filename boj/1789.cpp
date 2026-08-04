#include <iostream>
using namespace std;

int main(void) {
    long long S; cin >> S;
    long long sum = 0, i;
    for (i = 1; ; i++) {
        sum += i;
        if (sum > S) break;
    }
    cout << i - 1 << '\n';
}
