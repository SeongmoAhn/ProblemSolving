#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define pii pair<int, int>

vector<int> solution(vector<string> wallpaper) {
    int row = wallpaper.size(), col = wallpaper[0].size();
    int top = row, left = col, bottom = 0, right = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (wallpaper[i][j] != '#') continue;
            top = min(top, i);
            left = min(left, j);
            bottom = max(bottom, i + 1);
            right = max(right, j + 1);
        }
    }
    return {top, left, bottom, right};
}


int main(void) {
    for (int x : solution({".#...", "..#..", "...#."})) cout << x << " ";
    cout << endl;
    for (int x : solution({"..........", ".....#....", "......##..", "...##.....", "....#....."})) cout << x << " ";
    cout << endl;
    for (int x : solution({".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."})) cout << x << " ";
    cout << endl;
    for (int x : solution({"..", "#."})) cout << x << " ";
    cout << endl;
}
