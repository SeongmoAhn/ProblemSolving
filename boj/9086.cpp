#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        cout << input[0] << input[input.size() - 1] << endl;
    }
}
