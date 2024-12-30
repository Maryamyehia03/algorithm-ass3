#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Depth-First Search (DFS)
bool dfs(int source, int destination, unordered_map<int, vector<int>>& graph, set<int>& visited) {
    if (source == destination) {
        return true;
    }
    visited.insert(source);
    for (int neighbor : graph[source]) {
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(neighbor, destination, graph, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool validPath(vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    set<int> visited;
    return dfs(source, destination, graph, visited);
}


int main() {
//    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    int source1 = 0, destination1 = 2;
    cout << (validPath(edges1, source1, destination1) ? "True" : "False") << endl;

//    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source2 = 0, destination2 = 5;
    cout << (validPath(edges2, source2, destination2) ? "True" : "False") << endl;

    return 0;
}
