#include <iostream>
#include <deque>
using namespace std;

deque<int> d;

void action1() {
    d.pop_front();
}

void action2(int &count) {
    d.push_back(d.front());
    d.pop_front();
    count++;
}

void action3(int &count) {
    d.push_front(d.back());
    d.pop_back();
    count++;
}
int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input;
    int target;
    int targetIndex;
    int count = 0;
    int n, m, i;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        d.push_back(i);
    }

    for (i = 0; i < m; i++) {
        cin >> target;
        // targetIndex 찾기
        for (int j = 0; j < d.size(); j++) {
            if (d[j] == target) {
                targetIndex = j;
                break;
            }
        }

        if (targetIndex < d.size() - targetIndex) {
            while (1) {
                if (d.front() == target) {
                    action1();
                    break;
                }
                action2(count);
            }
        }
        else {
            while (1) {
                if (d.front() == target) {
                    action1();
                    break;
                }
                action3(count);
            }
        }
    }
    cout << count << '\n';

	return 0;
}
