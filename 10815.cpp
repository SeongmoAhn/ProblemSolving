#include <iostream>
using namespace std;

bool check[20000001];
int n, m;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        check[input + 10000000] = 1;
    }
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        cout << check[input + 10000000] << ' ';
    }
    cout << '\n';

    return 0;
}
