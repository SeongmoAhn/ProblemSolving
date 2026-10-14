#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define SIZE 1000001
#define PRIME false
#define NOT_PRIME true

int solution(int n) {
    int dp[SIZE] = {0};
    int isPrime[SIZE] = {0};
    for (int i = 2; i * i < SIZE; i++) {
        if (isPrime[i] == PRIME) {
            int j = 2;
            while (i * j < SIZE) {
                isPrime[i * j++] = NOT_PRIME;
            }
        }
    }
    for (int i = 2; i < SIZE; i++) {
        dp[i] = isPrime[i] == PRIME ? dp[i - 1] + 1 : dp[i - 1];
    }
    return dp[n];
}

int main(void) {
    cout << solution(10) << endl;
    cout << solution(5) << endl;
}
