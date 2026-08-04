#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define endl '\n'
#define SIZE 1001

int N;
int arr[SIZE][5];
set<int> s[SIZE];
priority_queue<pair<int, int>> pq;

void init_input()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) 
            cin >> arr[i][j];
    }
}

int solve()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < N; k++) {
                if (i == k || s[i].find(k) != s[i].end()) continue;

                if (arr[i][j] == arr[k][j])
                    s[i].insert(k);
            }
        }
        pq.push(make_pair(s[i].size(), -i));
    }

    return (-pq.top().second + 1);
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    init_input();
    cout << solve() << endl;

    return 0;
}
