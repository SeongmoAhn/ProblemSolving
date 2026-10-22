#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int n = elements.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int len = 0; len < n; len++) {
            sum += elements[(i + len) % n];
            s.insert(sum);
        }
    }

    return s.size();
}

int main(void) {
    cout << solution({7, 9, 1, 1, 4}) << endl;
}
