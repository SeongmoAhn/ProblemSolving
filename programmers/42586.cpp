#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<pair<int, int>> q;
    vector<int> ans;
    for (int i = 0; i < progresses.size(); i++) q.push({progresses[i], speeds[i]});

    while(!q.empty()) {
        int size = q.size();
        int cnt = 0;
        bool distribute = false;
        bool block = false;
        for (int i = 0; i < size; i++) {
            auto cur = q.front(); q.pop();
            cur.first += cur.second;

            if (i == 0) {
                if (cur.first >= 100) { distribute = true; cnt++; }
                else q.push(cur);
            } else {
                if (distribute && !block && cur.first >= 100) cnt++;
                else { block = true; q.push(cur); }
            }
        }
        if (distribute) ans.push_back(cnt);
    }

    return ans;
}

int main(void) {
    for (int x : solution({93, 30, 55}, {1, 30, 5})) cout << x << " ";
    cout << endl;
    for (int x : solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1})) cout << x << " ";
    cout << endl;
}
