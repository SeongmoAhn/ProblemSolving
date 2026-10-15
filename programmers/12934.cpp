#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long x = sqrtl(n);
    while (x * x < n) x++;
    while (x * x > n) x--;
    if (x * x == n) return (x + 1) * (x + 1);
    return -1;
}

int main(void) {
    cout << solution(121) << endl;
    cout << solution(3) << endl;
}
