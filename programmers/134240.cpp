#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string solution(vector<int> food) {
    string str = "";
    int idx = 0;
    for (auto f : food) {
        while (f > 1) {
            str += to_string(idx);
            f -= 2;
        }
        idx++;
    }

    string ans = str + "0";
    reverse(str.begin(), str.end());
    return ans + str;
}

int main(void) {
    cout << solution({1, 3, 4, 6}) << endl;
    cout << solution({1, 7, 1, 2}) << endl;
}
