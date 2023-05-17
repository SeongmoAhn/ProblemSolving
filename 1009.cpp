#include <iostream>
using namespace std;

int arr[10][4] = {{10, 10, 10, 10},
	{1, 1, 1, 1},
	{2, 4, 8, 6},
	{3, 9, 7, 1},
	{4, 6, 4, 6},
	{5, 5, 5, 5},
	{6, 6, 6, 6},
	{7, 9, 3, 1},
	{8, 4, 2, 6},
	{9, 1, 9, 1}};

int main(void)
{
	int testCase;
	int a, b;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> a >> b;
		b = b % 4;
		if (a != 0 && b == 0)
			b += 4;
		b--;
		cout << arr[a % 10][b] << endl;
	}

	return 0;
}
