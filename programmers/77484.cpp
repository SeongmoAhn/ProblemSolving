#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    map<int, int> m;
    for (auto w : win_nums) m[w] = 1;

    int mi = 0;
    int cnt = 0;
    for (auto l : lottos) { 
        if (m.count(l)) {
            mi++;
            m[l] = 0;
        }

        if (!l) cnt++;
    }

    int M = min(cnt, (int)win_nums.size() - mi);

    int grade[] = {6, 6, 5, 4, 3, 2, 1};
    return {grade[M + mi], grade[mi]};
}

int main(void) {
    for (int x : solution({44, 1, 0, 0, 31, 25}, {31, 10, 45, 1, 6, 19})) cout << x << " ";
    cout << endl;
    for (int x : solution({0, 0, 0, 0, 0, 0}, {38, 19, 20, 40, 15, 25})) cout << x << " ";
    cout << endl;
    for (int x : solution({45, 4, 35, 20, 3, 9}, {20, 9, 3, 45, 4, 35})) cout << x << " ";
    cout << endl;
}
