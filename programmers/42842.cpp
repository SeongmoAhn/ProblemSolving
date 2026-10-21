#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int n = brown + yellow;
    for (int i = 3; ; i++) {
        for (int j = 3; j <= i; j++) {
            if (i * j == n && (i - 2) * (j - 2) == yellow) return {i, j};
            if (i * j > n) break;
        }
    }
}

int main(void) {
    for (int x : solution(10, 2)) cout << x << " ";
    cout << endl;
    for (int x : solution(8, 1)) cout << x << " ";
    cout << endl;
    for (int x : solution(24, 24)) cout << x << " ";
    cout << endl;
}
