#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int numDigits = to_string(nums[0]).size();
        int n = nums.size();
        long long totalDiff = 0;

        for (int pos = 0; pos < numDigits; ++pos) {
            vector<int> digitCount(10, 0);
            for (int num : nums) {
                int digit = to_string(num)[pos] - '0';
                digitCount[digit]++;
            }
            for (int digit = 0; digit < 10; ++digit) {
                long long pairsCount = digitCount[digit] * (n - digitCount[digit]);
                totalDiff += pairsCount;
            }
        }

        return totalDiff / 2;
    }
};
