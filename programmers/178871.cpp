#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;
    for (int i = 0; i < players.size(); i++) m[players[i]] = i;

    for (auto name : callings) {
        auto cur = m[name];
        auto front = players[cur - 1];
        swap(players[cur], players[cur - 1]);
        m[name] = cur - 1;
        m[front] = cur;
    }

    return players;
}

int main(void) {
    for (string s : solution({"mumu", "soe", "poe", "kai", "mine"}, {"kai", "kai", "mine", "mine"})) cout << s << " ";
    cout << endl;
}
