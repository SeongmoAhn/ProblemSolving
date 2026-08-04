#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int n, position, priority, testCase;
    int i, j;
    int input, count, index;
    cin >> testCase; 

    for (i = 0; i < testCase; i++) {
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        cin >> n >> position;
        count = 0;

        for (j = 0; j < n; j++) {
            cin >> priority;
            q.push({j, priority});
            pq.push(priority);
        }

        while (!q.empty()) {
            index = q.front().first;
            priority = q.front().second;
            q.pop();

            if (pq.top() == priority) {
                pq.pop();
                count++;
                if (index == position) {
                    cout << count << endl;
                    break;
                }
            }
            else {
                q.push({index, priority});
            }
        }
    }
	return 0;
}
