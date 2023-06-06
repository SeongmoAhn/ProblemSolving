#include <iostream>
using namespace std;
int a, b;
int main() {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            return 0;
        }
        if (a > b && a % b == 0) {
            cout << "multiple" << '\n';
        }
        else if (a < b && b % a == 0) {
            cout << "factor" << '\n';
        }
        else
            cout << "neither" << '\n';
    }
    
}
