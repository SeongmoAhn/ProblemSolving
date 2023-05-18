#include <iostream>
#include <deque>
#include <string>
using namespace std;

class BigInt {
private:
    deque<char> numArray;
    int length;
    
public:
    BigInt (string str) {
        for (int i = 0; i < str.length(); i++) {
            numArray.push_back(str[i]);
        }
        this->length = str.length();
    }

    ~BigInt () {}

    void pushFront(int ch) {
        numArray.push_front(ch);
        length++;
    }

    int getBackToInt() {
        if (numArray.empty())
            return 0;
        return numArray.back() - '0';
    }
    int getFrontToInt() {
        if (numArray.empty())
            return 0;
        return numArray.front() - '0';
    }

    void popBack() {
        if (numArray.empty()) {
            return;
        }
        numArray.pop_back();
        length--;
    }
    void popFront() {
        if (numArray.empty()) {
            return;
        }
        numArray.pop_front();
        length--;
    }

    int getLength() {
        return length;
    }

    static BigInt add(BigInt num1, BigInt num2) {
        BigInt result = BigInt("");
        int carry = 0;
        int temp;
        int bigger = max(num1.getLength(), num2.getLength());

        for (int i = 0; i < bigger; i++) {
            temp = num1.getBackToInt() + num2.getBackToInt() + carry;
            carry = temp / 10;
            temp %= 10;
            num1.popBack();
            num2.popBack();
            result.pushFront(temp + '0');
        }
        if (carry)
            result.pushFront(carry + '0');

        return result;
    }
};

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    BigInt num1 = BigInt(input1);
    BigInt num2 = BigInt(input2);
    int size;

    BigInt test = BigInt::add(num1, num2);
    size = test.getLength();
    for (int i = 0; i < size; i++) {
        cout << test.getFrontToInt();
        test.popFront();
    }
    cout << endl;
    return 0;
}
