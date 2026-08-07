#include <iostream>
using namespace std;
int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    char alphabet[5][3] = {
        {'A', 'B', 'C'},
        {'A', 'G', 'H'},
        {'H', 'I', 'J'},
        {'K', 'A', 'B'},
        {'A', 'B', 'C'}
    };
    int a[26] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            a[alphabet[i][j] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        char ch = i + 'A';
        for (int j = 0; j < a[i]; j++) {
            cout << ch;
        }
    }

    return 0;
}
