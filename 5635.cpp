#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

typedef struct {
    string name;
    int year;
    int month;
    int day;
} Person;

int N;
vector<Person> v;

void initInput() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string n;
        int y, m, d;
        cin >> n >> d >> m >> y;
        v.push_back({n, y, m, d});
    }
}

bool compare(Person a, Person b) {
    if (a.year == b.year) {
        if (a.month == b.month)
            return a.day < b.day;
        return a.month < b.month;
    }
    return a.year < b.year;
}

void solve() {
    sort(v.begin(), v.end(), compare);
    cout << v[v.size() - 1].name << endl << v[0].name << endl;
}

int main(void) {
    cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    initInput();
    solve();

    return 0;
}
