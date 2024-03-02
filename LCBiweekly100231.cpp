#include <vector>
#include <algorithm> // For sorting
#include <queue> // For priority queue

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int numOperations = 0;

        // 1. Sort the array for efficient finding of smallest elements
        std::sort(nums.begin(), nums.end()); 

        // 2. Priority queue to keep track of smallest elements
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq; 

        // 3. Iterate through the array
        for (int num : nums) {
            if (num < k) {
                pq.push(num); // Push elements less than 'k' into the priority queue
            } else {
                // Elements greater than or equal to 'k' are already good
                continue;
            }

            // Check if we can remove the smallest element
            if (!pq.empty()) {
                pq.pop(); // Remove the smallest element
                numOperations++;
            }
        }

        // If the priority queue is not empty, it means we cannot make 
        // all elements greater than or equal to 'k'
        return pq.empty() ? numOperations : -1; 
    }
};
