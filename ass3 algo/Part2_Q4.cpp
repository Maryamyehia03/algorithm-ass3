#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int parent[N];

// Union-Find:
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

// Union-Find: Union by parent update
bool uni(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}
int main() {

    long long n, m, G, S;
    cin >> n >> m >> G >> S;

    vector<array<int, 4>> edges(m);
    for (auto& [gold, silver, u, v] : edges) {
        cin >> u >> v >> gold >> silver;
        //Use 0 based
        u--, v--;
    }
// Sort by gold cost
    sort(edges.begin(), edges.end());

    long long ans = LLONG_MAX;
    set<array<int, 3>> incEdg;
    for (auto& [g, s, u, v] : edges) {
        if (u == v) continue; // Ignore self-loops

        array <int, 3> remove{-1, -1, -1};
        incEdg.insert({s, u, v});
        // Reset Union-Find structure
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int mxs = 0;
        set<array<int, 3>> mst;

        incEdg.insert({s, u, v});
        iota(parent, parent+N, 0);
        for (auto &[curS, curU, curV] : incEdg) {
            if (uni(curU, curV)) {
                mxs = curS;
            }
            else {
                remove = {curS, curU, curV};
            }
        }

        if (remove[0] != -1) {
            incEdg.erase(remove);
        }

        if (incEdg.size() == n-1) {
            ans = min(ans, g*G+mxs*S);
        }
    }
    if (ans==LLONG_MAX)
        ans=-1;
    cout << ans<< '\n';
    return 0;
}
