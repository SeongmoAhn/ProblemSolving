#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// num[] ]의 자리수 올림을 처리
void normalize(vector<int>& num) {
    num.push_back(0);

    // 자리수 올림을 처리
    for (int i = 0; i < num.size(); i++) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back() == 0) num.pop_back();
}

// 두 긴 자연수의 곱을 반환
// 각 배열에는 각 수의 자리수가 1의 자리에서부터 시작해 저장되어 있다.
// 예: multiply({3, 2, 1}, {6, 5, 4}) = 123 * 456 = 56088 = {8, 8, 0, 6, 5}
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

//a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k){
	int originalASize = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);
	a.push_back(0);

	int aSize = a.size();
	for (int i = originalASize; i < aSize; i++)
		a[i] = 0;

	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i + k] += b[i];

	normalize(a);
}

// a -= b
// a>= b인 경우에만 사용 가능하다.
void subFrom(vector<int>& a, const vector<int>& b){
	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i] -= b[i];
	normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int aSize = a.size(), bSize = b.size();

    // a가 b보다 짧을 경우 둘을 바꿈
    if (aSize < bSize) return karatsuba(b, a);
    
    // 기저 사례: a나 b가 비어 있는 경우
    if (aSize == 0 || bSize == 0) return vector<int> ();

    // 기저 사례: a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경
    if (aSize <= 50) return multiply(a, b);

    int half = aSize / 2;
    // a와b를 밑에서 half자리와 나머지로 분리
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    // z2 = a1 * b1
    vector<int> z2 = karatsuba(a1, b1);

    // z0 = a0 * b0
    vector<int> z0 = karatsuba(a0, b0);

    // a0 = a0 + a1; b0 = b0 + b1
    addTo(a0, a1, 0); addTo(b0, b1, 0);

    // z1 = (a0 * b0) - z0 - z2;
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    // ret = z0 + z1 * 10^half + z2 * 10^(half*2)
    vector<int> ret(z2.size() + half * 2, 0);
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}

int main() {
    string input1, input2;
    vector<int> num1, num2, result;
    cin >> input1 >> input2;

    for (int i = input1.size() - 1; i >= 0; i--) {
        num1.push_back(input1[i] - '0');
    }
    for (int i = input2.size() - 1; i >= 0; i--) {
        num2.push_back(input2[i] - '0');
    }

    result = karatsuba(num2, num1);

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << '\n';

    return 0;
}
