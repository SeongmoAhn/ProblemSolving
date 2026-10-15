#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define pii pair<int, int>

string solution(vector<int> numbers, string hand) {
    map<int, pii> m = {
        {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}},
        {4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}},
        {7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}},
        {0, {3, 1}}
    };

    pii l = {3, 0}, r = {3, 2};
    string ans = "";
    for (auto n : numbers) {
        if (n == 1 || n == 4 || n == 7) { // L
            l = m[n];
            ans += "L";
        } else if (n == 3 || n == 6 || n == 9) { // R
            r = m[n];
            ans += "R";
        } else {
            int distLeft = abs(l.first - m[n].first) + abs(l.second - m[n].second);
            int distRight = abs(r.first - m[n].first) + abs(r.second - m[n].second);

            if (distLeft < distRight) {
                l = m[n];
                ans += "L";
            } else if (distLeft > distRight) {
                r = m[n];
                ans += "R";
            } else {
                if (hand[0] == 'r') {
                    r = m[n];
                    ans += "R";
                } else {
                    l = m[n];
                    ans += "L";
                }
            }
        }
    }

    return ans;
}

int main(void) {
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << endl;
    cout << solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left") << endl;
    cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right") << endl;
}
