#include <iostream>
#include <cstring>
using namespace std;

int testCase, student1, student2;
int n, m;
bool areFriends[10][10];
bool taken[10];

int countPairings() {
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            cur = i;
            break;
        }
    }
    if (cur == -1) return 1;

    int ret = 0;
    for (int i = cur + 1; i < n; i++) {
        if (!taken[i] && areFriends[cur][i]) {
            taken[cur] = taken[i] = true;
            ret += countPairings();
            taken[cur] = taken[i] = false;
        }
    }
    return ret;
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> testCase;

    for (int t = 0; t < testCase; t++) {
        cin >> n >> m;

        memset(taken, false, sizeof(taken));
        memset(areFriends, false, sizeof(areFriends));

        for (int i = 0; i < m; i++) {
            cin >> student1 >> student2;
            areFriends[student1][student2] = areFriends[student2][student1] = 1;
        }
        cout << countPairings() << '\n';
    }

    return 0;
}
