#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int actual_sum=(nums.size())*(nums.size()+1)/2;
        return actual_sum-sum;
    }
};

//drive code for this
int main(){
    vector<int> nums={3,0,1};
    Solution sol;
    cout<<sol.missingNumber(nums);
    return 0;
}