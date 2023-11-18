#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N; cin >> N;

    while (N) {
        vector<string> v;
        double flag = -1.0;
        for (int i = 0; i < N; i++) {
            string str; double num; cin >> str >> num;
            if (num < flag) continue;
            else if (num == flag) v.push_back(str);
            else {
                v.clear();
                v.push_back(str);
                flag = num;
            }
        }

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << endl;

        cin >> N;
    }
}
