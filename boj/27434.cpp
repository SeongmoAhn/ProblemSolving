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
    void pushBack(int ch) {
        numArray.push_back(ch);
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
            // cout << "deque is empty" << endl;
            return;
        }
        numArray.pop_back();
        length--;
    }
    void popFront() {
        if (numArray.empty()) {
            // cout << "deque is empty" << endl;
            return;
        }
        numArray.pop_front();
        length--;
    }

    int getLength() {
        return length;
    }
    string getString() {
        string returnStr;
        int size = getLength();
        for (int i = 0; i < size; i++) {
            returnStr.push_back(numArray.front());
            numArray.pop_front();
        }
        return returnStr;
    }

    void printAll() {
        int size = length;
        for (int i = 0; i < size; i++) {
            cout << getFrontToInt();
            popFront();
        }
        cout << endl;
    }

    void clear() {
        numArray.clear();
        length = 0;
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

    static BigInt mul(BigInt num1, BigInt num2) {
        BigInt result = BigInt("");
        BigInt small = BigInt(""), big = BigInt("");
        BigInt copyFromBig = BigInt("");
        BigInt returnResult = BigInt("");
        int i, j;
        int carry = 0;
        int size;
        int temp;
        int big_pop, small_pop;
        int big_size, small_size;
        if (num1.getLength() < num2.getLength()) {
            small = num1;
            big = num2;
        }
        else {
            small = num2;
            big = num1;
        }

        size = big.getLength();
        
        small_size = small.getLength();
        big_size = big.getLength();
        
        for (i = 0; i < small_size; i++) {
            copyFromBig = big;
            carry = 0;
            small_pop = small.getBackToInt(); small.popBack();
            result.clear();

            for (j = 0; j < big_size; j++) {
                big_pop = copyFromBig.getBackToInt(); copyFromBig.popBack();
                temp = big_pop;
                temp *= small_pop;
                temp += carry;
                carry = temp / 10;
                result.pushFront(temp % 10 + '0');
            }
            if (carry)
                result.pushFront(carry + '0');

            for (int t = 0; t < i; t++) {
                result.pushBack('0');
            }

            returnResult = add(returnResult, result);
        }

        return returnResult;
    }

    static BigInt factorial(int n) {
        BigInt temp = BigInt("1");

        if (n < 2) {
            return BigInt("1");
        }
        else {
            for (int i = 2; i <= n; i++) {
                temp = BigInt::mul(temp, BigInt(to_string(i)));
            }
        }
        return temp;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << BigInt::factorial(n).getString() << endl;

    return 0;
}
