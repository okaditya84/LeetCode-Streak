class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> sameParity(n - 1, false);
        
        // Precompute the sameParity array
        for (int i = 0; i < n - 1; ++i) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                sameParity[i] = true;
            }
        }
        
        // Construct the prefix sum array for sameParity
        vector<int> prefixSameParity(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSameParity[i] = prefixSameParity[i - 1] + (sameParity[i - 1] ? 1 : 0);
        }
        
        vector<bool> answer;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == end) {
                // A single element subarray is always special
                answer.push_back(true);
            } else {
                // Check if there are any same-parity pairs within the range [start, end-1]
                if (prefixSameParity[end] - prefixSameParity[start] > 0) {
                    answer.push_back(false);
                } else {
                    answer.push_back(true);
                }
            }
        }
        
        return answer;
    }
};
