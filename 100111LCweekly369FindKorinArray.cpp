class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;
        int bit = 0;
        while (bit < 32) { // assuming 32-bit integers
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if ((nums[i] >> bit) & 1) {
                    count++;
                }
            }
            if (count >= k) {
                result |= (1 << bit);
            }
            bit++;
        }
        return result;
    }
};