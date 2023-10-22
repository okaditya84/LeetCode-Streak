class Solution { 
public: 
    int minimumSum(std::vector<int>& nums) { 
        int ans = std::numeric_limits<int>::max(); 
        bool isFlagged = false; 
        for (int i = 0; i < nums.size(); ++i) { 
            for (int j = i + 1; j < nums.size(); ++j) { 
                for (int k = j + 1; k < nums.size(); ++k) { 
                    if (nums[i] < nums[j] && nums[k] < nums[j]) { 
                        isFlagged = true; 
                        ans = std::min(ans, nums[i] + nums[j] + nums[k]); 
                    } 
                } 
            } 
        } 
        return isFlagged ? ans : -1; 
    } 
};