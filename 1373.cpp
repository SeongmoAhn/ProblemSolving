#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
    string binary;
    deque<char> arr;
    deque<int> result;
    int num = 0;
    cin >> binary;
    int count = 0;
    for (int i = 0; i < binary.length(); i++) {
        arr.push_back(binary[i]);
    }

    while (arr.size() != 0) {
        if (count == 0){
            num += arr.back() - '0';
            arr.pop_back();
            count++;
        }

        else if (count == 1) {
            num += (arr.back() - '0') * 2;
            arr.pop_back();
            count++;
        }

        else if (count == 2) {
            num += (arr.back() - '0') * 4;
            arr.pop_back();
            count++;
        }

        else {
            // cout << num;
            result.push_front(num);
            count = 0;
            num = 0;
        }
    }
    // cout << num;
    result.push_front(num);

    while (result.size() != 0) {
        cout << result.front();
        result.pop_front();
    }
    cout << endl;
}
