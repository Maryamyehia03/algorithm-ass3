#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<int> g(a), s(b);
    for (int i = 0; i < a; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> s[i];
    }
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int sum = 0;
    int j = 0;
    for (int i = 0; i < a && j < b; ) {
        if (s[j] >= g[i]) {
            sum++;
            i++;
        }
        j++;
    }
    cout << sum << endl;
    return 0;
}
