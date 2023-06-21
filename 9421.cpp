#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define SIZE 1000001
#define INF 1e9
#define PRIME 0
#define NOT_PRIME 1

int n;
bool table[SIZE];
vector<int> prime;

void initInput() {
    cin >> n;
}

void makePrime() {
    for (int i = 2; i <= sqrt(n); i++) {
        if (table[i] == PRIME) {
            int j = 2;
            while (i * j <= n) {
                table[i * j] = NOT_PRIME;
                j++;
            }
        }
    } 

    for (int i = 2; i <= n; i++) {
        if (table[i] == PRIME) prime.push_back(i);
    }
}

bool check(int x) {
    map<int, bool> visited;
    int temp = x;
    while (1) {
        int result = 0;

        while (temp) {
            result += (temp % 10) * (temp % 10);
            temp /= 10;
        }

        if (result == 1) return true;

        if (!visited.count(result)) visited[result] = 1;
        else return false;

        temp = result;
    }
}

void solve() {
    makePrime();

    for (int i = 0; i < prime.size(); i++) {
        if (prime[i] > n) return;

        if (check(prime[i])) cout << prime[i] << endl;
    }
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
