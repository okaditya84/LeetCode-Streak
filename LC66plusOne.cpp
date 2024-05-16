class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(digits[n-1-i]==9){
                digits[n-1-i]=0;
            }
            else{
                digits[n-1-i]++;
                return digits;
            }

        }
        digits.insert(digits.begin(),1);
        return digits;
        
    }
};