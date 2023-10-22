class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
            vector<int>ans;
            int n=nums.size();
            int mx=nums[0],index1=0;
            int mn=nums[0],index2=0;
            for(int i=indexDifference;i<n;i++){
                if(nums[i-indexDifference]>mx){
                    mx=nums[i-indexDifference];
                    index1=i-indexDifference;
                }
                if(nums[i-indexDifference]<mn){
                    mn=nums[i-indexDifference];
                    index2=i-indexDifference;
                }
                if(abs(nums[i]-mx)>=valueDifference){
                    return {index1,i};
                }
                if(abs(nums[i]-mn)>=valueDifference){
                    return {index2,i};
                }
            }
            return {-1,-1};
    }
};