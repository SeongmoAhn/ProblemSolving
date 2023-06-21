#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 5000001
#define INF 1e9

int n;
int table[SIZE];
vector<int> input;

void initInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        input.push_back(temp);
    }
    for (int i = 2; i < SIZE; i++) table[i] = i;
}

void makePrime() {
    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (table[i] == i) {
            for (int j = i * i; j <= SIZE; j += i) {
                if (table[j] == j) {
                    table[j] = i;
                }
            }
        }
    } 
}

void primeFactor(int x) {
    int temp = x;

    while (temp > 1) {
        cout << table[temp] << ' ';
        temp /= table[temp];
    }
    cout << endl;
}

void solve() {
    makePrime();

    for (int i = 0; i < input.size(); i++) {
        primeFactor(input[i]);
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
