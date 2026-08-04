#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int N, a; cin >> N;
    string input;
    int cnt[130] = {0};
    char arr[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    while (N--) { cin >> a; cnt[arr[a]]++; } N++;
    cin.ignore(); getline(cin, input);
    for (int i = 0; i < input.size(); i++) cnt[input[i]]--;
    for (int i = 0; i < 130; i++) if (cnt[i]) N = 1;
    cout << (N ? 'n' : 'y');
}
