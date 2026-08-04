#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, i;
    long long input;
    cin >> n;
    int size = n - 1;
    vector<long long> distance;
    vector<long long> price;
    for (i = 0; i < size; i++) {
        cin >> input;
        distance.push_back(input);
    }
    for (i = 0; i < size; i++) {
        cin >> input;
        price.push_back(input);
    }

    long long minPrice = 2000000000;
    long long totalPrice = 0;
    for (i = 0; i < size; i++) {
        minPrice = min(minPrice, price[i]);
        totalPrice += minPrice * distance[i];
    }

    cout << totalPrice << '\n';

    return 0;
}
