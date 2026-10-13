#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    priority_queue<int> pq;
    vector<int> ans;

    for (int i = 0; i < score.size() && i < k; i++) {
        pq.push(-score[i]);
        ans.push_back(-pq.top());
    }
    for (int i = k; i < score.size(); i++) {
        int top = -pq.top();
        int cur = score[i];
        if (cur > top) {
            pq.pop();
            pq.push(-cur);
        }
        ans.push_back(-pq.top());
    }
    return ans;
}

int main(void) {
    for (int x : solution(3, {10, 100, 20, 150, 1, 100, 200})) cout << x << " ";
    cout << endl;
    for (int x : solution(4, {0, 300, 40, 300, 20, 70, 150, 50, 500, 1000})) cout << x << " ";
    cout << endl;
}
