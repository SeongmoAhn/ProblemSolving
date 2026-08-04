#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v = {2};


int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++ ){
        v.push_back(v.back() + (int)pow(2, i));
    }

    cout << v.back() * v.back() << '\n';

    return 0;
}
