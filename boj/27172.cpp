#include <iostream>
#include <vector>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 1000001

int n;
vector<int> number;
int cards[SIZE];
int score[SIZE];

void initInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        number.push_back(input);
        cards[input]++;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = number[i] * 2; j < SIZE; j += number[i]) {
            if (cards[j]) {
                score[number[i]]++;
                score[j]--;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << score[number[i]] << ' ';
    cout << endl;
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
