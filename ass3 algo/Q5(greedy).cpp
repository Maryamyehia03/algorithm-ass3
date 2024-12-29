#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NODES = 100000;
const int MAX_EDGES = 200000;

int totalNodes, totalEdges;
int parentArray[MAX_NODES + 5];
long long bitStorage[MAX_EDGES + 70];
pair<int, pair<int, int>> edgeList[MAX_EDGES + 5];
vector<pair<int, int>> adjacencyMap[MAX_NODES + 5];

int findSet(int node) {
    if (parentArray[node] == node) return node;
    return parentArray[node] = findSet(parentArray[node]);
}

int calculateSubtree(int currentNode, int parentNode) {
    int currentSubtreeSize = 1;
    int index = 0;
    while (index < adjacencyMap[currentNode].size()) {
        auto neighbor = adjacencyMap[currentNode][index];
        int nextNode = neighbor.first;
        int edgeWeight = neighbor.second;

        if (nextNode != parentNode) {
            int childSubtreeSize = calculateSubtree(nextNode, currentNode);
            bitStorage[edgeWeight] += 1LL * childSubtreeSize * (totalNodes - childSubtreeSize);
            currentSubtreeSize += childSubtreeSize;
        }
        index++;
    }
    return currentSubtreeSize;
}

void processSolution() {
    sort(edgeList, edgeList + totalEdges);

    int index = 1;
    while (index <= totalNodes) {
        parentArray[index] = index;
        index++;
    }

    int maximumEdgeWeight = 0;

    index = 0;
    while (index < totalEdges) {
        int nodeU = edgeList[index].second.first;
        int nodeV = edgeList[index].second.second;
        int weight = edgeList[index].first;

        if (findSet(nodeU) != findSet(nodeV)) {
            parentArray[findSet(nodeU)] = findSet(nodeV);
            adjacencyMap[nodeU].push_back({nodeV, weight});
            adjacencyMap[nodeV].push_back({nodeU, weight});
            maximumEdgeWeight = weight;
        }
        index++;
    }

    calculateSubtree(1, -1);

    for (int i = 0; i < maximumEdgeWeight; i++) {
        bitStorage[i + 1] += bitStorage[i] / 2;
        bitStorage[i] %= 2;
    }

    for (; bitStorage[maximumEdgeWeight] > 1; maximumEdgeWeight++) {
        bitStorage[maximumEdgeWeight + 1] = bitStorage[maximumEdgeWeight] / 2;
        bitStorage[maximumEdgeWeight] %= 2;
    }

    for (int i = maximumEdgeWeight; i >= 0; i--) {
        cout << bitStorage[i];
    }
    cout << '\n';
}

int main() {
    cin >> totalNodes >> totalEdges;
    int edgeIndex = 0;
    while (edgeIndex < totalEdges) {
        int fromNode, toNode, edgeWeight;
        cin >> fromNode >> toNode >> edgeWeight;
        edgeList[edgeIndex] = {edgeWeight, {fromNode, toNode}};
        edgeIndex++;
    }

    processSolution();
    return 0;
}
