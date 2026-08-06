#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 

vector<string> graph;
vector<string> v;
int visited[3][3];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void init_input() {
    for (int i = 0; i < 3; i++) {
        string str; cin >> str;
        graph.push_back(str);
    }
}

void solve(int y, int x, string str) {
    if (y == 2 && x == 2) {
        v.push_back(str);
        return ;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && nx >= 0 && ny < 3 && nx < 3 && !visited[ny][nx]) {
            visited[ny][nx] = 1;
            str += graph[ny][nx];
            solve(ny, nx, str);
            str.pop_back();
            visited[ny][nx] = 0;
        }
    }
}

int getout() {
    int cnt = 0;
    for (auto s : v) {
        int flag = 1;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                flag = 0;
                break;
            }
        }
        if (flag) cnt++;
    }
    return cnt;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    init_input();

    string str = "";
    str += graph[0][0];
    visited[0][0] = 1;
    solve(0, 0, str);
    cout << getout();

    return 0;
}
