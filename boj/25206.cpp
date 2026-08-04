#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, double> m = {{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0}};

int main(void)
{
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    double sum = 0.0, input;
    string str;
    int count = 0, i;
    int total = 0;

    for (i = 0; i < 20; i++) {
        cin >> str;
        cin >> input >> str;
        if (str != "P") {
            sum += input * m[str];
            total += input;
        }
    }

    cout << sum / total << '\n';

    return 0;
}
