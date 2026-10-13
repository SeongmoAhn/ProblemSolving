#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int sum = 0;
    for (int i = 0; i < absolutes.size(); i++) 
        sum += (signs[i] ? 1 : -1) * absolutes[i];
    return sum;
}

int main(void) {
    vector<int> absolutes = {4, 7, 12};
    vector<bool> signs = {true, false, true};

    cout << solution(absolutes, signs) << endl;
}
