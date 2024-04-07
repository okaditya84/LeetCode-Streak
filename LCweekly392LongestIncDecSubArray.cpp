class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        
        // Check for strictly increasing subarrays
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                int start = i-1;
                while (i < n && nums[i] > nums[i-1]) {
                    i++;
                }
                maxLength = max(maxLength, i - start);
            }
        }
        
        // Check for strictly decreasing subarrays
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                int start = i-1;
                while (i < n && nums[i] < nums[i-1]) {
                    i++;
                }
                maxLength = max(maxLength, i - start);
            }
        }
        
        return maxLength;
    }
};