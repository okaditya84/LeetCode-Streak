#include <iostream>
#include <vector>
using namespace std;

int findMinimumCost(vector<int> arr) {
    int n = arr.size();
    int cost = 0;
    for(int i = 1; i < n; i++) {
        cost += abs(arr[i] - arr[i - 1]);
    }
    return cost;
}

int main() {
    // Test case
    vector<int> arr = {1,4,2,1}; // Sample input array
    cout << "Minimum cost: " << findMinimumCost(arr) << endl;
    return 0;
}
