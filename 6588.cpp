#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define endl '\n'
#define SIZE 1000001

bool prime[SIZE] = {1, 1, 1};
int N;
int big, small;

void makePrime() {
    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (prime[i] == 0) {
            int j = 2;
            while (i * j <= SIZE) {
                prime[i * j] = 1;
                j++;
            }
        }
    }
}

void printAnswer() { cout << N << " = " << small << " + " << big << endl; }

void solve() {
    makePrime();

    cin >> N;
    while (N) {
        small = 3;
        big = N - 3;
        while (small <= big) {
            if (!prime[small] && !prime[big])
                break;
            small += 2;
            big -= 2;
        }
        if (small > big) cout << "Goldbach's conjecture is wrong." << endl;
        else printAnswer();
        cin >> N;
    }
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    solve();

    return 0;
}
