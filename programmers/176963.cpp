#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> ans;
    map<string, int> m;
    for (int i = 0; i < name.size(); i++) m[name[i]] = yearning[i];

    for (auto v : photo) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (m.count(v[i])) sum += m[v[i]];
        }
        ans.push_back(sum);
    }

    return ans;
}

int main(void) {
for (int x : solution({"may", "kein", "kain", "radi"}, {5, 10, 1, 3}, {{"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}})) cout << x << " ";
cout << endl;
for (int x : solution({"kali", "mari", "don"}, {11, 1, 55}, {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}})) cout << x << " ";
cout << endl;
for (int x : solution({"may", "kein", "kain", "radi"}, {5, 10, 1, 3}, {{"may"}, {"kein", "deny", "may"}, {"kon", "coni"}})) cout << x << " ";
cout << endl;
}
