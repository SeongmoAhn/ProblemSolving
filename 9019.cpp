#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define endl '\n'
#define SIZE 10000

int A, B, nx;
queue<pair<int, string>> q;
bool visited[SIZE];

char D(void) {
    int temp = nx * 2;
    if (temp > 9999) temp %= 10000;
    nx = temp;
    return 'D';
}

char S(void) {
    int temp = nx - 1;
    if (temp < 0) temp = 9999;
    nx = temp;
    return 'S';
}

char L(void) {
    int temp = (nx % 1000) * 10 + (nx / 1000);
    nx = temp;
    return 'L';
}

char R(void) {
    int temp = (nx % 10) * 1000 + (nx / 10);
    nx = temp;
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
            nx = num;
            str += func[i]();
            if (visited[nx]) {
                str.pop_back();
                continue;
            }
            visited[nx] = 1;
            q.push({nx, str});
            str.pop_back();
        }
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
