#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define SIZE 3000
#define PRIME false
#define NOT_PRIME true

bool isPrime[SIZE];
int ans;

void makePrime() {
    for (int i = 2; i * i < SIZE; i++) {
        if (isPrime[i] == PRIME) {
            int j = 2;
            while (i * j < SIZE) {
                isPrime[i * j++] = NOT_PRIME;
            }
        }
    }
}

void dfs(vector<int> &nums, int idx, int sum, int cnt) {
    if (cnt == 3) {
        if (isPrime[sum] == PRIME) ans++;
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        dfs(nums, i + 1, sum + nums[i], cnt + 1);
    }
}

int solution(vector<int> nums) {
    makePrime();
    dfs(nums, 0, 0, 0);
    return ans;
}

int main(void) {
    cout << solution({1, 2, 3, 4}) << endl;
    cout << solution({1, 2, 7, 6, 4}) << endl;
}
