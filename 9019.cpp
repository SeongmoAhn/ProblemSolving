#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 10000

int A, B, nextNum;
queue<pair<int, string>> q;
bool visited[SIZE];

char D(void) {
    int nx = nextNum * 2;
    if (nx > 9999) nx %= 10000;
    nextNum = nx;
    return 'D';
}

char S(void) {
    int nx = nextNum - 1;
    if (nx < 0) nx = 9999;
    nextNum = nx;
    return 'S';
}

char L(void) {
    int nx = (nextNum % 1000) * 10 + (nextNum / 1000);
    nextNum = nx;
    return 'L';
}

char R(void) {
    int nx = (nextNum % 10) * 1000 + (nextNum / 10);
    nextNum = nx;
    return 'R';
}

void solve() {
    fill(visited, visited + SIZE, 0);
    cin >> A >> B;
    char (*func[4])(void) = {D, S, L, R};
    queue<pair<int, string>> q;
    q.push({A, ""});
    visited[A] = 1;

    while (!q.empty()) {
        int num = q.front().first;
        string str = q.front().second;
        q.pop();

        if (num == B) {
            cout << str << endl;
            return ;
        }

        for (int i = 0; i < 4; i++) {
            nextNum = num;
            str += func[i]();
            if (visited[nextNum]) {
                str.pop_back();
                continue;
            }
            visited[nextNum] = 1;
            q.push({nextNum, str});
            str.pop_back();
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
