#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solution(int x) {
    int sum = 0;
    int n = x;
    while (x) {
        sum += x % 10;
        x /= 10;
    }

    return n % sum == 0;
}

int main(void) {
    cout << solution(12) << endl;
    cout << solution(11) << endl;
}
