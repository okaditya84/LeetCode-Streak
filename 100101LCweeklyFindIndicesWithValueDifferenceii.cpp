class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        int i = 0, j = i + indexDifference;
        while (i < n && j < n) {
            if (abs(nums[i] - nums[j]) >= valueDifference) {
                return {i, j};
            }
            j++;
            if (j - i < indexDifference || j >= n) {
                i++;
                j = i + indexDifference;
            }
        }
        return {-1, -1};
    }
};
