#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for (auto c : completion) m[c]++;

    for (auto p : participant) {
        if (m[p]) m[p]--;
        else return p;
    }
}

int main(void) {
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << endl;
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl;
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << endl;
}
