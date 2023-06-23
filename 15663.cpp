#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define PII pair<int, int>
#define ll long long
#define SIZE 10

int n, bound;
int v[SIZE];
int visited[SIZE];
int result[SIZE];

void initInput() {
    cin >> n >> bound;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v[i] = input;
    }
    sort(v, v + n);
}

void solve(int j) {
    if (j == bound) {
        for (int i = 0; i < bound; i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }

    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && temp != v[i]) {
            result[j] = v[i];
            temp = result[j];
            visited[i] = 1;
            solve(j + 1);
            visited[i] = 0;
        }
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve(0);

    return 0;
}
