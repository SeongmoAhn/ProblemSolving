#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++) 
        sum += a[i] * b[i];
    return sum;
}

int main(void) {
    cout << solution({1, 2, 3, 4}, {-3, -1, 0, 2}) << endl;
    cout << solution({-1, 0, 1}, {1, 0, -1}) << endl;
}
