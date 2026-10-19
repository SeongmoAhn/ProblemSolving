#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s(phone_book.begin(), phone_book.end());
    for (const string& phone : phone_book) {
        string temp = "";
        for (int i = 0; i + 1 < phone.size(); i++) {
            temp += phone[i];
            if (s.count(temp)) return false;
        }
    }
    return true;
}

int main(void) {
    cout << solution({"119", "97674223", "1195524421"}) << endl;
    cout << solution({"123", "456", "789"}) << endl;
    cout << solution({"12", "123", "1235", "567", "88"}) << endl;
}
