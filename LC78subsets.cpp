class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //return all possible subsets
        int n=nums.size();
        vector<vector<int>> res;
        for(int i =0;i<n;i++){
            int size = res.size();
            for(int j=0;j<size;j++){
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
            res.push_back({nums[i]});
        }
        res.push_back({});
        return res;
    }
};