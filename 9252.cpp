#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define PS_INPUT cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false)
#define endl '\n'
#define INF 1e9
#define pii pair<int, int>
#define ll long long
#define SIZE 1001

string str1 = " ", str2 = " ";
int dp[SIZE][SIZE];
int len1, len2;
string lcs;

void initInput() {
    string temp1, temp2;
    cin >> temp1 >> temp2;
    str1 += temp1;
    str2 += temp2;
    len1 = str1.size();
    len2 = str2.size();
}

void solve() {
    for (int row = 1; row < len2; row++) {
        for (int col = 1; col < len1; col++) {
            if (str1[col] == str2[row]) {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            }
            else {
                dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
            }
        }
    }
    cout << dp[len2 - 1][len1 - 1] << endl;

    int col = len1 - 1;
    int row = len2 - 1;
	while (dp[row][col]) {
		if (dp[row][col] == dp[row - 1][col])
			row--;

		else if (dp[row][col] == dp[row][col - 1])
			col--;

		else {
			lcs += str1[col];
			row--, col--;
		}

	}

	if (lcs.size() > 0) {
		reverse(lcs.begin(), lcs.end());
		cout << lcs << endl;
	}
}

int main(void)
{
    PS_INPUT; 
    initInput();
    solve();

    return 0;
}
