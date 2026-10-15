#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        int num = arr1[i] | arr2[i];

        string str = "";
        for (int i = 0; i < n; i++) {
            str += num % 2 ? '#' : ' ';
            num /= 2;
        }
        reverse(str.begin(), str.end());
        ans.push_back(str);
    }
    return ans;
}

int main(void) {
    for (string s : solution(5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28})) cout << s << " ";
    cout << endl;
    for (string s : solution(6, {46, 33, 33, 22, 31, 50}, {27, 56, 19, 14, 14, 10})) cout << s << " ";
    cout << endl;
}
