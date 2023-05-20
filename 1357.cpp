#include <iostream>
#include <deque>
using namespace std;

string rev(string str) {
    deque<char> d;
    char temp;
    int i;
    int size = str.length();
    string returnStr;

    for (i = 0; i < size; i++) {
        temp = str.back();
        str.pop_back();
        if (temp == '0' && d.size() == 0) {
            continue;
        }
        else {
            d.push_back(temp);
        }
    }
    size = d.size();
    for (i = 0; i < size; i++) {
        returnStr.push_back(d.front());
        d.pop_front();
    }
    return returnStr;
}

int main(void)
{
    string input1, input2;
    deque<int> num1, num2;
    cin >> input1 >> input2;

    input1 = rev(input1);
    input2 = rev(input2);

    cout << rev(to_string(stoi(input1) + stoi(input2))) << endl;

	return 0;
}
