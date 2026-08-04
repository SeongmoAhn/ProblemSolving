#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define MOD 1000
#define ll long long

typedef vector<vector<long long>> matrix;
int a;
ll b;

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

matrix matrixPower(matrix A, long long n) {
    if (n == 0) {
        matrix ret(a, vector<long long>(a));
        for (int i = 0; i < a; i++)
            ret[i][i] = 1;
        return ret;
    }
    else if (n & 1) {
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
    cin >> a >> b;

    matrix input(a, vector<ll>(a));
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            cin >> input[i][j];

    input = matrixPower(input, b);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << input[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
