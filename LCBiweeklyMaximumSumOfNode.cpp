class Solution {
public:
    long long maximumValueSum(std::vector<int>& values, int target, std::vector<std::vector<int>>& connections) {
        int numNodes = values.size();
        std::vector<int> adjacencyList[numNodes];

        for (int i = 0; i < numNodes - 1; ++i) {
            adjacencyList[connections[i][0]].push_back(connections[i][1]);
            adjacencyList[connections[i][1]].push_back(connections[i][0]);
        }

        std::vector<int> increaseNodes;
        for (int i = 0; i < numNodes; ++i) {
            long long newVal = static_cast<long long>(values[i]) ^ target;
            if (newVal > values[i]) {
                increaseNodes.push_back(i);
            }
        }

        int increaseSize = increaseNodes.size();
        if (increaseSize % 2 == 0) {
            long long result = 0;
            for (int i = 0; i < numNodes; ++i) {
                result += values[i];
            }

            for (int i = 0; i < increaseSize; ++i) {
                result -= values[increaseNodes[i]];
                long long addVal = static_cast<long long>(values[increaseNodes[i]]) ^ target;
                result += addVal;
            }

            return result;
        } else {
            long long result = 0;
            for (int i = 0; i < numNodes; ++i) {
                result += static_cast<long long>(values[i]);
            }

            long long maxSum = result;

            for (int i = 0; i < increaseSize; ++i) {
                result -= values[increaseNodes[i]];
                long long addVal = static_cast<long long>(values[increaseNodes[i]]) ^ target;
                result += addVal;
            }

            for (int i = 0; i < increaseSize; ++i) {
                long long addVal = static_cast<long long>(values[increaseNodes[i]]) ^ target;
                long long currentSum = result - addVal + values[increaseNodes[i]];
                maxSum = std::max(maxSum, currentSum);
            }

            std::vector<int> visited(numNodes, 0);
            long long totalSum = 0;

            for (int i = 0; i < increaseSize; ++i) {
                visited[increaseNodes[i]] = 1;
            }

            for (int i = 0; i < numNodes; ++i) {
                if (visited[i] == 0) {
                    long long addVal = static_cast<long long>(values[i]) ^ target;
                    long long currentSum = result - values[i] + addVal;
                    maxSum = std::max(maxSum, currentSum);
                }
            }

            return maxSum;
        }
    }
};
