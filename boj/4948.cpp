#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define endl "\n"
#define PRIME false
#define NOT_PRIME true

vector<int> testCase;
vector<int> prime;
bool table[246913] = { NOT_PRIME, NOT_PRIME, };
int maxValue = -1;

void makePrime() {
    for (int i = 2; i <= sqrt(maxValue); i++) {
        if (table[i] == PRIME) {
            int j = 2;
            while (i * j <= maxValue) {
                table[i * j] = NOT_PRIME;
                j++;
            }
        }
    } 
}

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int input;
    while (1) {
        cin >> input;
        if (!input) break;

        maxValue = max(maxValue, input);
        testCase.push_back(input);
    }
    maxValue *= 2;
    makePrime();

    for (int i = 0; i < testCase.size(); i++) {
        int cnt = 0, test = testCase[i];

        for (int j = test + 1; j <= (test * 2); j++) {
            if (table[j] == PRIME)
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
