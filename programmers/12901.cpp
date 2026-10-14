#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string solution(int a, int b) {
    int day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string yoil[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int ans = -1;

    for (int i = 0; i < a - 1; i++) ans += day[i];
    ans += b;

    return yoil[ans % 7];
}

int main(void) {
    cout << solution(5, 24) << endl;
}
