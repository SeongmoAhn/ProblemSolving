#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long

typedef vector<vector<ll>> matrix;
int N, MOD, P;

void initInput() {
    cin >> N >> MOD >> P;
}

matrix operator * (const matrix &A, const matrix &B) {
    matrix ret(N, vector<ll>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int m = 0; m < N; m++) {
                ret[i][j] += (A[i][m] * B[m][j]) % MOD;
            }
            ret[i][j] %= MOD;
        }
    }

    return ret;
}

matrix matrixPower(matrix &A, int n) {
    if (n == 0) {
        matrix ret(N, vector<ll>(N));
        for (int i = 0; i < N; i++) ret[i][i] = 1;
        return ret;
    }

    if (n & 1) {
        matrix temp = matrixPower(A, n - 1);
        return A * temp;
    }
    else {
        matrix temp = matrixPower(A, n / 2);
        return temp * temp;
    }
}

void solve() {
    while (1) {
        initInput(); if (!N && !MOD && !P) break;

        matrix mat(N, vector<ll>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> mat[i][j];
        mat = matrixPower(mat, P);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    solve();

    return 0;
}
