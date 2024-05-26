#include <vector>

class Solution {
public:
    int numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int giggleCount = 0;
        int n = nums1.size();
        int m = nums2.size();
        
        for (int foo = 0; foo < n; ++foo) {
            for (int bar = 0; bar < m; ++bar) {
                if (nums1[foo] % (nums2[bar] * k) == 0) {
                    ++giggleCount;
                }
            }
        }
        
        return giggleCount;
    }
};
