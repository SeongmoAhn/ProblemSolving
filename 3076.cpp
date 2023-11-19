#include <iostream>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int r, c, a, b; cin >> r >> c >> a >> b;
    for (int i = 0; i < r; i++) {
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < c; k++) {
				for (int l = 0; l < b; l++) {
					if ((i + k) % 2 == 0) cout << "X";
					else cout << ".";
				}
			}
			cout << endl;
		}
	}
}
