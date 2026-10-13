#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(), mats.end(), greater<>());
    int row = park.size();
    int col = park[0].size();

    for (int mat : mats) {
        for (int i = 0; i < row - mat + 1; i++) {
            for (int j = 0; j < col - mat + 1; j++) {
                bool flag = true; 

                for (int y = i; y < i + mat; y++) {
                    for (int x = j; x < j + mat; x++) {
                        if (park[y][x] != "-1") {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }

                if (flag) return mat;
            }
        }

    }

    return -1;
}

int main(void) {
    cout << solution({5, 3, 2}, {{"A", "A", "-1", "B", "B", "B", "B", "-1"}, {"A", "A", "-1", "B", "B", "B", "B", "-1"}, {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"}, {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}, {"D", "D", "-1", "-1", "-1", "-1", "-1", "F"}, {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}}) << endl;
}
