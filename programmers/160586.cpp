#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    int cnt[26]; fill(cnt, cnt + 26, 1000);
    vector<int> ans;

    for (auto k : keymap) {
        for (int i = 0; i < k.size(); i++) {
            auto cur = cnt[k[i] - 'A'];
            cnt[k[i] - 'A'] = min(cnt[k[i] - 'A'], i + 1);
        }
    }

    for (auto t : targets) {
        int sum = 0;
        for (int i = 0; i < t.size(); i++) {
            if (cnt[t[i] - 'A'] == 1000) {
                sum = -1;
                break;
            }
            sum += cnt[t[i] - 'A'];
        }
        ans.push_back(sum);
    }

    return ans;
}

int main(void) {
    for (int x : solution({"ABACD", "BCEFD"}, {"ABCD", "AABB"})) cout << x << " ";
    cout << endl;
    for (int x : solution({"AA"}, {"B"})) cout << x << " ";
    cout << endl;
    for (int x : solution({"AGZ", "BSSS"}, {"ASA", "BGZ"})) cout << x << " ";
    cout << endl;
}
