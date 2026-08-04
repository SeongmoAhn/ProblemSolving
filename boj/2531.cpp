#include <iostream>
#include <memory.h>
using namespace std;

int n, d, k, inputCoupon;
int overlapCount, cnt, couponCheck, maxCount = 0;
int table[300001];
int visited[3001];

int main()
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> d >> k >> inputCoupon;
	
	for (int i = 0; i < n; i++)
        cin >> table[i];

	for (int i = 0; i < n; i++) {
		overlapCount = 0;
		couponCheck = 1;

		for (int j = i; j < i + k; j++) {				
			if (visited[table[j % n]] == 1) 
                overlapCount++;
			else
                visited[table[j % n]] = 1;

			if (table[j % n] == inputCoupon)
                couponCheck = 0;
		}

		maxCount = max(maxCount, k - overlapCount + couponCheck);
		memset(visited, 0, sizeof(visited));
	}

	cout << maxCount;
}
