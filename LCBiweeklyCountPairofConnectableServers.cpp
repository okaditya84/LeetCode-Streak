class Solution {
public:
    void depthFirstSearch(int node, int parent, int signalSpeed, int weight, int &result, vector<vector<pair<int, int>>>& adjacencyList) {
        if (weight % signalSpeed == 0) {
            result++;
        }
        for (pair<int, int> neighbor : adjacencyList[node]) {
            if (neighbor.first == parent) {
                continue;
            }
            depthFirstSearch(neighbor.first, node, signalSpeed, neighbor.second + weight, result, adjacencyList);
        }
    }

    int calculatePairs(int node, int signalSpeed, vector<vector<pair<int, int>>>& adjacencyList) {
        vector<int> subTreeResults;
        int totalSum = 0;
        for (pair<int, int> neighbor : adjacencyList[node]) {
            int subResult = 0;
            depthFirstSearch(neighbor.first, node, signalSpeed, neighbor.second, subResult, adjacencyList);
            subTreeResults.push_back(subResult);
            totalSum += subResult;
        }
        int finalResult = 0;
        for (int subResult : subTreeResults) {
            totalSum -= subResult;
            finalResult += subResult * totalSum;
        }
        return finalResult;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int numberOfNodes = edges.size() + 1;
        vector<vector<pair<int, int>>> adjacencyList(numberOfNodes + 1);
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back({edge[1], edge[2]});
            adjacencyList[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> results(numberOfNodes, 0);
        for (int i = 0; i < numberOfNodes; i++) {
            results[i] += calculatePairs(i, signalSpeed, adjacencyList);
            cout << results[i] << endl;
        }
        return results;
    }
};
