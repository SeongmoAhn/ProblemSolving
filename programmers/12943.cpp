#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(int num) {
    long long n = num;
    if (n == 1) return 0;

    int cnt = 0;
    while (cnt++ < 500) {
        if (n % 2) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }

        if (n == 1) return cnt;
    }
    return -1;
}

int main(void) {
    cout << solution(16) << endl;
    cout << solution(626331) << endl;
}
