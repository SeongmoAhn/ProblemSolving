#include <iostream>
#include <vector>
using namespace std;

char company[2] = {'M', 'Y'};

int payY(vector<int> v) {
    int size = v.size();
    int i;
    int cur;
    int count = 0;

    for (i = 0; i < size; i++) {
        cur = v[i];
        while (cur >= 30) {
            cur -= 30;
            count++;
        }
        count++;
    }

    return 10 * count;
}
int payM(vector<int> v) {
    int size = v.size();
    int i;
    int cur;
    int count = 0;

    for (i = 0; i < size; i++) {
        cur = v[i];
        while (cur >= 60) {
            cur -= 60;
            count++;
        }
        count++;
    }

    return 15 * count;
}
int main(void)
{
    int n, i, j;
    cin >> n;
    vector<int> v;
    int howMuchM, howMuchY;
    int input;
    for (i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    howMuchM = payM(v);
    howMuchY = payY(v);

    if (howMuchM < howMuchY) {
        cout << "M " << howMuchM << endl;
    }
    else if (howMuchM > howMuchY) {
        cout << "Y " << howMuchY << endl;
    }
    else {
        cout << "Y M " << howMuchY << endl;
    }

	return 0;
}
