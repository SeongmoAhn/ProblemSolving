#include <iostream>
#include <vector>
using namespace std;

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
    first = v[n - 1];
    second = v[n - 2];

    count = int(m / (k + 1)) * k;
    count += m % (k + 1);

    result += (count) * first;
    result += (m - count) * second;

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
