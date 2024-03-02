#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        // Use a priority queue (min-heap) for efficient operations
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq; 

        // Push all elements into the heap
        for (int num : nums) {
            pq.push(num);
        }

        int cnt = 0;
        while (pq.top() < k) {
            // Extract the two smallest elements
            long long first = pq.top(); 
            pq.pop();
            long long second = pq.top();
            pq.pop();

            cnt++;

            // Calculate the combined value with overflow protection
            long long val = std::min(first, second) * 2 + std::max(first, second);
            pq.push(val);
        }

        return cnt;
    }
};


