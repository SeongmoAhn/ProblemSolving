#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long

const ll MOD = 1000000007LL;
typedef vector<vector<long long>> matrix;

matrix operator * (const matrix &A, const matrix &B) {
    int size = A.size();
    matrix C(size, vector<long long>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            long long sum = 0;
            for (int m = 0; m < size; m++) {
                C[i][j] += (A[i][m] % MOD) * (B[m][j] % MOD) % MOD;
            }
            C[i][j] %= MOD;
        }
    }
    return C;
}

matrix matrixPower(const matrix &A, ll n) {
    if (n == 0) return {{1, 0}, {0, 1}};

    if (n & 1) {
        matrix temp = matrixPower(A, n - 1);
        return A * temp;
    }
    else {
        matrix temp = matrixPower(A, n / 2);
        return temp * temp;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll N; cin >> N;
    if (N <= 1) { cout << N << endl; return 0; }

    matrix fibonacci = {{1, 1}, {1, 0}};

    cout << matrixPower(fibonacci, N)[0][1] % MOD << endl;

    return 0;
}
