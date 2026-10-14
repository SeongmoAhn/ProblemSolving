#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int getDay(string date) {
    int y, m, d;
    sscanf(date.c_str(), "%d.%d.%d", &y, &m, &d);
    return (y * 12 * 28) + (m * 28) + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> ans;
    int expire = getDay(today);
    int types[26] = {0};
    for (auto t : terms) {
        char a;
        int b;
        sscanf(t.c_str(), "%c %d", &a, &b);
        types[a - 'A'] = b;
    }

    int idx = 0;
    for (auto date : privacies) {
        idx++;
        int type = date[date.size() - 1] - 'A';
        int check = getDay(date) + types[type] * 28;

        if (check <= expire) {
            ans.push_back(idx);
        }
    }

    return ans;
}

int main(void) {
    for (int x : solution("2022.05.19", {"A 6", "B 12", "C 3"}, {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"})) cout << x << " ";
    cout << endl;
    for (int x : solution("2020.01.01", {"Z 3", "D 5"}, {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"})) cout << x << " ";
    cout << endl;
}
