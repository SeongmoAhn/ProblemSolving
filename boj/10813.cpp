#include <iostream>
#include <vector>
using namespace std;

vector<int> v(101);

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input1, input2, n, m, i;
    int temp;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        v[i] = i;
    }

    for (i = 0; i < m; i++) {
        cin >> input1 >> input2;
        temp = v[input1];
        v[input1] = v[input2];
        v[input2] = temp;
    }

    for (i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << '\n';

    return 0;
}
