class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        vector<int> result;

        // First two elements are added according to the rules
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Loop through the remaining elements, applying the distribution logic
        for (int i = 2; i < n; ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Combine the arrays for the final result
        result.reserve(arr1.size() + arr2.size()); // Pre-allocate for efficiency
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());

        return result;
    }
};
