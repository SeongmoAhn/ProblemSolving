#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000000
#define SIZE

typedef vector<vector<ll>> matrix;

matrix operator * (matrix A, matrix B) {
    matrix C(2, vector<ll>(2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll sum = 0;
            for (int m = 0; m < 2; m++) {
                sum += (A[i][m] % MOD) * (B[m][j] % MOD) % MOD;
            }
            C[i][j] = sum % MOD;
        }
    }
    return C;
}

matrix matrixPower(matrix A, ll size) {
    if (size == 0) {
        matrix ret(2, vector<ll>(2));
        ret[0][0] = ret[1][1] = 1; ret[0][1] = ret[1][0] = 0;
        return ret;
    }
    else if (size & 1) {
        matrix temp = matrixPower(A, (size - 1) / 2);
        return A * temp * temp;
    }
    else {
        matrix temp = matrixPower(A, size / 2);
        return temp * temp;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    matrix fibonacci(2, vector<ll>(2));
    fibonacci[0][0] = fibonacci[0][1] = fibonacci[1][0] = 1; fibonacci[1][1] = 0;
    matrix A = matrixPower(fibonacci, (a - 1) + 2);
    matrix B = matrixPower(fibonacci, b + 2);

    cout << (((B[0][1] - 1) % MOD - (A[0][1] - 1) % MOD) % MOD + MOD) % MOD << endl;

    return 0;
}
