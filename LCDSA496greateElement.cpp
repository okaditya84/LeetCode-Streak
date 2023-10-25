class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int n =nums2.size();
        for(int i=0;i<nums1.size();i++){
            int j=0;
            for(;j<n;j++){
                if(nums1[i]==nums2[j]){
                    break;
                }
            }
            int k=j+1;
            for(;k<n;k++){
                if(nums2[k]>nums2[j]){
                    result.push_back(nums2[k]);
                    break;
                }
            }
            if(k==n){
                result.push_back(-1);
            }
        }
        return result;
    }
};