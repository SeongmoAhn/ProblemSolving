#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    int cnt = 0;
    string cur = board[h][w];
    for (int i = 0; i < 4; i++) {
        int ny = h + dy[i];
        int nx = w + dx[i];
        if (ny < 0 || nx < 0 || ny == board.size() || nx == board[0].size()) continue;
        if (board[ny][nx] == cur) cnt++;
    }
    return cnt;
}

int main(void) {
    cout << solution({{"blue", "red", "orange", "red"}, {"red", "red", "blue", "orange"}, {"blue", "orange", "red", "red"}, {"orange", "orange", "red", "blue"}}, 1, 1) << endl;
    cout << solution({{"yellow", "green", "blue"}, {"blue", "green", "yellow"}, {"yellow", "blue", "blue"}}, 0, 1) << endl;
}
