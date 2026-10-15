#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define SIZE 51
#define pii pair<int, int>


vector<int> solution(vector<string> park, vector<string> routes) {
    int row = park.size(), col = park[0].size();
    pii cur;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (park[i][j] == 'S') cur = {i, j};
        }
    }

    for (auto route : routes) {
        char course = route[0];
        int move = route[2] - '0';

        int pass = false;
        if (course == 'N') { // 위로 -
            for (int i = 0; i < move; i++) {
                cur.first--;

                if (cur.first < 0 || park[cur.first][cur.second] == 'X') {
                    cur.first += i + 1;
                    pass = true;
                    break;
                }
            }
            if (pass) continue;
        } else if (course == 'S') { // 아래로 +
            for (int i = 0; i < move; i++) {
                cur.first++;

                if (cur.first >= row || park[cur.first][cur.second] == 'X') {
                    cur.first -= i + 1;
                    pass = true;
                    break;
                }
            }
            if (pass) continue;
        } else if (course == 'W') { // 왼쪽으로 -
            for (int i = 0; i < move; i++) {
                cur.second--;

                if (cur.second < 0 || park[cur.first][cur.second] == 'X') {
                    cur.second += i + 1;
                    pass = true;
                    break;
                }
            }
        } else { // 오른쪽으로 +
            for (int i = 0; i < move; i++) {
                cur.second++;

                if (cur.second >= col || park[cur.first][cur.second] == 'X') {
                    cur.second -= i + 1;
                    pass = true;
                    break;
                }
            }
        }
    }

    return {cur.first, cur.second};
}

int main(void) {
    for (int x : solution({"SOO", "OOO", "OOO"}, {"E 2", "S 2", "W 1"})) cout << x << " ";
    cout << endl;
    for (int x : solution({"SOO", "OXX", "OOO"}, {"E 2", "S 2", "W 1"})) cout << x << " ";
    cout << endl;
    for (int x : solution({"OSO", "OOO", "OXO", "OOO"}, {"E 2", "S 3", "W 1"})) cout << x << " ";
    cout << endl;
}
