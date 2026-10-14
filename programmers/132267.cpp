#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(int a, int b, int n) {
    int ans = 0;
    while (n >= a) {
        int get = (n / a) * b;
        ans += get;
        n = (n % a) + get;
    }

    return ans;
}

int main(void) {
    cout << solution(2, 1, 20) << endl;
    cout << solution(3, 1, 20) << endl;
}
