#include <iostream>
#include <vector>
using namespace std;

// M의 값이 커졌을 때의 알고리즘
int main()
{
    int n, m, k;
    int i;
    cin >> n >> m >> k;
    int input;
    vector<int> v;
    int count = 0;
    int result = 0;
    int first, second;
    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    first = v[n - 1]; // 입력 값 중 가장 큰 값
    second = v[n - 2]; // 입력 값 중 두 번째로 큰 값

    // 가장 큰 값이 쓰여지는 횟수
    count = int(m / (k + 1)) * k;
    count += m % (k + 1);

    result += (count) * first;
    result += (m - count) * second; // (m - count)는 두번 째로 큰 값이 쓰여지는 횟수

    cout << result << endl;
}

// 기본적인 알고리즘
// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     int input;
//     int first, second;
//     int sum = 0;
//     vector<int> v;
//     int i, j;
//     for (i = 0; i < n; i++) {
//         cin >> input;
//         v.push_back(input);
//     }
//     sort(v.begin(), v.end());
//     first = v[n - 1];
//     second = v[n - 2];
//
//     while (true) {
//         for (i = 0; i < k; i++) {
//             if (m == 0)
//                 break;
//             sum += first;
//             m--;
//         }
//         if (m == 0)
//             break;
//         sum += second;
//         m--;
//     }
//
//     cout << sum << endl;
// }
